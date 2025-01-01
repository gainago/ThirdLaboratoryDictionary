#ifndef L_R_U_CACHE_H
#define L_R_U_CACHE_H

#include "LinkedList.h"
#include "Pair.h"
#include "ReturnValue.h"
#include "Dictionary.h"

template <typename Key, typename Value>
class LRUCache{
private:

    MyNamespace::ReturnValue<Value> (*GetValue_)(Key const &);
    //Key access history, most recent at back
    LinkedList<Key> keysOfCachedElements_; 
    Dictionary<Key, MyNamespace::Pair<Value, typename LinkedList<Key>::Iterator> > dictionary_;
    unsigned int capacity_;
public:

    LRUCache(MyNamespace::ReturnValue<Value> (*GetValue)(Key const &), unsigned int capacity, int (*GetHashCode)(Key const &)) :
                                                                                    GetValue_(GetValue),
                                                                                    dictionary_(GetHashCode),
                                                                                    capacity_(capacity)
    {
        if(capacity == 0){
            throw "invalid capacity";
        }
    }
    MyNamespace::ReturnValue<Value> Get(Key const & key)
    {
        if(dictionary_.isContains(key)){ //chache hit
            MyNamespace::Pair<Value, typename LinkedList<Key>::Iterator> cachedElement = dictionary_.Get(key);

            keysOfCachedElements_.Erase(cachedElement.GetSecond()); // reload record
            keysOfCachedElements_.Append(key);

            dictionary_.Remove(key);

            typename LinkedList<Key>::Iterator newIt = keysOfCachedElements_.Back(); 

            MyNamespace::Pair<Value, typename LinkedList<Key>::Iterator> newPair(cachedElement.GetFirst(), newIt);

            dictionary_.Add(key, newPair);

            return MyNamespace::ReturnValue<Value>(1, cachedElement.GetFirst());
        }
                        //cache hit
        MyNamespace::ReturnValue<Value> getNewValue = GetValue_(key);

        if(!getNewValue.IsCorrect()){ // can not get value with this key
            return getNewValue; //do not upgrade access history
        }

        if(keysOfCachedElements_.GetLength() == capacity_){
            dictionary_.Remove(keysOfCachedElements_.GetFirst());
            keysOfCachedElements_.PopFirst();
        }

        keysOfCachedElements_.Prepend(key);
        dictionary_.Add(key,
            MyNamespace::Pair<Value, typename LinkedList<Key>::Iterator>
            (getNewValue.GetValue(), keysOfCachedElements_.Begin()));
    
        return MyNamespace::ReturnValue<Value>(1, getNewValue.GetValue());
    }
};

#endif  //L_R_U_CACHE_H
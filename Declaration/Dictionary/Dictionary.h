#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "DynamicArray.h"
#include "LinkedList.h"
#include "Pair.h"

template< typename TypeKey, typename TypeValue> class Dictionary //вся работа с памятью делегирована на array
{
private:
    int (*GetHashCode_)(TypeKey const &);
    double fillFactor_;
    double increaseFactor_;
    DynamicArray<LinkedList<MyNamespace::Pair<TypeKey const, TypeValue> > > array_; //занимает 8 байт на стеке
    int size_;

    bool isNeedRecapacity()
    {
        return !(size_ < fillFactor_*(array_.GetCapacity()));
    }

    bool isListContains(int numberList, TypeKey const & key) const
    {
        for(int i = 0; i < array_.Get(numberList).GetLength(); i++)
        {
            if(array_.Get(numberList).Get(i).GetFirst() == key)
            {
                return true;
            }
        }
        return false;
    }

    void Rebuild(int newSize)
    {
        DynamicArray<LinkedList<MyNamespace::Pair<TypeKey const, TypeValue> > > newArray(newSize);
        Iterator it = this->begin();
        for(;it != this->end(); ++it)
        {
            newArray[GetHashCode_((*it).GetFirst()) % newArray.GetCapacity()].Append(
                MyNamespace::Pair<TypeKey const, TypeValue>((*it).GetFirst(), (*it).GetSecond()));
        }

        //array_ = newArray;
        array_.swap(newArray);
    }

    

public:
    //   итератор не очищает память
    class Iterator{ 
        friend class Dictionary<TypeKey, TypeValue>;
    private:

        DynamicArray<LinkedList<MyNamespace::Pair<TypeKey const, TypeValue> > >& basedArray_;
        int arrayIndex_;
        typename LinkedList<MyNamespace::Pair< const TypeKey, TypeValue> >::Iterator listIterator_; // раз в массиве хранятся листы
                                                                                             // и не получилось найти хотя бы один элемент
                                                                                             //то значение true этого поля означает 
                                                                                             //что это уже конец словаря
        int isItEndIterator_; // это поле нужно чтобы при размере словаря итераторы работали нормально
        
    public:

        Iterator(DynamicArray<LinkedList<MyNamespace::Pair<TypeKey const, TypeValue> > > & basedArray) 
            :   basedArray_(basedArray), arrayIndex_(0), listIterator_(nullptr) {
                
                if(basedArray.GetCapacity() > 0){
                    listIterator_ = basedArray[0].begin();
                    isItEndIterator_ = 0;
                    
                }
                else {
                    isItEndIterator_ = 1;
                }
            }
        Iterator(Iterator const & other) : basedArray_(other.basedArray_), arrayIndex_(other.arrayIndex_)
                                        , listIterator_(other.listIterator_), isItEndIterator_(other.isItEndIterator_)
        {}

        Iterator& operator++()
        {
            if(isItEndIterator_){
                throw "invalid index";
            }

            if(listIterator_ != (basedArray_[arrayIndex_]).end())
            {
                ++listIterator_;

                if(listIterator_ != (basedArray_[arrayIndex_]).end()){
                    return *this;
                }
            }

            ++arrayIndex_;

            for(; arrayIndex_ < basedArray_.GetCapacity(); arrayIndex_++)
            {
                listIterator_ = (basedArray_[arrayIndex_]).begin();
                if(listIterator_ != (basedArray_[arrayIndex_]).end()){
                    return *this;
                }
            }

            isItEndIterator_ = 1;
            return *this;

        }

        MyNamespace::Pair< const TypeKey, TypeValue>& operator*()
        {
            if(isItEndIterator_){
                throw "invalid index";
            }

            return (*listIterator_);

        }

        bool operator==(Iterator const & other)
        {
            if(this->arrayIndex_ == other.arrayIndex_ && (&(this->basedArray_) == (&other.basedArray_))
                && this->isItEndIterator_ == other.isItEndIterator_ && this->listIterator_ == other.listIterator_){
                
                return true;
            }

            return false;
        }

        bool operator!=(Iterator const & other)
        {
            return !(*this == other);
        }
        
    };

    Iterator begin(){
        return Iterator(array_);
    }
    Iterator end() { 
        Iterator it(array_);
        it.listIterator_ = typename LinkedList<MyNamespace::Pair< const TypeKey, TypeValue> >::Iterator(nullptr);
        it.arrayIndex_ = array_.GetCapacity();
        it.isItEndIterator_ = 1;
        return it;
    }

    Dictionary(int (*GetHashCode)(TypeKey const &), double fillFactor = 0.7, double increaseFactor = 2, int capacity = 0) : GetHashCode_(GetHashCode)
        , fillFactor_(fillFactor), increaseFactor_(increaseFactor), array_(capacity), size_(0) {}

    void Add(TypeKey const key, TypeValue value)
    {
        if(array_.GetCapacity() == 0){
            array_.ReCapacity(1);
        }

        if(isContains(key)){
            throw "the element with same key have already existed";
        }

        array_[GetHashCode_(key) % array_.GetCapacity()].Append(MyNamespace::Pair<TypeKey const, TypeValue>(key, value));
        ++size_;

        if(isNeedRecapacity()){
            if((double)array_.GetCapacity() > (double)__INT_MAX__/increaseFactor_){
                throw " can not increase dictionary";
            }
            Rebuild(array_.GetCapacity() * increaseFactor_);
        }
    }

    bool isContains(TypeKey const & key) const
    {
        return isListContains(GetHashCode_(key) % array_.GetCapacity(), key);
    }

    

};


#endif //DICTIONARY_H
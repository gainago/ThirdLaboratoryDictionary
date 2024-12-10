#include <cassert>
#include <cstdlib>
#include "Dictionary.h"
#include "MyString.h"
#include "GetHashCode.h"
#include "time.h"
#include "PrintDictionary.h"

void ConstructionTests()
{
    { Dictionary<int, int> d(&GetHashCodeInt, 0.1, 444, 40);}
    try{
        Dictionary<int, int> d(&GetHashCodeInt, -1, 444, 40);
        assert(0);
    }
    catch(char const*){}

    try{
        Dictionary<int, int> d(&GetHashCodeInt, 12, 0.5, 40);
        assert(0);
    }
    catch(char const*){}

    try{
        Dictionary<int, int> d(&GetHashCodeInt, 12, 2, -1);
        assert(0);
    }
    catch(char const*){}

    try{
        Dictionary<int, int> d(nullptr, 12, 2, 0);
        assert(0);
    }
    catch(char const*){}
    
}

void AddTestsMyString()
{
    MyString arrayString[5] = {"Ivan", "Ivanovich /n", "  &^^Ivanov", "880.055#535`35", ""};
    Dictionary<MyString, int> dictionaryMyString(&GetHashCodeMyString, 0.12, 2, 0);
    for(int i = 0; i < 5; i++){
        dictionaryMyString.Add(arrayString[i], i);
    }

    for(int i = 0; i < 5; i++){
        assert(dictionaryMyString.isContains(arrayString[i]));
    }

}

void AddTestsInt()
{
    Dictionary<int, int> dictionaryInt(&GetHashCodeInt, 0.12, 2, 0);
    dictionaryInt.Add(555, 666);
    try{
        dictionaryInt.Add(555, 999);
        assert(0);
    }
    catch(char const*){}

    srand(time(NULL));
    for(int i = 0; i < 100; i++){   // добавляем 100 элементов
        int tmpValue = rand();
        if(dictionaryInt.isContains(tmpValue)){
            i--;
            continue;
        }

        dictionaryInt.Add(tmpValue, tmpValue);
    }

    for(auto it = dictionaryInt.begin(); it!= dictionaryInt.end(); ++it){ //пытаемся вставить елементы 
                                                                    //с уже существующии ключами
        try{
            dictionaryInt.Add((*it).GetFirst(), rand());
            assert(0);
        }
        catch(const char*){}
    }
    
}

void RemoveTestsInt()
{
    int arr[5] = {13, 69, 77, -1, 0};
    Dictionary<int, int> dictionary(&GetHashCodeInt, 0.12, 2, 0);
    for(int i = 0; i < 5; i++){
        dictionary.Add(arr[i], i);
    }

    for(int i = 0; i < 100; i++){ // таких элементов мы не добавляли
        try{
            dictionary.Remove(rand() + 80);
            assert(0);
        }
        catch(const char*) {}
    }

    for(int i = 0; i < 5; i++)
    {
        dictionary.Remove(arr[i]);
    }
    
}

void RemoveTestsMyString()
{
    MyString arrayString[5] = {"Ivan", "Ivanovich /n", "  &^^Ivanov", "880.055#535`35", ""};
    Dictionary<MyString, int> dictionaryMyString(&GetHashCodeMyString, 0.12, 2, 0);
    for(int i = 0; i < 5; i++){
        dictionaryMyString.Add(arrayString[i], i);
    }

    for(int i = 0; i < 127; i++){ 
        if((char)i == '\0'){ // нулевой префикс
            continue;
        }                                         // таких элементов там нет
        try{
            dictionaryMyString.Remove(MyString(i) + arrayString[i % 5]);
            assert(0);
        }
        catch(const char*) {}
    }

   //PrintDictionary(dictionaryMyString);

    for(int i = 0; i < 5; i++)
    {
        dictionaryMyString.Remove(arrayString[i]);
    }

    for(int i = 0; i < 127; i++){       //элементов там нет
        try{
            dictionaryMyString.Remove(MyString(i));
            assert(0);
        }
        catch(const char*) {}
    }
}

void GetTestsInt()
{
    int arr[5] = {13, 69, 77, -1, 0};
    Dictionary<int, int> dictionary(&GetHashCodeInt, 0.12, 2, 0);
    for(int i = 0; i < 5; i++){
        dictionary.Add(arr[i], i);
    }

    for(int i = 0; i < 5; i++){
        dictionary.Get(arr[i])+=1;
    }

    for(int i = 0; i < 5; i++){
        
        assert(dictionary.Get(arr[i]) == i + 1);
    }

    for(int i = 0; i < 5; i++){
        try{
            dictionary.Get(arr[i] + 20); // элементов с такими индексами нет
            assert(0);
        }
        catch(const char*) {}
    }
    
}

void IteratorTestsInt()
{
    int arr[5] = {13, 69, 77, -1, 0};
    Dictionary<int, int> dictionary(&GetHashCodeInt, 0.12, 2, 0);

    for(int i = 0; i < 5; i++){
        dictionary.Add(arr[i], i);
    }

    for(auto it = dictionary.begin(); it != dictionary.end(); ++it){ // проверяем заполнились ли все значения 
        if((*it).GetSecond() != 13 || (*it).GetSecond() != 69 || (*it).GetSecond() != 77 
            || (*it).GetSecond() != -1 || (*it).GetSecond() != 0){

            }
        else{
            assert(0);
        }
    }

    for(auto it = dictionary.begin(); it != dictionary.end(); ++it){
        
        (*it).SetSecond(-800);
    }

    for(int i = 0; i < 5; i++){
        assert(dictionary.Get(arr[i]) == -800);
    }
   
}

void IteratorTestsMyString()
{
    MyString arrayString[5] = {"Ivan", "Ivanovich /n", "  &^^Ivanov", "880.055#535`35", ""};
    Dictionary<MyString, int> dictionaryMyString(&GetHashCodeMyString, 0.12, 2, 0);
    for(int i = 0; i < 5; i++){
        dictionaryMyString.Add(arrayString[i], i);
    }
    assert(dictionaryMyString.begin() != dictionaryMyString.end());

    for(auto it = dictionaryMyString.begin(); it != dictionaryMyString.end(); ++it){
        
        (*it).SetSecond(337);
    }

    for(int i = 0; i < 5; i++){
        assert(dictionaryMyString.Get(arrayString[i]) == 337);
    }
    
}
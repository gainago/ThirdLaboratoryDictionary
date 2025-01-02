#include <fstream>
#include "MyString.h"
#include "DynamicArray.h"
#include "Person.h" //to MLENGTH

DynamicArray<MyString>* GetNamesToMyString()
{
    DynamicArray<MyString>* arrMyString = new DynamicArray<MyString>(737);

    std::ifstream ifs;
    ifs.open("../male_names_rus.txt", std::ios::in);
    if(!ifs.is_open())
    {
        throw "can not open male_names_rus.txt";
    }

    char buffer[Person::GetMaxLength()];
    for(int i = 0; i <= 735; i++)
    {
        ifs >> buffer;
        MyString tmpStr(buffer);
        arrMyString->operator[](i) = tmpStr;
    }

    return arrMyString;
}
DynamicArray<MyString>* GetSurnamesToMyString()
{
    DynamicArray<MyString>* arrMyString = new DynamicArray<MyString>(14653);

    std::ifstream ifs;
    ifs.open("../male_surnames_rus.txt", std::ios::in);
    if(!ifs.is_open())
    {
        throw "can not open male_surnames_rus.txt";
    }

    char buffer[Person::GetMaxLength()];
    for(int i = 0; i <= 14651; i++)
    {
        ifs >> buffer;
        MyString tmpStr(buffer);
        arrMyString->operator[](i) = tmpStr;
    }

    return arrMyString;
}
//DynamicArray<MyString>* GetSurnamesToMyString();

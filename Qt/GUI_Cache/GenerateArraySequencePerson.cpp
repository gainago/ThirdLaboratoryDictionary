#include <fstream>
#include <cmath>
#include <time.h>
#include "Sequence.h"
#include "Person.h"
#include "ArraySequence.h"

// Greater C++14

Sequence<Person*>* GenerateArraySequencePerson(int const count, DynamicArray<MyString>* Names, DynamicArray<MyString>* Surnames)
{
    Sequence<Person*> *seq;
    srand(time(NULL));
    
        seq = new MutableArraySequence<Person*>(count);
    
    for(int i = 0; i < count; i++)
    {
        int indexName = rand() % Names->GetCapacity(); //если удалить это строки будет отвратичельно
                                        //волшебные значения 
                                        //НУЖНО брать эти значения из DynmicArray с именами и фамилиями
        int indexSurname = rand() % Surnames->GetCapacity();
        MyString name = Names->Get(indexName);
        MyString lastName = Surnames->Get(indexSurname);
        MyString middleName = Names->Get(abs(indexSurname - indexName ) % Names->GetCapacity()) + MyString("ов");

        auto SFL{ [](MyString inputStr)->MyString //makeMyStringFixLength 
        {
            MyString addedStr(Person::GetMaxLength() - inputStr.GetLength()); //MLENGTH in Person.h
            MyString outputStr = inputStr + addedStr;
            return outputStr;

        }};

        MyString tmpId = SFL(MyString::IntToMyString(i));
        MyString tmpName = SFL(name);
        MyString tmpMiddleName = SFL(middleName);
        MyString tmpLastName = SFL(lastName);
        Person *tmpPerson;

        int birthYear = rand() % 220 + 1800;
        tmpPerson = new Person(tmpId, tmpName, tmpMiddleName, tmpLastName, birthYear);  //код с хорошо подобранными именами практически
                                                                                            //не нужно комментировать
        //Person tmpPerson(SFL(MyString::IntToMyString(i)), SFL(name), SFL(middleName), SFL(lastName), i);
        seq->Set(i, tmpPerson);
    }
    
    return seq;

}

void DeleteGenerateArraySequencePerson(Sequence<Person*>* seq)
{
    if(seq == nullptr){
        return;
    }
    for(int i = 0; i < seq->GetLength(); i++)
    {
        delete seq->Get(i);
    }

    delete seq;

    
}

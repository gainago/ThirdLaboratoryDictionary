#ifndef PRINT_DICTIONARY_H
#define PRINT_DICTIONARY_H

#include "Dictionary.h"
#include <iostream>

template< typename TypeKey, typename TypeValue>
void PrintDictionary(Dictionary<TypeKey, TypeValue> & dictionary)
{
    for(auto it = dictionary.begin(); it != dictionary.end(); ++it)
    {
        std::cout << (*it).GetSecond() << "\t";
    }
    std::cout << std::endl;
}

#endif //PRINT_DICTIONARY_H

#ifndef PRINT_SEQ_H
#define PRINT_SEQ_H

#include <iostream>
#include "Sequence.h"

template < typename Type> void PrintSeq(Sequence<Type> const * seq)
{
    for(int i = 0; i < seq->GetLength(); i++)
    {
        std::cout << seq->Get(i) << " \t";
    }
    std::cout << std::endl;
}
#endif
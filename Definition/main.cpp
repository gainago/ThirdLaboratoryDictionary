#include "PrintArray.h"
#include "LinkedList.h"
#include "DynamicArray.h"
#include "Dictionary.h"
#include "GetHashCode.h"
#include "PrintDictionary.h"
#include "SetRandomInt.h"
#include "UnitTests.h"

int main(int argc, char** argv)
{

    int arr[4] = {0, -1, 100, 234}; 

    ConstructionTests();

    AddTestsMyString();

    AddTestsInt();

    RemoveTestsInt();

    RemoveTestsMyString();

    GetTestsInt();

    IteratorTestsInt();

    IteratorTestsMyString();


    return 0;
}
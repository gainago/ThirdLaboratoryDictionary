#include <QApplication>

#include "PrintArray.h"
#include "LinkedList.h"
#include "DynamicArray.h"
#include "Dictionary.h"
#include "GetHashCode.h"
#include "PrintDictionary.h"
#include "SetRandomInt.h"
#include "UnitTests.h"
#include "LoadTestsInt.h"

int main(int argc, char** argv)
{

    

    /*ConstructionTests();

    AddTestsMyString();

    AddTestsInt();

    RemoveTestsInt();

    RemoveTestsMyString();

    GetTestsInt();

    IteratorTestsInt();

    IteratorTestsMyString();*/

    QApplication app(argc, argv);
    LoadTestsInt();
    return app.exec();

}
#include "PrintArray.h"
#include "LinkedList.h"
#include "DynamicArray.h"
#include "Dictionary.h"
#include "GetHashCodeInt.h"
#include "PrintDictionary.h"
struct Point{
    int x;
    int y;
};
int main(int argc, char** argv)
{

    int arr[4] = {0, -1, 100, 234}; 
    // LinkedList<int> list(arr, 5);

    // LinkedList<int>::Iterator it = list.begin();

    // for(it; it!= list.end(); ++it)
    // {
    //     std::cout << *it << "\t";
    // }
    // DynamicArray<int> dArray(arr, 5);
    // for(int i = 0; i < dArray.GetCapacity(); i++){
    //     std::cout << dArray[i] << "\t";
    // }
    Dictionary<int, int> d(&GetHashCodeInt);
    for(int i = 0; i < 4; i++){
        d.Add(arr[i], arr[i]);

        PrintDictionary(d);
    }
    //Point arrPoints[5] = {{1, 1}, {4, 4}, {-1, 100}};
    //MyNamespace::Pair<const int, int> pair1;


    return 0;
}
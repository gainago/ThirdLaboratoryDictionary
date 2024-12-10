#include <time.h>
#include <cstdlib>
#include "DynamicArray.h"
#include "Dictionary.h"

void SetRandomInt(int const size, Dictionary<int, int>& dictionary)
{
    srand(time(NULL));
    for(int i = 0; i < size; i++){
        int tmpValue = rand();
        if(dictionary.isContains(tmpValue)){
            i--;
            continue;
        }

        dictionary.Add(tmpValue, tmpValue);
    }
}

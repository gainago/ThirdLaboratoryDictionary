#include <QString>
#include "uiclass.h"

bool isNormalQString(QString str){

    if(str.isEmpty()){
        return false;
    }
    int countSpace = 0;
    int sizeKey = 0;
    for(int i = 0; i < str.size(); i++){

        if(str.at(i) == ' ' ){
            if(countSpace == 0){
                sizeKey = i;
            }
            countSpace++;
            if(countSpace > 1){

                return false;
            }

        }
    }

    if(sizeKey == 0){
        return false;
    }

    if(countSpace == 0){
        return false;
    }

    if(str.size() - sizeKey - 1 == 0){
        return false;
    }

    if(sizeKey > UIClass::GetMaxLengthQString() ||
        (UIClass::GetMaxLengthQString() < (str.size() - sizeKey - 1))){

        return false;;
    }
    return true;
}

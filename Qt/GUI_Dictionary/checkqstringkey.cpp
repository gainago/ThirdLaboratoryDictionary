#include <QString>

bool isNormalQStringKey(QString strKey)
{
    if(strKey.size() > 10){
        return false;
    }

    int countSpace = 0;
    for(int i = 0; i < strKey.size(); i++){
        if(strKey.at(i) == ' '){
            countSpace++;
        }
    }

    if(countSpace > 0){
        return false;
    }

    return true;
}

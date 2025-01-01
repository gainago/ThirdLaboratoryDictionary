#include <QString>

int GetHashQString(QString const & string)
{
    int hash = 0;
    for(int i = 0 ; i < string.size(); i++){
        hash+= (int)(string.at(i).unicode());
        hash%=(int)(1e9+7);
    }
    return hash;
}

#include "Abs.h"
#include "MyString.h"

int GetHashCodeInt(int const & value)
{
    return MyNamespace::Abs(value);
}

int GetHashCodeMyString(MyString const & string)
{
    int hash = 0;

    for(int i = 0; i < string.GetLength(); i++)
    {
        hash+=(int)(string.GetCharPointer()[i]);
        hash = hash % (int)(1e9 + 7);
    }

    return hash;
}

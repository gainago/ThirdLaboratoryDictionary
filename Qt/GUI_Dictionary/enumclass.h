#ifndef ENUMCLASS_H
#define ENUMCLASS_H

#include <QString>

class EnumClass
{
    enum class Operations {Add, Get, Remove};
    Operations operation_;
public:
    EnumClass(int);
    QString GetQStringRepresentation();
    int GetIntRepresentation();
};

#endif // ENUMCLASS_H

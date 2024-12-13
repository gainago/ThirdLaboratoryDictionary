#include "enumclass.h"

EnumClass::EnumClass(int operation) : operation_((Operations)operation)
{}

QString EnumClass::GetQStringRepresentation()
{
    switch((int)operation_)
    {
        case 0:
        {
            return QString("Add");
            break;
        }
        case 1:
        {
            return QString("Get");
            break;
        }
        case 2:
        {
            return QString("Remove");
            break;
        }
        default:
        {
            throw "invalid class member";
        }
    }
}

int EnumClass::GetIntRepresentation()
{
    return (int)operation_;
}

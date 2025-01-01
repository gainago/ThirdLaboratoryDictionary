#include "memberofmodel.h"

memberOfModel::memberOfModel(EnumClass operation, double time,
    int size) :
    operation_(operation), time_(time), size_(size)
{}
memberOfModel::memberOfModel() : operation_(-1)
{
    time_ = 0;
    size_ = 0;
}
EnumClass memberOfModel::getOperation() const
{
    return operation_;
}

double memberOfModel::getTime() const
{
    return time_;
}

int memberOfModel::getSize() const
{
    return size_;
}



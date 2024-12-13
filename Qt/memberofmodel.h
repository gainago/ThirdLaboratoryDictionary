#ifndef MEMBEROFMODEL_H
#define MEMBEROFMODEL_H

#include "enumclass.h"
#include "QString"

class memberOfModel
{
private:
    EnumClass operation_;
    double time_;
    int size_;
public:
    memberOfModel(EnumClass operation, double time,
                  int size);
    memberOfModel();

    EnumClass getOperation() const;
    double getTime() const;
    int getSize() const;
};

#endif // MEMBEROFMODEL_H

#ifndef ORMPROPERTYINTERFACE_H
#define ORMPROPERTYINTERFACE_H

#include "ormdefinitions.h"

class ORMPropertyInterface
{
public:
    ORMPropertyInterface();

    virtual ORMString asString() const = 0;
    virtual void fromString(const ORMString &value) = 0;
};

#endif // ORMPROPERTYINTERFACE_H

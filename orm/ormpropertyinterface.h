#ifndef ORMPROPERTYINTERFACE_H
#define ORMPROPERTYINTERFACE_H

#include "ormdefinitions.h"

class ORMPropertyInterface
{
    bool bNull;
public:
    ORMPropertyInterface();

    virtual ORMString asString() const = 0;
    virtual void fromString(const ORMString &value) = 0;

    void setNull(const bool n);
    bool isNull() const;
};

#endif // ORMPROPERTYINTERFACE_H

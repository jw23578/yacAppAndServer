#ifndef ORMPROPERTYOID_H
#define ORMPROPERTYOID_H

#include "ormtemplatedpropertyinterface.h"

class ORMPropertyOID : public ORMTemplatedPropertyInterface<size_t>
{
public:
    ORMPropertyOID();

    ORMString asString() const override;
    void fromString(const ORMString &value) override;

    ORMPropertyOID &operator=(const size_t value)
    {
        set(value);
        return *this;
    }
};

#endif // ORMPROPERTYOID_H

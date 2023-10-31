#ifndef ORMPROPERTYUUID_H
#define ORMPROPERTYUUID_H

#include "ormtemplatedpropertyinterface.h"

class ORMPropertyUuid : public ORMTemplatedPropertyInterface<ORMUuid>
{
public:
    ORMPropertyUuid();

    ORMString asString() const override;
    void fromString(const ORMString &value) override;

    ORMPropertyUuid &operator=(const ORMUuid value)
    {
        set(value);
        return *this;
    }        
};

#endif // ORMPROPERTYUUID_H

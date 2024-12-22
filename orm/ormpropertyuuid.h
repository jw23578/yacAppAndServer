#ifndef ORMPROPERTYUUID_H
#define ORMPROPERTYUUID_H

#include "ormtemplatedpropertyinterface.h"

class ORMPropertyUuid : public ORMTemplatedPropertyInterface<ORMUuid>
{
public:
    ORMPropertyUuid();

    ORMString asString() const override;
    void fromString(const ORMString &value) override;
    ORMString asJson() const override;

    void generate();
    void clear();

    ORMPropertyUuid &operator=(const ORMUuid value)
    {
        set(value);
        return *this;
    }
};

bool operator!=(ORMPropertyUuid const &a, ORMUuid const &b);

#endif // ORMPROPERTYUUID_H

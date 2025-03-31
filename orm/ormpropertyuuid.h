#ifndef ORMPROPERTYUUID_H
#define ORMPROPERTYUUID_H

#include "ormtemplatedpropertyinterface.h"

class ORMPropertyUuid : public ORMTemplatedPropertyInterface<ORMUuid>
{
public:
    ORMPropertyUuid(ORMString const &name);

    ORMString asString() const override;
    void fromString(const ORMString &value) override;
    ORMString asJson() const override;

    void generate();
    void clear();

    ORMPropertyUuid &operator=(const ORMPropertyUuid &other)
    {
        set(other.get());
        return *this;
    }

    ORMPropertyUuid &operator=(const ORMUuid &other)
    {
        set(other);
        return *this;
    }
};

bool operator!=(ORMPropertyUuid const &a, ORMUuid const &b);

#endif // ORMPROPERTYUUID_H

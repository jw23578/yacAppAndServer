#ifndef ORMPROPERTYSIZET_H
#define ORMPROPERTYSIZET_H

#include "ormtemplatedpropertyinterface.h"

class ORMPropertySizeT : public ORMTemplatedPropertyInterface<size_t>
{
public:
    ORMPropertySizeT();

public:
    ORMString asString() const override;
    void fromString(const ORMString &value) override;

    ORMPropertySizeT &operator=(const size_t value)
    {
        set(value);
    }

};

#endif // ORMPROPERTYSIZET_H

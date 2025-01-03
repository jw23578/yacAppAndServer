#ifndef ORMPROPERTYSIZET_H
#define ORMPROPERTYSIZET_H

#include "ormtemplatedpropertyinterface.h"

class ORMPropertySizeT : public ORMTemplatedPropertyInterface<size_t>
{
public:
    ORMPropertySizeT(ORMString const &name);

public:
    ORMString asString() const override;
    void fromString(const ORMString &value) override;
    ORMString asJson() const override;

    ORMPropertySizeT &operator=(const size_t value)
    {
        set(value);
        return *this;
    }

};

#endif // ORMPROPERTYSIZET_H

#ifndef ORMPROPERTYBOOL_H
#define ORMPROPERTYBOOL_H

#include "ormtemplatedpropertyinterface.h"

class ORMPropertyBool : public ORMTemplatedPropertyInterface<bool>
{
public:
    ORMPropertyBool();

    ORMString asString() const override;
    void fromString(const ORMString &value) override;

    ORMPropertyBool &operator=(const bool value)
    {
        set(value);
    }
};

#endif // ORMPROPERTYBOOL_H

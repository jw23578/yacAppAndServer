#ifndef ORMPROPERTYBOOL_H
#define ORMPROPERTYBOOL_H

#include "ormtemplatedpropertyinterface.h"

class ORMPropertyBool : public ORMTemplatedPropertyInterface<bool>
{
public:
    ORMPropertyBool();

    ORMString asString() const override;
    void fromString(const ORMString &value) override;
};

#endif // ORMPROPERTYBOOL_H

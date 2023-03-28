#ifndef ORMPROPERTYSTRING_H
#define ORMPROPERTYSTRING_H

#include "ormtemplatedpropertyinterface.h"

class ORMPropertyString: public ORMTemplatedPropertyInterface<ORMString>
{
public:
    ORMPropertyString();

    ORMString asString() const override;
    void fromString(const ORMString &value) override;
};

#endif // ORMPROPERTYSTRING_H

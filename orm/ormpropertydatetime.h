#ifndef ORMPROPERTYDATETIME_H
#define ORMPROPERTYDATETIME_H

#include "ormtemplatedpropertyinterface.h"

class ORMPropertyDateTime : public ORMTemplatedPropertyInterface<ORMDateTime, ORMPropertyDateTime>
{
public:
    ORMPropertyDateTime();

    ORMString asString() const;
    void fromString(const ORMString &value);
};

#endif // ORMPROPERTYDATETIME_H

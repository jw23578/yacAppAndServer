#include "ormpropertystring.h"

ORMPropertyString::ORMPropertyString():ORMTemplatedPropertyInterface<ORMString>()
{

}

ORMString ORMPropertyString::asString() const
{
    return get();
}

void ORMPropertyString::fromString(const ORMString &value)
{
    set(value);
}

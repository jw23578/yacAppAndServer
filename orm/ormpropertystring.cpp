#include "ormpropertystring.h"
#include "utils/extstring.h"

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

ORMString ORMPropertyString::asJson() const
{
    return ExtString::quote(asString());
}

bool operator==(const ORMPropertyString &a, const ORMString &b)
{
    return a.get() == b;
}

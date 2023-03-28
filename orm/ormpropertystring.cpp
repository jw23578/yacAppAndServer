#include "ormpropertystring.h"

ORMPropertyString::ORMPropertyString()
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

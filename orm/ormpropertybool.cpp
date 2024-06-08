#include "ormpropertybool.h"

ORMPropertyBool::ORMPropertyBool():ORMTemplatedPropertyInterface<bool>()
{
    set(false);
}

ORMString ORMPropertyBool::asString() const
{
    return get() ? "true" : "false";
}

void ORMPropertyBool::fromString(const ORMString &value)
{
    set(value == "true");
}

ORMString ORMPropertyBool::asJson() const
{
    return asString();
}


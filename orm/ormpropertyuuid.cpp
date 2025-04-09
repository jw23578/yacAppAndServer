#include "ormpropertyuuid.h"
#include "extstring.h"
#include "extuuid.h"

ORMPropertyUuid::ORMPropertyUuid(ORMString const &name):ORMTemplatedPropertyInterface<ORMUuid>(name)
{
    set(ExtUuid::NullUuid);
    setNull(true);
}

ORMString ORMPropertyUuid::asString() const
{
    return ExtUuid::uuidToString(get());
}

void ORMPropertyUuid::fromString(const ORMString &value)
{
    set(ExtUuid::stringToUuid(value));
    if (value == "")
    {
        setNull(true);
    }
}

ORMString ORMPropertyUuid::asJson() const
{
    if (isNull())
    {
        return "null";
    }
    return MACRO_STD_STRING_2_ORM_STRING(ExtString::quote(MACRO_ORM_STRING_2_STD_STRING(asString())));
}

void ORMPropertyUuid::generate()
{
    set(ExtUuid::generateUuid());
}

void ORMPropertyUuid::clear()
{
    set(ExtUuid::NullUuid);
}

bool operator!=(ORMPropertyUuid const &a, ORMUuid const &b)
{
    return a.getRef() != b;
}

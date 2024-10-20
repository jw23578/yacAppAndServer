#include "ormpropertyuuid.h"
#include "utils/extstring.h"
#include "utils/extuuid.h"

ORMPropertyUuid::ORMPropertyUuid():ORMTemplatedPropertyInterface<ORMUuid>()
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
}

ORMString ORMPropertyUuid::asJson() const
{
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

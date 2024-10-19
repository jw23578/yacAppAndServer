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
    return ExtString::quote(asString());
}

void ORMPropertyUuid::generate()
{
    set(ExtUuid::generateUuid());
}

void ORMPropertyUuid::clear()
{
    set(ExtUuid::NullUuid);
}

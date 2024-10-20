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
#ifdef ORMCPPTypes
    return ExtString::quote(asString());
#endif
#ifdef ORMQTTypes
    return ExtString::quote(asString().toStdString()).c_str();
#endif
}

void ORMPropertyUuid::generate()
{
    set(ExtUuid::generateUuid());
}

void ORMPropertyUuid::clear()
{
    set(ExtUuid::NullUuid);
}

#include "ormpropertydatetime.h"
#include "utils/extstring.h"

ORMPropertyDateTime::ORMPropertyDateTime():ORMTemplatedPropertyInterface<ORMDateTime>()
{

}

ORMString ORMPropertyDateTime::asString() const
{
#ifdef ORMCPPTypes
    return ExtString::timepointToISO(get());
#endif
#ifdef ORMQTTypes
    return get().toTimeSpec(Qt::LocalTime).toString(Qt::ISODate);
#endif
}

void ORMPropertyDateTime::fromString(const ORMString &value)
{
#ifdef ORMCPPTypes
    set(ExtString::toTimepoint(value));
#endif
#ifdef ORMQTTypes
    set(QDateTime::fromString(value, Qt::DateFormat::ISODateWithMs));
#endif
}

ORMString ORMPropertyDateTime::asJson() const
{
    return MACRO_STD_STRING_2_ORM_STRING(ExtString::quote(MACRO_ORM_STRING_2_STD_STRING(asString())));
}

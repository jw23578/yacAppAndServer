#include "ormpropertydatetime.h"
#include "utils/extstring.h"

ORMPropertyDateTime::ORMPropertyDateTime(const ORMString &name):ORMTemplatedPropertyInterface<ORMDateTime>(name)
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
    if (value == "")
    {
        setNull(true);
    }
}

ORMString ORMPropertyDateTime::asJson() const
{
    if (isNull())
    {
        return "null";
    }
    return MACRO_STD_STRING_2_ORM_STRING(ExtString::quote(MACRO_ORM_STRING_2_STD_STRING(asString())));
}

bool operator!=(ORMPropertyDateTime const &a, ORMDateTime const &b)
{
    return a.getRef() != b;
}

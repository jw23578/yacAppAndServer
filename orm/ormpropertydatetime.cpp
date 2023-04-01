#include "ormpropertydatetime.h"

#ifdef ORMCPPTypes
#include "utils/extstring.h"
#endif

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

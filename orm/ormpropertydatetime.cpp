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
#ifdef ORMCPPTypes
    return ExtString::quote(asString());
#endif
#ifdef ORMQTTypes
    return ExtString::quote(asString().toStdString()).c_str();
#endif
}

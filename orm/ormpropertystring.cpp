#include "ormpropertystring.h"
#include "utils/extstring.h"

ORMPropertyString::ORMPropertyString():ORMTemplatedPropertyInterface<ORMString>()
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

ORMString ORMPropertyString::asJson() const
{
#ifdef ORMCPPTypes
    return ExtString::quote(asString());
#endif
#ifdef ORMQTTypes
    return ExtString::quote(asString().toStdString()).c_str();
#endif

}

size_t ORMPropertyString::size() const
{
    return getRef().size();
}

bool operator==(const ORMPropertyString &a, const ORMString &b)
{
    return a.getRef() == b;
}

#include "t0015_user_devicetoken.h"

size_t t0015_user_devicetoken::fetchDeviceToken(CurrentContext &context,
                                                const ORMUuid &userId,
                                                std::set<ORMString> &deviceTokenSet)
{
    SqlString sql;
    sql.select(getORMName());
    sql.addCompare("where", user_idORM().name(), "=", ExtUuid::uuidToString(userId));
    context.opi.addOnlyInsertDBWhere(false, sql);
    context.opi.fetchValues(sql, device_tokenORM().name(), deviceTokenSet);
    return deviceTokenSet.size();
}


#include "t0015_user_devicetoken.h"

size_t t0015_user_devicetoken::fetchDeviceToken(CurrentContext &context,
                                                const reducedsole::uuid &userId,
                                                std::set<ORMString> &deviceTokenSet)
{
    SqlString sql;
    sql.select(getORMName());
    sql.addCompare("where", user_id.name(), "=", userId.str());
    context.opi.addOnlyInsertDBWhere(false, sql);
    context.opi.fetchValues(sql, device_token.name(), deviceTokenSet);
    return deviceTokenSet.size();
}


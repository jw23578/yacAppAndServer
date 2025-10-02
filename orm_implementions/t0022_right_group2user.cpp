#include "t0022_right_group2user.h"
#include "t0023_right2rightgroup.h"

bool t0022_right_group2user::removeUser(CurrentContext &context,
                                           const reducedsole::uuid &rightGroupId,
                                           const reducedsole::uuid &userId,
                                           std::string &message)
{
    if (!userInRightGroup(context, rightGroupId, userId))
    {
        message = "user is not in rightgroup";
        return false;
    }
    erase(context);
    return true;
}

bool t0022_right_group2user::userInRightGroup(CurrentContext &context,
                                              const reducedsole::uuid &rightGroupId,
                                              const reducedsole::uuid &userId)
{
    return load(context,
              {{right_group_id.name(), ExtUuid::uuidToString(rightGroupId)},
               {user_id.name(), ExtUuid::uuidToString(userId)}});
}


void t0022_right_group2user::fetchUserRightNumbers(CurrentContext &context,
                                                      const reducedsole::uuid &userId,
                                                      std::set<int> &rightNumbersSet)
{
    SqlString sql;
    sql.select(t0023_right2rightgroup().getORMName());
    sql += std::string(" where ") + right_group_id.name();
    sql += std::string(" in (select ") + right_group_id.name();
    sql += std::string(" from ") + getORMName();
    sql.addCompare("where", user_id.name(), "=", ExtUuid::uuidToString(userId));
    context.opi.addOnlyInsertDBWhere(false, sql);
    sql += std::string(")");
    context.opi.addOnlyInsertDBWhere(true, sql);
    context.opi.fetchValues(sql, t0023_right2rightgroup().right_number.name(), rightNumbersSet);
}

#include "t0021_right_group.h"
#include "ormpersistenceinterface.h"
#include "t0022_right_group2user.h"
#include "t0023_right2rightgroup.h"

std::map<reducedsole::uuid, reducedsole::uuid> t0021_right_group::appId2AdminGroupId;

reducedsole::uuid t0021_right_group::checkAndGenerateAdminGroup(CurrentContext &context)
{
    const auto it(appId2AdminGroupId.find(context.appId));
    if (it != appId2AdminGroupId.end())
    {
        return it->second;
    }
    t0021_right_group adminGroup;
    if (context.opi.selectObject({{adminGroup.name.name(), Rights::Administrator}, {adminGroup.app_id.name(), context.appId.str()}}, adminGroup))
    {
        appId2AdminGroupId[context.appId] = adminGroup.right_group_id;
        return adminGroup.right_group_id;
    }

    adminGroup.name = Rights::Administrator;
    adminGroup.app_id = context.appId;
    adminGroup.prepareFirstInsert();
    context.opi.insertObject(adminGroup, context.userId);

    std::string message;
    std::set<int> current_right_numbers;
    adminGroup.fetchRightNumbers(context.opi, current_right_numbers);
    for (const auto &rn: Rights::allRightNumbers)
    {
        if (current_right_numbers.find(rn) == current_right_numbers.end())
        {
            t0023_right2rightgroup right2rightgroup;
            right2rightgroup.right_group_id = adminGroup.right_group_id;
            right2rightgroup.right_number = rn;
            right2rightgroup.store(context);
        }
    }
    return adminGroup.right_group_id;
}

void t0021_right_group::fetchRightNumbers(ORMPersistenceInterface &opi, std::set<int> &rightNumbers)
{
    SqlString sql;
    sql.select(t0023_right2rightgroup().getORMName());
    sql.addCompare("where", t0023_right2rightgroup().right_group_id.name(), "=", right_group_id);
    opi.addOnlyInsertDBWhere(false, sql);
    opi.fetchValues(sql, t0023_right2rightgroup().right_number.name(), rightNumbers);
}

size_t t0021_right_group::fetchMember(CurrentContext &context,
                                    std::set<ORMUuid> &member)
{
    SqlString sql;
    sql.select(t0022_right_group2user().getORMName());
    sql.addCompare("where", right_group_id.name(), "=", right_group_id);
    context.opi.fetchValues(sql, t0022_right_group2user().right_group_id.name(), member);
    return member.size();
}


#ifndef T0022_RIGHT_GROUP2USER_H
#define T0022_RIGHT_GROUP2USER_H

#include "appbaseobject.h"

class t0022_right_group2user : public AppBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif
    MACRO_UUID_PROPERTY(right_group2appuser);
    MACRO_UUID_PROPERTY(right_group_id);
    MACRO_UUID_PROPERTY(user_id);
    MACRO_DATETIME_PROPERTY(requested_datetime);
    MACRO_DATETIME_PROPERTY(approved_datetime);
    MACRO_UUID_PROPERTY(approved_appuser_id);
    MACRO_DATETIME_PROPERTY(denied_datetime);
    MACRO_UUID_PROPERTY(denied_appuser_id);
    MACRO_DATETIME_PROPERTY(result_seen);

public:
    MACRO_CREATE_AND_GETORMNAME(t0022_right_group2user)
    t0022_right_group2user():AppBaseObject(Rights::RN_changeRightsGroups)
    {
        MACRO_ADD_PROPERTY_ADD_DETAIL(right_group2appuser, DetailID);
        MACRO_ADD_INDEX_PROPERTY(right_group_id);
        MACRO_ADD_INDEX_PROPERTY(user_id);
        MACRO_ADD_PROPERTY(requested_datetime);
        MACRO_ADD_PROPERTY(approved_datetime);
        MACRO_ADD_PROPERTY(approved_appuser_id);
        MACRO_ADD_PROPERTY(denied_datetime);
        MACRO_ADD_PROPERTY(denied_appuser_id);
        MACRO_ADD_PROPERTY(result_seen);
    }
    bool removeUser(CurrentContext &context,
                    const reducedsole::uuid &rightGroupId,
                    const reducedsole::uuid &userId, std::string &message);
    bool userInRightGroup(CurrentContext &context,
                          const ORMUuid &rightGroupId,
                          const ORMUuid &userId);
    void fetchUserRightNumbers(CurrentContext &context,
                               const ORMUuid &userId,
                               std::set<int> &rightNumbersSet);
};

#endif // T0022_RIGHT_GROUP2USER_H

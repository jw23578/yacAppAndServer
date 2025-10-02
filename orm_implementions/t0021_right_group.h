#ifndef T0021_RIGHT_GROUP_H
#define T0021_RIGHT_GROUP_H

#include "appbaseobject.h"
#include "orm_implementions/currentcontext.h"

class t0021_right_group : public AppBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif
    MACRO_UUID_PROPERTY(right_group_id);
    MACRO_STRING_PROPERTY(name);
    MACRO_BOOL_PROPERTY(automatic);
    MACRO_STRING_PROPERTY(access_code);
    MACRO_BOOL_PROPERTY(request_allowed);
    MACRO_BOOL_PROPERTY(visible_for_non_members);

    static std::map<ORMUuid, ORMUuid> appId2AdminGroupId;
public:
    MACRO_CREATE_AND_GETORMNAME(t0021_right_group)
    t0021_right_group():AppBaseObject(Rights::RN_changeRightsGroups)
    {
        MACRO_ADD_PROPERTY_ADD_DETAIL(right_group_id, DetailID);
        MACRO_ADD_PROPERTY(name);
        MACRO_ADD_PROPERTY(automatic);
        MACRO_ADD_PROPERTY(access_code);
        MACRO_ADD_PROPERTY(request_allowed);
        MACRO_ADD_PROPERTY(visible_for_non_members);
    }
    static ORMUuid checkAndGenerateAdminGroup(CurrentContext &context);
    void fetchRightNumbers(ORMPersistenceInterface &opi, std::set<int> &rightNumbers);
    size_t fetchMember(CurrentContext &context, std::set<ORMUuid> &member);
};


#endif // T0021_RIGHT_GROUP_H

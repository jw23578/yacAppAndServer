#ifndef T0021_RIGHT_GROUP_H
#define T0021_RIGHT_GROUP_H

#include "yacbaseobject.h"

class t0021_right_group : public YACBaseObject
{
public:
    MACRO_DECLARE_PROPERTY(ORMPropertyUuid, app_id);
    MACRO_DECLARE_PROPERTY(ORMPropertyString, name);
    MACRO_DECLARE_PROPERTY(ORMPropertyUuid, creater_id);
    MACRO_DECLARE_PROPERTY(ORMPropertyDateTime, deleted_datetime);
    MACRO_DECLARE_PROPERTY(ORMPropertyUuid, deleted_appuser_id);
    MACRO_DECLARE_PROPERTY(ORMPropertyBool, automatic);
    MACRO_DECLARE_PROPERTY(ORMPropertyString, access_code);
    MACRO_DECLARE_PROPERTY(ORMPropertyBool, request_allowed);
    MACRO_DECLARE_PROPERTY(ORMPropertyBool, visible_for_non_members);

    t0021_right_group():YACBaseObject(Rights::RN_changeRightsGroups)
    {
        MACRO_ADD_PROPERTY(app_id);
        MACRO_ADD_PROPERTY(name);
        MACRO_ADD_PROPERTY(creater_id);
        MACRO_ADD_PROPERTY(deleted_datetime);
        MACRO_ADD_PROPERTY(deleted_appuser_id);
        MACRO_ADD_PROPERTY(automatic);
        MACRO_ADD_PROPERTY(access_code);
        MACRO_ADD_PROPERTY(request_allowed);
        MACRO_ADD_PROPERTY(visible_for_non_members);
    }

    const ORMString getORMName() const override
    {
        return "t0021_right_group";
    }
    YACBaseObject *create() const override
    {
        return new t0021_right_group;
    }

};


#endif // T0021_RIGHT_GROUP_H

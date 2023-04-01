#ifndef T0021_RIGHT_GROUP_H
#define T0021_RIGHT_GROUP_H

#include "yacbaseobject.h"

class t0021_right_group : public YACBaseObject
{
public:
    ORMPropertyUuid app_id;
    ORMPropertyString name;
    ORMPropertyUuid creater_id;
    ORMPropertyDateTime deleted_datetime;
    ORMPropertyUuid deleted_appuser_id;
    ORMPropertyBool automatic;
    ORMPropertyString access_code;
    ORMPropertyBool request_allowed;
    ORMPropertyBool visible_for_non_members;

    t0021_right_group():YACBaseObject(Rights::RN_changeRightsGroups)
    {
        MACRO_addProperty(app_id);
        MACRO_addProperty(name);
        MACRO_addProperty(creater_id);
        MACRO_addProperty(deleted_datetime);
        MACRO_addProperty(deleted_appuser_id);
        MACRO_addProperty(automatic);
        MACRO_addProperty(access_code);
        MACRO_addProperty(request_allowed);
        MACRO_addProperty(visible_for_non_members);
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

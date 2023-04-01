#ifndef T0021_RIGHT_GROUP_H
#define T0021_RIGHT_GROUP_H

#include "yacbaseobject.h"
#include <QObject>
class t0021_right_group : public YACBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif

    MACRO_UUID_PROPERTY(app_id);
    MACRO_STRING_PROPERTY(name);
    MACRO_UUID_PROPERTY(creater_id);
    MACRO_DATETIME_PROPERTY(deleted_datetime);
    MACRO_UUID_PROPERTY(deleted_appuser_id);
    MACRO_BOOL_PROPERTY(automatic);
    MACRO_STRING_PROPERTY(access_code);
    MACRO_BOOL_PROPERTY(request_allowed);
    MACRO_BOOL_PROPERTY(visible_for_non_members);

public:
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

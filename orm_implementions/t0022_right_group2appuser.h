#ifndef T0022_RIGHT_GROUP2APPUSER_H
#define T0022_RIGHT_GROUP2APPUSER_H

#include "yacbaseobject.h"

class t0022_right_group2appuser : public YACBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif

    MACRO_UUID_PROPERTY(right_group_id);
    MACRO_UUID_PROPERTY(user_id);
    MACRO_DATETIME_PROPERTY(requested_datetime);
    MACRO_DATETIME_PROPERTY(approved_datetime);
    MACRO_UUID_PROPERTY(approved_appuser_id);
    MACRO_DATETIME_PROPERTY(denied_datetime);
    MACRO_UUID_PROPERTY(denied_appuser_id);
    MACRO_DATETIME_PROPERTY(result_seen);

public:
    MACRO_CREATE_AND_GETORMNAME(t0022_right_group2appuser)
    t0022_right_group2appuser():YACBaseObject(Rights::RN_changeRightsGroups)
    {
        MACRO_ADD_INDEX_PROPERTY(right_group_id);
        MACRO_ADD_INDEX_PROPERTY(user_id);
        MACRO_ADD_PROPERTY(requested_datetime);
        MACRO_ADD_PROPERTY(approved_datetime);
        MACRO_ADD_PROPERTY(approved_appuser_id);
        MACRO_ADD_PROPERTY(denied_datetime);
        MACRO_ADD_PROPERTY(denied_appuser_id);
        MACRO_ADD_PROPERTY(result_seen);
    }
};

#endif // T0022_RIGHT_GROUP2APPUSER_H

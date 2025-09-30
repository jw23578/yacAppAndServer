#ifndef T0023_RIGHT2RIGHTGROUP_H
#define T0023_RIGHT2RIGHTGROUP_H

#include "appbaseobject.h"

class t0023_right2rightgroup : public AppBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif
    MACRO_UUID_PROPERTY(right2rightgroup_id);
    MACRO_INT_PROPERTY(right_number);
    MACRO_UUID_PROPERTY(right_group_id);
public:
    MACRO_CREATE_AND_GETORMNAME(t0023_right2rightgroup)
    t0023_right2rightgroup():AppBaseObject(Rights::RN_changeRightsGroups)
    {
        MACRO_ADD_PROPERTY_ADD_DETAIL(right2rightgroup_id, DetailID);
        MACRO_ADD_PROPERTY(right_number);
        MACRO_ADD_INDEX_PROPERTY(right_group_id);
    }
};



#endif // T0023_RIGHT2RIGHTGROUP_H

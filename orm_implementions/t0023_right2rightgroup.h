#ifndef T0023_RIGHT2RIGHTGROUP_H
#define T0023_RIGHT2RIGHTGROUP_H

#include "yacbaseobject.h"

class t0023_right2rightgroup : public YACBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif
    MACRO_INT_PROPERTY(right_number);
    MACRO_UUID_PROPERTY(right_group_id);
public:
    t0023_right2rightgroup():YACBaseObject(Rights::RN_changeRightsGroups)
    {
        MACRO_ADD_PROPERTY(right_number);
        MACRO_ADD_INDEX_PROPERTY(right_group_id);
    }

    const ORMString getORMName() const override
    {
        return "t0023_right2rightgroup";
    }
    YACBaseObject *create() const override
    {
        return new t0023_right2rightgroup;
    }
};



#endif // T0023_RIGHT2RIGHTGROUP_H

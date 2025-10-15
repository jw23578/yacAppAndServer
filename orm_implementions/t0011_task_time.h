#ifndef T__11_TASK_TIME_H
#define T__11_TASK_TIME_H

#include "appbaseobject.h"

class t0011_task_time : public AppBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif
    MACRO_UUID_PROPERTY(task_time_id);
    MACRO_UUID_PROPERTY(user_id);
    MACRO_DATETIME_PROPERTY(task_start);
    MACRO_DATETIME_PROPERTY(task_end);
public:
    MACRO_CREATE_AND_GETORMNAME(t0011_task_time)

    t0011_task_time():AppBaseObject(Rights::RN_everybody)
    {
        MACRO_ADD_PROPERTY_ADD_DETAIL(task_time_id, DetailID);
        MACRO_ADD_PROPERTY(user_id);
        MACRO_ADD_PROPERTY(task_start);
        MACRO_ADD_PROPERTY(task_end);
    }
};

#endif // T__11_TASK_TIME_H

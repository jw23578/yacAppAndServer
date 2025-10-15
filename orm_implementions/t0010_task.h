#ifndef T__1__TASK_H
#define T__1__TASK_H

#include "appbaseobject.h"

class t0010_task : public AppBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif
    MACRO_UUID_PROPERTY(task_id);
    MACRO_STRING_PROPERTY(task);
    MACRO_DATETIME_PROPERTY(finished);
public:
    MACRO_CREATE_AND_GETORMNAME(t0010_task)

    t0010_task():AppBaseObject(Rights::RN_everybody)
    {
        MACRO_ADD_PROPERTY_ADD_DETAIL(task_id, DetailID);
        MACRO_ADD_PROPERTY(task);
        MACRO_ADD_PROPERTY(finished);
    }
};

#endif // T__1__TASK_H

#ifndef T__12_WORKTIME_H
#define T__12_WORKTIME_H

#include "appbaseobject.h"

class t0012_worktime : public AppBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif
    MACRO_UUID_PROPERTY(worktime_id);
    MACRO_UUID_PROPERTY(user_id);
    MACRO_DATETIME_PROPERTY(ts);
    MACRO_INT_PROPERTY(type);
    MACRO_INT_PROPERTY(user_mood);
    MACRO_INT_PROPERTY(day_rating);
public:
    MACRO_CREATE_AND_GETORMNAME(t0012_worktime)

    t0012_worktime():AppBaseObject(Rights::RN_everybody)
    {
        MACRO_ADD_PROPERTY_ADD_DETAIL(worktime_id, DetailID);
        MACRO_ADD_PROPERTY(user_id);
        MACRO_ADD_PROPERTY(ts);
        MACRO_ADD_PROPERTY(type);
        MACRO_ADD_PROPERTY(user_mood);
        MACRO_ADD_PROPERTY(day_rating);
    }

};

#endif // T__12_WORKTIME_H

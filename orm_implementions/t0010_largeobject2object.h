#ifndef T__1__LARGEOBJECT2OBJECT_H
#define T__1__LARGEOBJECT2OBJECT_H

#include "appbaseobject.h"

class t0010_largeobject2object : public AppBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif
    MACRO_UUID_PROPERTY(largeobject2object_id);
    MACRO_UUID_PROPERTY(largeobject_id);
    MACRO_UUID_PROPERTY(object_id);
    MACRO_INT_PROPERTY(position);
public:
    MACRO_CREATE_AND_GETORMNAME(t0010_largeobject2object)
    t0010_largeobject2object():AppBaseObject(Rights::RN_everybody)
    {
        MACRO_ADD_PROPERTY_ADD_DETAIL(largeobject2object_id, DetailID);
        MACRO_ADD_PROPERTY(largeobject_id);
        MACRO_ADD_PROPERTY(object_id);
        MACRO_ADD_PROPERTY(position);
    }
};

#endif // T__1__LARGEOBJECT2OBJECT_H

#ifndef T0032_CATCHPHRASE2DOCUMENT_H
#define T0032_CATCHPHRASE2DOCUMENT_H

#include "appbaseobject.h"

class t0032_catchphrase2document: public AppBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif
    MACRO_UUID_PROPERTY(catchphrase2document_id);
    MACRO_UUID_PROPERTY(document_id);
    MACRO_UUID_PROPERTY(t0031_id);
public:
    MACRO_CREATE_AND_GETORMNAME(t0032_catchphrase2document)
    t0032_catchphrase2document():AppBaseObject(Rights::RN_everybody)
    {
        MACRO_ADD_PROPERTY_ADD_DETAIL(catchphrase2document_id, DetailID);
        MACRO_ADD_PROPERTY(document_id);
        MACRO_ADD_PROPERTY(t0031_id);
    }
};

#endif // T0032_CATCHPHRASE2DOCUMENT_H

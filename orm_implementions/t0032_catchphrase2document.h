#ifndef T0032_CATCHPHRASE2DOCUMENT_H
#define T0032_CATCHPHRASE2DOCUMENT_H

#include "yacbaseobject.h"

class t0032_catchphrase2document: public YACBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif
    MACRO_UUID_PROPERTY(app_id);
    MACRO_UUID_PROPERTY(document_id);
    MACRO_UUID_PROPERTY(t0031_id);
public:
    MACRO_CREATE_AND_GETORMNAME(t0032_catchphrase2document)
    t0032_catchphrase2document():YACBaseObject(Rights::RN_everybody)
    {
        MACRO_ADD_INDEX_PROPERTY(app_id);
        MACRO_ADD_PROPERTY(document_id);
        MACRO_ADD_PROPERTY(t0031_id);
    }
};

#endif // T0032_CATCHPHRASE2DOCUMENT_H

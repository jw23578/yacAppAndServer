#ifndef T0032_CATCHPHRASE2DOCUMENT_H
#define T0032_CATCHPHRASE2DOCUMENT_H

#include "yacbaseobject.h"

MACRO_BEGIN_APP_ORM_OBJECT(t0032_catchphrase2document)
MACRO_UUID_PROPERTY(document_id);
MACRO_UUID_PROPERTY(t0031_id);
public:
    t0032_catchphrase2document():YACBaseObject(Rights::RN_everybody)
    {
        MACRO_ADD_INDEX_PROPERTY(app_id);
        MACRO_ADD_PROPERTY(document_id);
        MACRO_ADD_PROPERTY(t0031_id);
    }
};

#endif // T0032_CATCHPHRASE2DOCUMENT_H

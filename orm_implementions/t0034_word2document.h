#ifndef T0034_WORD2DOCUMENT_H
#define T0034_WORD2DOCUMENT_H

#include "yacbaseobject.h"

MACRO_BEGIN_APP_ORM_OBJECT(t0034_word2document)
MACRO_UUID_PROPERTY(document_id);
MACRO_UUID_PROPERTY(t0033_id);
public:
t0034_word2document():YACBaseObject(Rights::RN_everybody)
{
    MACRO_ADD_INDEX_PROPERTY(app_id);
    MACRO_ADD_PROPERTY(document_id);
    MACRO_ADD_PROPERTY(t0033_id);
}
};

#endif // T0034_WORD2DOCUMENT_H

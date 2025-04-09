#ifndef T0034_WORD2DOCUMENT_H
#define T0034_WORD2DOCUMENT_H

#include "yacbaseobject.h"

class t0034_word2document: public YACBaseObject
{
#ifdef ORMQTTypes
    Q_OBJECT
#endif
    MACRO_UUID_PROPERTY(app_id);
    MACRO_UUID_PROPERTY(document_id);
    MACRO_UUID_PROPERTY(t0033_id);
public:
    MACRO_CREATE_AND_GETORMNAME(t0034_word2document)
    t0034_word2document():YACBaseObject(Rights::RN_everybody)
    {
        MACRO_ADD_INDEX_PROPERTY(app_id);
        MACRO_ADD_PROPERTY(document_id);
        MACRO_ADD_PROPERTY(t0033_id);
    }
};

#endif // T0034_WORD2DOCUMENT_H

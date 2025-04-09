#ifndef T0033_WORDS_H
#define T0033_WORDS_H

#include "yacbaseobject.h"


class t0033_words: public YACBaseObject
{
    Q_OBJECT
    MACRO_UUID_PROPERTY(app_id);
    MACRO_STRING_PROPERTY(word);
public:
    MACRO_CREATE_AND_GETORMNAME(t0033_words)
    t0033_words():YACBaseObject(Rights::RN_everybody)
    {
        MACRO_ADD_INDEX_PROPERTY(app_id);
        MACRO_ADD_PROPERTY(word);
    }
};

#endif // T0033_WORDS_H

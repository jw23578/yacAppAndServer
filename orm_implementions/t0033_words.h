#ifndef T0033_WORDS_H
#define T0033_WORDS_H

#include "yacbaseobject.h"


MACRO_BEGIN_APP_ORM_OBJECT(t0033_words)
MACRO_STRING_PROPERTY(word);
public:
t0033_words():YACBaseObject(Rights::RN_everybody)
{
    MACRO_ADD_INDEX_PROPERTY(app_id);
    MACRO_ADD_PROPERTY(word);
}
};

#endif // T0033_WORDS_H

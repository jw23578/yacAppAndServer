#ifndef T0026_APPUSER_TAG_H
#define T0026_APPUSER_TAG_H

#include "yacbaseobject.h"

class t0026_appuser_tag : public YACBaseObject
{
public:
    MACRO_DECLARE_PROPERTY(ORMPropertyString, tag);

    t0026_appuser_tag():YACBaseObject(Rights::RN_everybody)
    {
        MACRO_ADD_PROPERTY(tag);
    }
    const ORMString getORMName() const override
    {
        return "t0026_appuser_tag";
    }
    YACBaseObject *create() const override
    {
        return new t0026_appuser_tag;
    }


};

#endif // T0026_APPUSER_TAG_H

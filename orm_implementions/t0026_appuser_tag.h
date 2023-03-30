#ifndef T0026_APPUSER_TAG_H
#define T0026_APPUSER_TAG_H

#include "orm/ormobjectinterface.h"

class t0026_appuser_tag : public ORMObjectInterface
{
    ORMPropertyUuid id;
    ORMPropertyString tag;
public:
    t0026_appuser_tag():ORMObjectInterface()
    {
        MACRO_addProperty(id);
        MACRO_addProperty(tag);
    }
    const ORMString getORMName() const override
    {
        return "t0026_appuser_tag";
    }
    ORMObjectInterface *create() const override
    {
        return new t0026_appuser_tag;
    }


};

#endif // T0026_APPUSER_TAG_H

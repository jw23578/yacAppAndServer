#include "orm/ormpropertyuuid.h"
#include "orm/ormpropertyint.h"
#include "container/indexedpointercontainer.h"

int main(int argc, char **argv)
{
    IndexedPointerContainer<QString, QString> container(true);
    container.add("abc", new QString);
    container.deleteById("abc");

    return 0;
}

#include "ormpropertyuuid.h"
#include "ormpropertyint.h"
#include "container/indexedpointercontainer.h"

int main(int argc, char **argv)
{
    IndexedPointerContainer<ORMString, ORMString> container(true);
    container.add("abc", new ORMString);
    container.deleteById("abc");
    container.deleteByIndex(0);

    return 0;
}

#ifndef YACAPPANDSERVERMACROS_H
#define YACAPPANDSERVERMACROS_H

#ifdef YACAPPServer
#include <string>
#define MACRO_ConstString(nameValue) \
    const std::string nameValue{#nameValue}
#endif
#ifdef YACAPPApp
#include <QString>
#define MACRO_ConstString(nameValue) \
    const QString nameValue{#nameValue}
#endif

#endif // YACAPPANDSERVERMACROS_H

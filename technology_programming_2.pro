TEMPLATE = app
CONFIG += c++17
INCLUDEPATH += include \
               include/cpp \
               include/csharp \
               include/java

HEADERS += \
    include/Unit.h \
    include/IFactory.h \
    include/examples.h \
    include/cpp/CppFactory.h \
    include/cpp/CppClassUnit.h \
    include/cpp/CppMethodUnit.h \
    include/cpp/CppPrintOperatorUnit.h \
    include/csharp/CSharpFactory.h \
    include/csharp/CSharpClassUnit.h \
    include/csharp/CSharpMethodUnit.h \
    include/csharp/CSharpPrintOperatorUnit.h \
    include/java/JavaFactory.h \
    include/java/JavaClassUnit.h \
    include/java/JavaMethodUnit.h \
    include/java/JavaPrintOperatorUnit.h

SOURCES += \
    src/Unit.cpp \
    src/IFactory.cpp \
    src/examples.cpp \
    src/main.cpp \
    src/cpp/CppFactory.cpp \
    src/cpp/CppClassUnit.cpp \
    src/cpp/CppMethodUnit.cpp \
    src/cpp/CppPrintOperatorUnit.cpp \
    src/csharp/CSharpFactory.cpp \
    src/csharp/CSharpClassUnit.cpp \
    src/csharp/CSharpMethodUnit.cpp \
    src/csharp/CSharpPrintOperatorUnit.cpp \
    src/java/JavaFactory.cpp \
    src/java/JavaClassUnit.cpp \
    src/java/JavaMethodUnit.cpp \
    src/java/JavaPrintOperatorUnit.cpp

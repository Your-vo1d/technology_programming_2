TEMPLATE = app
CONFIG += c++17
INCLUDEPATH += include

HEADERS += \
    include/Unit.h \
    include/ClassUnit.h \
    include/MethodUnit.h \
    include/PrintOperatorUnit.h

SOURCES += \
    src/Unit.cpp \
    src/ClassUnit.cpp \
    src/MethodUnit.cpp \
    src/PrintOperatorUnit.cpp \
    src/main.cpp

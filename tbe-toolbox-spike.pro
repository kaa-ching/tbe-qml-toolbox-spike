TEMPLATE = app

QT += quick qml svg xml
CONFIG += c++11

SOURCES += main.cpp \
    ImageProvider.cpp
RESOURCES += \
    views.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/quick/views
INSTALLS += target

DISTFILES += \
    main.qml

HEADERS += \
    ImageProvider.h

QT += quick

CONFIG += c++11 sanitizer sanitize_address sanitize_leak sanitize_undefined

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        gameboard.cpp \
        main.cpp

RESOURCES += qml.qrc

QML_IMPORT_PATH =
QML_DESIGNER_IMPORT_PATH =

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    gameboard.h

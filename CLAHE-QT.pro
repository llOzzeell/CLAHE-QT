QT = core gui

CONFIG += c++11 console

SOURCES += \
        CLAHE.c \
        main.cpp

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

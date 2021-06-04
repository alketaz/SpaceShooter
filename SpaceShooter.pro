QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller/controller.cpp \
    controller/menucontroller.cpp \
    controller/playcontroller.cpp \
    model/bullet.cpp \
    model/deep_ptr.cpp \
    main.cpp \
    model/player.cpp \
    model/spaceship.cpp \
    model/vettore.cpp \
    view/2D_models/bulletmodel.cpp \
    view/2D_models/enemymodel.cpp \
    view/2D_models/playermodel.cpp \
    view/gamescene.cpp \
    view/mainmenu.cpp \
    view/mainwindow.cpp \
    view/mainwindowview.cpp


HEADERS += \
    controller/controller.h \
    controller/menucontroller.h \
    controller/playcontroller.h \
    model/bullet.h \
    model/deep_ptr.h \
    model/player.h \
    model/spaceship.h \
    model/enemy.h \
    model/vettore.h \
    view/2D_models/bulletmodel.h \
    view/2D_models/enemymodel.h \
    view/2D_models/playermodel.h \
    view/gamescene.h \
    view/mainmenu.h \
    view/mainwindow.h \
    view/mainwindowview.h \
    view/viewSelector.h

FORMS += \
    view/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc \
    resource.qrc

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
    controller/tutorialcontroller.cpp \
    model/deep_ptr.cpp \
    main.cpp \
    model/enemy.cpp \
    model/finalenemy.cpp \
    model/player.cpp \
    model/spaceship.cpp \
    model/specialenemy.cpp \
    model/vettore.cpp \
    model/playmodel.cpp \
    view/2D_models/bulletmodel.cpp \
    view/2D_models/enemymodel.cpp \
    view/2D_models/healthbar.cpp \
    view/2D_models/playermodel.cpp \
    view/gamescene.cpp \
    view/mainmenu.cpp \
    view/mainwindow.cpp \
    view/mainwindowview.cpp \
    view/tutorialscene.cpp


HEADERS += \
    controller/controller.h \
    controller/menucontroller.h \
    controller/playcontroller.h \
    controller/tutorialcontroller.h \
    model/deep_ptr.h \
    model/enemy.h \
    model/enumClasses.h \
    model/finalenemy.h \
    model/gamephase.h \
    model/player.h \
    model/spaceship.h \
    model/specialenemy.h \
    model/vettore.h \
    model/playmodel.h \
    view/2D_models/bulletmodel.h \
    view/2D_models/enemymodel.h \
    view/2D_models/healthbar.h \
    view/2D_models/playermodel.h \
    view/gamescene.h \
    view/mainmenu.h \
    view/mainwindow.h \
    view/mainwindowview.h \
    view/tutorialscene.h \
    view/viewSelector.h

FORMS += \
    view/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES +=


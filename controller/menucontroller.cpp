#include "controller/menucontroller.h"

menucontroller::menucontroller() : controller(){
    scene = new mainmenu();
    connect(scene, &mainmenu::onPlayPressed, this, [=](){emit sceneRequest(viewSelector::playScene);});
}

QGraphicsScene* menucontroller::getScene() const{return scene;}

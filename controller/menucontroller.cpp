#include "menucontroller.h"
#include "view/viewSelector.h"

menucontroller::menucontroller() : controller(){
    scene = new mainmenu();
    connect(scene, &mainmenu::onPlayPressed, this, [=](){emit controller::sceneRequest(viewSelector::playScene);});
    connect(scene, &mainmenu::onTutorialPressed, this, [=](){emit controller::sceneRequest(viewSelector::tutorialScene);});
    connect(scene, &mainmenu::onOptionsPressed, this, [=](){emit controller::sceneRequest(viewSelector::optionsScene);});
}

QGraphicsScene* menucontroller::getScene() const{return scene;}


#include "tutorialcontroller.h"

tutorialcontroller::tutorialcontroller(): controller(), scene(new tutorialScene()){
    connect(scene, &tutorialScene::menuPressed, this, [=](){emit sceneRequest(viewSelector::mainMenu);});
}

QGraphicsScene* tutorialcontroller::getScene() const{return scene;}

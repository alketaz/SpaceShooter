#include "playcontroller.h"

playcontroller::playcontroller(): controller(){
    scene = new gameScene();
}

QGraphicsScene* playcontroller::getScene() const{return scene;}

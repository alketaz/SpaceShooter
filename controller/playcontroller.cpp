#include "playcontroller.h"

playcontroller::playcontroller(): controller(), model(new playModel(1920,1080)), moveTimer(new QTimer())
{
    scene = new gameScene(model);
    moveTimer->start(1200);
    connect(moveTimer, &QTimer::timeout, scene, &gameScene::move);
    connect(moveTimer, &QTimer::timeout, model, &playModel::updateEnemyPosition);
}

QGraphicsScene* playcontroller::getScene() const{return scene;}

void playcontroller::tick(){
    QTimer* tick(new QTimer());
    tick->start(30);
    //connect(tick, &QTimer::timeout, this, &playcontroller::checkCollisions);
    //connect(tick, &QTimer::timeout, this, &playcontroller::checkPlayerActions);
}

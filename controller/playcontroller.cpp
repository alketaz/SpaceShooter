#include "playcontroller.h"

playcontroller::playcontroller(): controller(), model(new playModel(1920,1080)), moveTimer(new QTimer())
{
    scene = new gameScene(model);
    tick();
    moveTimer->start(1200);
    connect(moveTimer, &QTimer::timeout, scene, &gameScene::move);
    connect(moveTimer, &QTimer::timeout, model, &playModel::updateEnemyPosition);
}

QGraphicsScene* playcontroller::getScene() const{return scene;}

void playcontroller::tick(){
    QTimer* tick(new QTimer());
    tick->start(30);
    QTimer* bulletTick(new QTimer());
    bulletTick->start(500);
    //connect(tick, &QTimer::timeout, this, &playcontroller::checkCollisions);
    connect(tick, &QTimer::timeout, this, &playcontroller::checkPlayerActions);
    connect(bulletTick, &QTimer::timeout, this, &playcontroller::checkForBullets);
}

void playcontroller::checkPlayerActions(){
    int x = scene->movePlayerX();
    int y = scene->movePlayerY();
    if(x || y){
        model->movePlayer(x,y);
        scene->updatePlayer(x,y);
    }
}

void playcontroller::checkForBullets(){
    bulletModel* bullet = new bulletModel();
    bullet->setPos(scene->getPlayerPos()[0], scene->getPlayerPos()[1]);
    scene->addItem(bullet);
}

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
    QTimer* enemyBulletTick(new QTimer());
    enemyBulletTick->start(100);
    //connect(tick, &QTimer::timeout, this, &playcontroller::checkGameState);
    connect(tick, &QTimer::timeout, scene, &gameScene::checkCollisions);
    connect(tick, &QTimer::timeout, this, &playcontroller::checkPlayerActions);
    connect(bulletTick, &QTimer::timeout, this, &playcontroller::spawnBullets);
    connect(enemyBulletTick, &QTimer::timeout, this, &playcontroller::spawnEnemyBullets);
    //connect(tick, &QTimer::timeout, this, &playcontroller::checkCollisions);
}

void playcontroller::checkPlayerActions(){
    int x = scene->movePlayerX();
    int y = scene->movePlayerY();
    if(x || y){
        model->movePlayer(x,y);
        scene->updatePlayer(x,y);
    }
}

void playcontroller::spawnBullets(){
    bulletModel* bullet = new bulletModel(true);
    bullet->setPos(scene->getPlayerBulletPos()[0], scene->getPlayerBulletPos()[1]);
    scene->addItem(bullet);
}

void playcontroller::spawnEnemyBullets(){
    bulletModel* bullet = new bulletModel(false);
    unsigned int randEnemy = (rand()%(model->enemySize()));
    bullet->setPos(scene->getEnemyBulletPos(randEnemy)[0], scene->getEnemyBulletPos(randEnemy)[1]);
    scene->addItem(bullet);
}

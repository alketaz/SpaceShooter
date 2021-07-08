#include "playcontroller.h"

playcontroller::playcontroller(): controller(), model(new playModel(1920,1080)), moveTimer(new QTimer()), tick(new QTimer()), bulletTick(new QTimer()), enemyBulletTick(new QTimer())
{
    scene = new gameScene(model);
    moveTimer->start(1200);
    tick->start(30);
    bulletTick->start(750);
    enemyBulletTick->start(1000);
    connect(moveTimer, &QTimer::timeout, scene, &gameScene::move);
    connect(moveTimer, &QTimer::timeout, model, &playModel::updateEnemyPosition);

    connect(tick, &QTimer::timeout, this, &playcontroller::checkState);
    connect(tick, &QTimer::timeout, this, &playcontroller::checkPlayerActions);
    connect(tick, &QTimer::timeout, scene, &gameScene::checkCollisions);

    connect(bulletTick, &QTimer::timeout, this, &playcontroller::spawnBullets);
    connect(enemyBulletTick, &QTimer::timeout, this, &playcontroller::spawnEnemyBullets);

    connect(scene, &gameScene::stopBullets, tick, &QTimer::stop);
    connect(scene, &gameScene::stopBullets, bulletTick, &QTimer::stop);
    connect(scene, &gameScene::stopBullets, moveTimer, &QTimer::stop);
    connect(scene, &gameScene::stopBullets, enemyBulletTick, &QTimer::stop);
    connect(scene, &gameScene::resume, tick, [=](){tick->start();});
    connect(scene, &gameScene::resume, bulletTick, [=](){bulletTick->start();});
    connect(scene, &gameScene::resume, moveTimer, [=](){moveTimer->start();});
    connect(scene, &gameScene::resume, enemyBulletTick, [=](){enemyBulletTick->start();});
    connect(scene, &gameScene::gameEnd, this, [=](){emit sceneRequest(viewSelector::mainMenu);});
    //connect(this, &playcontroller::checkPlayerActions, scene, &gameScene::checkCollisions);
}

QGraphicsScene* playcontroller::getScene() const{return scene;}

void playcontroller::checkState()
{
    if((scene->enemiesCleared() && model->enemiesCleared()) || model->playerDead())
        emit scene->changeState();
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
    if(!model->playerDead()){
        bulletModel* bullet = new bulletModel(true);
        bullet->setPos(scene->getPlayerBulletPos()[0], scene->getPlayerBulletPos()[1]);
        scene->addItem(bullet);
        connect(tick, &QTimer::timeout, bullet, &bulletModel::move);
    }
}

void playcontroller::healPlayer(){model->healPlayer();}

void playcontroller::spawnEnemyBullets(){
    unsigned int size = (model->enemySize()<5 ? model->enemySize()/2+1 : 5);
    unsigned int* shootingShips = new unsigned int[size];
    for (unsigned int i=0; i < size; i++){
        bulletModel* bullet = new bulletModel(false);
        unsigned int randEnemy = (rand()%(model->enemySize()));
        for(unsigned int j=0; j<i; j++){
            if(randEnemy==shootingShips[j]){
                ++randEnemy;
                randEnemy = randEnemy%model->enemySize();
                j--;
            }
        }
        shootingShips[i]=randEnemy;
        bullet->setPos(scene->getEnemyBulletPos(randEnemy)[0], scene->getEnemyBulletPos(randEnemy)[1]);
        spaceship* origin = model->getEnemy(randEnemy);
        bullet->setDmg(origin->getDmg());
        scene->addItem(bullet);
        connect(tick, &QTimer::timeout, bullet, &bulletModel::move);
    }
}

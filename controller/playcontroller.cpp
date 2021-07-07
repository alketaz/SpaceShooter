#include "playcontroller.h"

playcontroller::playcontroller(): controller(), model(new playModel(1920,1080)), moveTimer(new QTimer())
{
    scene = new gameScene(model);
    tick();
    moveTimer->start(1200);
    connect(moveTimer, &QTimer::timeout, scene, &gameScene::move);
    connect(moveTimer, &QTimer::timeout, model, &playModel::updateEnemyPosition);
    connect(scene, &gameScene::gameEnd, this, [=](){emit sceneRequest(viewSelector::mainMenu);});
    connect(this, &playcontroller::checkPlayerActions, scene, &gameScene::checkCollisions);
}

QGraphicsScene* playcontroller::getScene() const{return scene;}

void playcontroller::tick(){
    QTimer* tick(new QTimer());
    tick->start(30);
    QTimer* bulletTick(new QTimer());
    bulletTick->start(750);
    QTimer* enemyBulletTick(new QTimer());
    enemyBulletTick->start(100);
    connect(tick, &QTimer::timeout, this, &playcontroller::checkState);
    connect(tick, &QTimer::timeout, this, &playcontroller::checkPlayerActions);
    connect(bulletTick, &QTimer::timeout, this, &playcontroller::spawnBullets);
    connect(bulletTick, &QTimer::timeout, this, &playcontroller::spawnEnemyBullets);
}


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
    emit scene->checkCollisions();
}

void playcontroller::spawnBullets(){
    if(!model->playerDead()){
        bulletModel* bullet = new bulletModel(true);
        bullet->setPos(scene->getPlayerBulletPos()[0], scene->getPlayerBulletPos()[1]);
        scene->addItem(bullet);
    }
}

void playcontroller::healPlayer(){model->healPlayer();}

void playcontroller::spawnEnemyBullets(){
    unsigned int size = (model->enemySize()<5 ? model->enemySize()/2+1 : 5);
    unsigned int* shootingShips = new unsigned int[size];
    for (int i=0; i < size; i++){
        bulletModel* bullet = new bulletModel(false);
        unsigned int randEnemy = (rand()%(model->enemySize()));
        for(int j=0; j<i; j++){
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
    }
}

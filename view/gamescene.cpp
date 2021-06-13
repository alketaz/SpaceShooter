#include "gamescene.h"

gameScene::gameScene(playModel* m): match(m), phase(gamePhase::base), p(new playerModel()) , playerActions(new bool[5]) //, moveTimer(new QTimer())
{
    for(int i=0;i<5;i++)
        playerActions[i]=false;
    setSceneRect(0,0,m->getScreenW(),m->getScreenH());
    loadBG();
    //loadInfoBox();
    loadPlayer();
    loadEnemies();
}

void gameScene::loadBG()
{
    QPixmap bg(":/img/game_bg.png");
    QBrush brush(bg);
    setBackgroundBrush(brush);
}

void gameScene::loadInfoBox(){
    QGraphicsRectItem infoLeft(0,0,320,1080);
    QGraphicsRectItem infoRight(1600,0,320,1080);
    QBrush grey(QColor::fromRgb(255,255,255));
    infoLeft.setBrush(grey);
    infoRight.setBrush(grey);
    addItem(&infoLeft);
    addItem(&infoRight);
    //Non funziona
}

void gameScene::loadPlayer()
{
    p->setPos(width()/2-32, height()-96);
    addItem(p);
    p->setFocus();
}

void gameScene::loadEnemies()
{
    /*bool ex=false;
    std::vector<enemyModel*> v;
    for(int i=0; !ex; i++){
        if(i*128+64>=width())
            ex = true;
        else{
            enemyModel* enemy = new enemyModel();
            enemy->setPos(enemy->x()+i*128, enemy->y());
            v.push_back(enemy);
            addItem(enemy);
        }
    }*/

    switch(phase){
    case gamePhase::base:
        match->FirstWave();
        vettore<enemyModel*> aux;
        for(vettore<deep_ptr<spaceship>>::const_iterator cit = match->enemies.begin(); cit!=match->enemies.end(); cit++){
            enemyModel* eM = new enemyModel();
            eM->setPos((*cit)->getX(), (*cit)->getY());
            aux.push_back(eM);
            addItem(eM);
        }
        enemyItems = aux;
        break;
    /*case gamePhase::special:
        break;
    case gamePhase::final:
        break;
    case gamePhase::won:
        break;*/
    }
}

int* gameScene::getPlayerPos() const{
    int* aux = new int[2];
    aux[0] = p->x() + p->getWidth()/2 - 2;
    aux[1] = p->y();
    return aux;
}


void gameScene::enemiesCleared(){
    if(phase == gamePhase::base)
        phase = gamePhase::special;
    else if(phase == gamePhase::special)
        phase = gamePhase::final;
    else
        phase = gamePhase::won;
    loadEnemies();
}

void gameScene::move(){
    for(vettore<enemyModel*>::iterator it = enemyItems.begin(); it!=enemyItems.end(); it++)
        (*it)->setPos((*it)->x(), (*it)->y()+16);
}

int gameScene::movePlayerX() const{
    int res =0;
    if(playerActions[0])
        res-=8;
    if(playerActions[2])
        res+=8;
    qDebug() << "movePlayerX: "<<res;
    return res;
}

int gameScene::movePlayerY() const{
    int res =0;
    if(playerActions[1])
        res-=8;
    if(playerActions[3])
        res+=8;
    return res;
}

bool gameScene::spawnBullet() const{
    return playerActions[4];
}

void gameScene::keyPressEvent(QKeyEvent* event){
    switch (event->key()){
    case Qt::Key_Left:
        playerActions[0] = true;
        break;
    case Qt::Key_Up:
        playerActions[1] = true;
        break;
    case Qt::Key_Right:
        playerActions[2] = true;
    break;
    case Qt::Key_Down:
        playerActions[3] = true;
    break;
    case Qt::Key_Space:
        playerActions[4] = true;
    break;
    }
}

void gameScene::keyReleaseEvent(QKeyEvent* event){
    switch (event->key()){
    case Qt::Key_Left:
        playerActions[0] = false;
        break;
    case Qt::Key_Up:
        playerActions[1] = false;
        break;
    case Qt::Key_Right:
        playerActions[2] = false;
    break;
    case Qt::Key_Down:
        playerActions[3] = false;
    break;
    case Qt::Key_Space:
        playerActions[4] = false;
    break;
    }
}

void gameScene::updatePlayer(int w, int h){
    p->setPos(p->x()+ w, p->y() + h);
    if(p->x() + p->getWidth() > width())
        p->setPos(width() - p->getWidth(), p->y());

    if(p->x() < 0)
        p->setPos(0, p->y());

    if(p->y() + p->getHeight() > height())
        p->setPos(p->x(), height()- p->getHeight());

    if(p->y() < 0)
        p->setPos(p->x(), 0);
}


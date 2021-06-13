#include "gamescene.h"

gameScene::gameScene(playModel* m): match(m), phase(gamePhase::base), playerActions(new bool[5]) //, moveTimer(new QTimer())
{
    for(int i=0;i<5;i++)
        playerActions[i]=false;
    setSceneRect(0,0,m->getScreenW(),m->getScreenH());
    loadBG();
    loadPlayer();
    loadEnemies();
    //moveTimer->start(1200);
    //connect(moveTimer, &QTimer::timeout, this, &gameScene::move);
}

void gameScene::loadBG()
{
    QPixmap bg(":/img/game_bg.png");
    QBrush brush(bg);
    setBackgroundBrush(brush);
}

void gameScene::loadPlayer()
{
    playerModel* player = new playerModel();
    player->setPos(width()/2-32, height()-96);
    addItem(player);
    player->setFocus();
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

#include "gamescene.h"

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
        match->setWave(match->FirstWave(width()));
        for(vettore<deep_ptr<spaceship>>::const_iterator cit = match->enemies.begin(); cit!=match->enemies.end(); cit++){
            enemyModel* eM = new enemyModel();
            eM->setPos((*cit)->getX(), (*cit)->getY());
            addItem(eM);
        }
        break;
    /*case gamePhase::special:
        break;
    case gamePhase::final:
        break;
    case gamePhase::won:
        break;*/
    }
}

gameScene::gameScene(): match(new playModel()), phase(gamePhase::base)
{
    setSceneRect(0,0,1920,1080);
    loadBG();
    loadPlayer();
    loadEnemies();
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

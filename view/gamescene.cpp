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
    int xPos = 64, yPos = -64;
    switch(phase){
    case gamePhase::base:
        for(int i=0; i*128+64+xPos<width(); i++){
            enemies.push_back(new enemy());

        }
        break;
    case gamePhase::special:
        break;
    case gamePhase::final:
        break;
    }
}

gameScene::gameScene(): phase(gamePhase::base)
{
    setSceneRect(0,0,1920,1080);
    loadBG();
    loadPlayer();
    loadEnemies();
}

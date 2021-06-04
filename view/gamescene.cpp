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
    bool ex=false;
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
    }
}

gameScene::gameScene()
{
    setSceneRect(0,0,1920,1080);
    loadBG();
    loadPlayer();
    loadEnemies();
}

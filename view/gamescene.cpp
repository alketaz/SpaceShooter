#include "gamescene.h"

gameScene::gameScene()
{
    setSceneRect(0,0,1920,1080);
    playerModel* player = new playerModel();
    player->setPos(width()/2-32, height()-96);
    addItem(player);
    player->setFocus();
}

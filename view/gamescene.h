#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include "model/deep_ptr.h"
#include "model/player.h"
#include "model/enemy.h"

class gameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    gameScene();

private:
    //deep_ptr<enemy> enemy;
};

#endif // GAMESCENE_H

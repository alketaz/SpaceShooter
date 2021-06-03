#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "model/deep_ptr.h"
#include "model/player.h"
#include "model/enemy.h"
#include "view/2D_models/playermodel.h"

class gameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    gameScene();

private:
    //deep_ptr<enemy> enemy;
};

#endif // GAMESCENE_H

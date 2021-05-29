#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include "model/deep_ptr.h"
#include "model/player.h"

class gameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    gameScene();

private:
    deep_ptr
};

#endif // GAMESCENE_H

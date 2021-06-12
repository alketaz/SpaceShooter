#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "model/deep_ptr.h"
#include "model/gamephase.h"
#include "model/playmodel.h"
#include "view/2D_models/playermodel.h"
#include "view/2D_models/enemymodel.h"

class gameScene : public QGraphicsScene
{
    Q_OBJECT
private:
    playModel* match;
    gamePhase phase;

public:
    gameScene();
    void loadBG();
    void loadPlayer();
    void loadEnemies();

public slots:
    void enemiesCleared();
};

#endif // GAMESCENE_H

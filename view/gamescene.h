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
    vettore<enemyModel*> enemyItems;
    bool* playerActions;
    //QTimer* moveTimer;

public:
    gameScene(playModel*);
    void loadBG();
    void loadPlayer();
    void loadEnemies();

/*signals:
    void updateMatch();*/

public slots:
    void enemiesCleared();
    void move();
};

#endif // GAMESCENE_H

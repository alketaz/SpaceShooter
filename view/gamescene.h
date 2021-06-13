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
    playerModel* p;
    bool* playerActions;
    //QTimer* moveTimer;

public:
    gameScene(playModel*);
    void loadBG();
    void loadInfoBox();
    void loadPlayer();
    void loadEnemies();

    int* getPlayerPos() const;

    int movePlayerX() const;
    int movePlayerY() const;
    bool spawnBullet() const;

    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);

/*signals:
    void updateMatch();*/

public slots:
    void enemiesCleared();
    void move();  //usare per connect e tiorna
    void updatePlayer(int, int);
};

#endif // GAMESCENE_H

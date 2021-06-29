#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include "model/deep_ptr.h"
#include "model/gamephase.h"
#include "model/playmodel.h"
#include "model/enumClasses.h"
#include "view/2D_models/playermodel.h"
#include "view/2D_models/enemymodel.h"
#include "view/2D_models/bulletmodel.h"
#include "view/2D_models/healthbar.h"

class bulletModel;
class healthBar;

class gameScene : public QGraphicsScene
{
    Q_OBJECT
private:
    playModel* match;
    gamePhase phase;
    std::vector<enemyModel*> enemyItems;
    std::vector<healthBar*> enemyHealth;
    vettore<bulletModel*> bulletItems;
    QGraphicsPixmapItem* p;
    healthBar* hp;
    bool* playerActions;
    //QTimer* moveTimer;

public:
    gameScene(playModel*);
    void loadBG();
    void loadInfoBox();
    void loadPlayer();
    void loadEnemies();

    int* getPlayerBulletPos() const;
    int* getEnemyBulletPos(unsigned int) const;
    int getEnemyByPos(int x, int y) const;
    unsigned int getEnemyHit() const;
    void checkCollisions();
    bool enemiesCleared() const;

    int movePlayerX() const;
    int movePlayerY() const;
    bool spawnBullet() const;
    void addToBulletVector(bulletModel*);
    void removeEnemy(unsigned int);

    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);

/*signals:
    void updateMatch();*/

public slots:
    void move();
    void changeState();
    void updatePlayer(int, int);
};

#endif // GAMESCENE_H

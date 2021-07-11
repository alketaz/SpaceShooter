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

class playerModel;
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
    //vettore<bulletModel*> bulletItems;
    playerModel* p;
    healthBar* hp;
    bool* playerActions;
    //QGraphicsPixmapItem menuButton;
    QGraphicsPixmapItem menuText;
    QGraphicsPixmapItem menuButton;

public:
    gameScene(playModel*);
    void loadBG();
    void loadInfoBox();
    void loadPlayer();
    void loadWave();
    void loadEnemies();

    int* getPlayerBulletPos() const;
    int* getEnemyBulletPos(unsigned int) const;
    //enemyModel* getEnemyByPos(unsigned int) const;
    //unsigned int getEnemyHit() const;
    void checkCollisions();
    bool enemiesCleared() const;
    //void checkPause();

    int movePlayerX();
    int movePlayerY();
    //bool spawnBullet() const;
    //void addToBulletVector(bulletModel*);
    void removeEnemy(unsigned int);

    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);

signals:
    void gameEnd();
    void stopBullets();
    void resume();
    void shieldDown();

public slots:
    void move();
    void changeState();
    void updatePlayer(int, int);
    void healPlayer();
    void refillShield();
    //void pauseMenu();
};

#endif // GAMESCENE_H

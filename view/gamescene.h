#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QPushButton>
#include "model/deep_ptr.h"
#include "model/gamephase.h"
#include "model/playmodel.h"
#include "view/enumClasses.h"
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
    playerModel* p;
    healthBar* hp;
    bool* playerActions;
    QGraphicsRectItem* bgrect;
    QGraphicsPixmapItem* menuText;
    QPushButton* menuButton;

public:
    gameScene(playModel*);
    void loadBG();
    void loadInfoBox();
    void loadPlayer();
    void loadWave();
    void loadEnemies();

    int* getPlayerBulletPos() const;
    int* getEnemyBulletPos(unsigned int) const;
    void checkCollisions();
    bool enemiesCleared() const;

    int movePlayerX();
    int movePlayerY();
    void removeEnemy(unsigned int);

    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);

    void loadPause();

signals:
    void gameEnd();
    void stopBullets();
    void resume();
    void shieldDown();
    void enemyOut();
    void menuPressed();

public slots:
    void move();
    void changeState();
    void updatePlayer(int, int);
    void healPlayer();
    void refillShield();
};

#endif // GAMESCENE_H

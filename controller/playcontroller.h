#ifndef PLAYCONTROLLER_H
#define PLAYCONTROLLER_H
#include <QObject>
#include "math.h"
#include "controller.h"
#include "view/gamescene.h"

class playcontroller: public controller
{
    Q_OBJECT;
private:
    gameScene* scene;
    playModel* model;
    QTimer* moveTimer;
    QTimer* tick;
    QTimer* bulletTick;
    QTimer* enemyBulletTick;

public:
    playcontroller();
    QGraphicsScene* getScene() const;

public slots:
    void checkState();
    void checkPlayerActions();
    void spawnEnemyBullets();
    void spawnBullets();
    void healPlayer();
    void shieldCooldown();
};

#endif // PLAYCONTROLLER_H

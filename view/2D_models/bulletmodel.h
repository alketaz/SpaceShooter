#ifndef BULLETMODEL_H
#define BULLETMODEL_H

#include <QGraphicsRectItem>
#include <QTimer>
#include <QGraphicsScene>
#include "view/2d_models/enemymodel.h"
#include "view/gamescene.h"


class bulletModel : public QObject, public QGraphicsRectItem
{
private:
    QTimer* timer;
    bool playerBullet;
    unsigned int dmg;
    enemyModel* hitShip;

public:
    bulletModel(bool);
    bool fromPlayer();
    void setDmg(unsigned int);
    //enemyModel* gotHit();

signals:
    void enemyHit();

public slots:
    void move();
};

#endif // BULLETMODEL_H

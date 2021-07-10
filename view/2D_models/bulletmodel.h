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
    bool playerBullet;
    unsigned int dmg;

public:
    bulletModel(bool);
    bulletModel(const bulletModel&);
    void setDmg(unsigned int);
    unsigned int getDmg() const;
    bool getDir() const;
    //enemyModel* gotHit();

signals:
    void enemyHit();

public slots:
    void move();
};

#endif // BULLETMODEL_H

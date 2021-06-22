#include "view/2D_models/bulletmodel.h"

bulletModel::bulletModel(bool b): timer(new QTimer()), playerBullet(b)
{
    setRect(0,0,4,16);
    setBrush(playerBullet ? Qt::red : Qt::green);
    connect(timer, &QTimer::timeout, this, [=](){emit move();});
    timer->start(16);
}

void bulletModel::move(){
    setPos(x(), (playerBullet? y()-8 : y()+8));

    if(y()<=-16 || y() >= 1080){
        scene()->removeItem(this);
        delete this;
    }

    else{
        QList<QGraphicsItem*> impact = collidingItems();
        for(int i=0, n=impact.size(); i<n; i++){
            if(playerBullet && dynamic_cast<enemyModel*>(impact[i])){
                scene()->removeItem(this);
                hitShip = static_cast<enemyModel*>(impact[i]);
                hitShip->setHit(true);
                delete this;
            }
            if(!playerBullet && typeid(*(impact[i]))==typeid(playerModel)){
                scene()->removeItem(this);
                delete this;
            }
        }
    }
}

enemyModel* bulletModel::gotHit(){return hitShip;}

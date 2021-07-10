#include "view/2D_models/bulletmodel.h"

bulletModel::bulletModel(bool b): playerBullet(b), dmg(0)
{
    setRect(0,0,4,16);
    setBrush(playerBullet ? Qt::red : Qt::green);
}

bulletModel::bulletModel(const bulletModel & b): QObject(), QGraphicsRectItem(), playerBullet(b.playerBullet), dmg(b.dmg)
{
    setRect(0,0,4,16);
    setBrush(playerBullet ? Qt::red : Qt::green);
}

void bulletModel::setDmg(unsigned int i) {dmg = i;}

unsigned int bulletModel::getDmg() const {return dmg;}

bool bulletModel::getDir() const {return playerBullet;}

void bulletModel::move(){
    setPos(x(), (playerBullet? y()-12 : y()+12));

    if(y()<=-16 || y() >= 1080){
        scene()->removeItem(this);
        delete this;
    }

    else{
        QList<QGraphicsItem*> impact = collidingItems();
        for(int i=0; i<impact.size(); i++){
            if(playerBullet && dynamic_cast<enemyModel*>(impact[i])){
                scene()->removeItem(this);
                auto hitShip = static_cast<enemyModel*>(impact[i]);
                hitShip->setHit(true);
                delete this;
            }
            if(!playerBullet && typeid(*(impact[i]))==typeid(playerModel)){
                scene()->removeItem(this);
                auto hitShip = static_cast<playerModel*>(impact[i]);
                hitShip->setHit(true);
                hitShip->setDmg(dmg);
                delete this;
            }
        }
    }
}


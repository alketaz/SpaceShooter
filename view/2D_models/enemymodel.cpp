#include "enemymodel.h"
#include <QDebug>

enemyModel::enemyModel(enemyType et): type(et), width(64), height(64), updateTimer(new QTimer()), hit(false)
{
    QPixmap ship1(":/img/enemy1.png");
    QPixmap ship2(":/img/enemy2.png");
    QPixmap ship3(":/img/enemy3.png");
    sprite.push_back(ship1);
    sprite.push_back(ship2);
    sprite.push_back(ship3);
    setSprite(rand()%3);
    updateTimer->start(200);
    connect(updateTimer, &QTimer::timeout, this, &enemyModel::changeSprite);
}

void enemyModel::setSprite(unsigned int i){
    setPixmap(sprite[i].scaled(width,height));
}

void enemyModel::setHit(bool b){hit = b;}

bool enemyModel::getHit() const
{
    qDebug() << "addr:"<<this;
    return hit;
}

void enemyModel::changeSprite(){
    spriteSel++;
    spriteSel%=3;
    setSprite(spriteSel);
}

unsigned int enemyModel::getHeight() const{return height;}

unsigned int enemyModel::getWidth() const{return width;}

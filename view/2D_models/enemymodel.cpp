#include "enemymodel.h"

enemyModel::enemyModel(): updateTimer(new QTimer())
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
    setPixmap(sprite[i].scaled(64,64));
}

void enemyModel::changeSprite(){
    spriteSel++;
    spriteSel%=3;
    setSprite(spriteSel);
}

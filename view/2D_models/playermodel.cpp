#include "playermodel.h"

playerModel::playerModel(): updateTimer(new QTimer()), width(64), height(80), sprite(0)
{
    QPixmap ship1(":/img/user1.png");
    QPixmap ship2(":/img/user2.png");
    QPixmap ship3(":/img/user3.png");
    sprite.push_back(ship1);
    sprite.push_back(ship2);
    sprite.push_back(ship3);
    setSprite();
    setFlag(QGraphicsItem::ItemIsFocusable);
    updateTimer->start(200);
    connect(updateTimer, &QTimer::timeout, this, &playerModel::changeSprite);
}

void playerModel::setSprite(unsigned int i){
    setPixmap(sprite[i].scaled(width,height));
}

void playerModel::changeSprite(){
    spriteSel+=1;
    spriteSel%=3;
    setSprite(spriteSel);
}

unsigned int playerModel::getWidth() const{return width;}

unsigned int playerModel::getHeight() const{return height;}

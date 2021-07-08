#include "enemymodel.h"
#include <QDebug>

enemyModel::enemyModel(enemyType et): type(et), width(type==enemyType::final ? 512 : (type==enemyType::special ? 256 : 64)), height(type==enemyType::final ? 256 : (type==enemyType::special ? 128 : 64)), updateTimer(new QTimer()), hit(false)
{
    if(type == enemyType::base){
        QPixmap ship1(":/img/enemy1.png");
        QPixmap ship2(":/img/enemy2.png");
        QPixmap ship3(":/img/enemy3.png");
        sprite.push_back(ship1);
        sprite.push_back(ship2);
        sprite.push_back(ship3);
    }
    else if(type == enemyType::mini){
        QPixmap img(":/img/mini");
        for(int i=0; i<3; i++){
            QRect crop(i*76,0,64,76);
            QPixmap ship = img.copy(crop);
            sprite.push_back(ship);
        }
    }
    else if(type == enemyType::special){
        QPixmap img(":/img/se");
        for(int i=0; i<3; i++){
            QRect crop(0,i*128,256,128);
            QPixmap ship = img.copy(crop);
            sprite.push_back(ship);
        }
    }
    else if(type == enemyType::final){
        QPixmap img(":/img/final");
        for(int i=0; i<4; i++){
            QRect crop(0,i*512,1024,512);
            QPixmap ship = img.copy(crop);
            sprite.push_back(ship);
        }
    }
    setSprite(rand()%sprite.size());
    updateTimer->start(200);
    connect(updateTimer, &QTimer::timeout, this, &enemyModel::changeSprite);
}

void enemyModel::setSprite(unsigned int i){
    setPixmap(sprite[i].scaled(width,height));
}

void enemyModel::setHit(bool b){hit = b;}

bool enemyModel::getHit() const {return hit;}

void enemyModel::changeSprite(){
    spriteSel++;
    spriteSel%=3;
    setSprite(spriteSel);
}

unsigned int enemyModel::getHeight() const{return height;}

enemyType enemyModel::getType() const {return type;}

unsigned int enemyModel::getWidth() const{return width;}

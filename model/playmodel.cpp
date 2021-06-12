#include "model/playmodel.h"
#include "model/vettore.h"
#include <QDebug>

playModel::playModel(): enemies(), p(new player()){}

vettore<deep_ptr<spaceship>> playModel::FirstWave(unsigned int screen_w){
    vettore<deep_ptr<spaceship>> aux;
    for(int i=0; i<24; i++){
        spaceship* ptr = new enemy();
        ptr->setX((screen_w/16-(ptr->getSpaceshipWidth()/2) + i*screen_w/8)%screen_w);
        ptr->setRow(i/8);
        ptr->setY(-(ptr->getSpaceshipHeight()+ptr->getRow()*ptr->getSpaceshipHeight()*2));
        aux.push_back(ptr);
    }
    return aux;
}

void playModel::setWave(const vettore<deep_ptr<spaceship>>& v){enemies = v;}

unsigned int playModel::enemySize() const{return enemies.size();}

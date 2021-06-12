#include "model/playmodel.h"
#include "model/vettore.h"
#include <QDebug>

playModel::playModel(): enemies(), p(new player()){}

void playModel::FirstWave(unsigned int screen_w){
    vettore<deep_ptr<spaceship>> aux;
    for(int i=0; i<24; i++){
        spaceship* ptr = new enemy();
        ptr->setX((screen_w/16-(ptr->getSpaceshipWidth()/2) + i*screen_w/8)%screen_w);
        ptr->setRow(i/8);
        ptr->setY(-(ptr->getSpaceshipHeight()+ptr->getRow()*ptr->getSpaceshipHeight()*2));
        aux.push_back(ptr);
    }
    enemies = aux;
}



void playModel::updateEnemyPosition(){
    for(vettore<deep_ptr<spaceship>>::iterator it = enemies.begin(); it!=enemies.end();it++)
        (*it)->setY((*it)->getY()+16);
};

unsigned int playModel::enemySize() const{return enemies.size();}

#include "model/playmodel.h"
#include "model/vettore.h"
#include <QDebug>

playModel::playModel(unsigned int w, unsigned int h): enemies(), p(new player()), screen_w(w), screen_h(h){
    p->setX(screen_w/2-32);
    p->setY(screen_h-96);
}

void playModel::FirstWave(){
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
    qDebug()<<"New pos: "<<enemies[0]->getY();
};

unsigned int playModel::enemySize() const{return enemies.size();}

unsigned int playModel::getScreenW()const{return screen_w;}

unsigned int playModel::getScreenH()const{return screen_h;}

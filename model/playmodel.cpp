#include "model/playmodel.h"
#include "model/vettore.h"

unsigned int playModel::screen_w = 1920;
unsigned int playModel::screen_h = 1080;

playModel::playModel(): enemies(), p(new player){
    p->updatePosition(screen_w/2-32,screen_h-96);
}

void playModel::FirstWave(){
    for(int i=0; i<24; i++){
        spaceship* ptr = new enemy();
        int x = (screen_w/16-(ptr->getSpaceshipWidth()/2) + i*screen_w/8)%screen_w;
        static_cast<enemy*>(ptr)->setRow(i/8);
        int y = -(ptr->getSpaceshipHeight()+static_cast<enemy*>(ptr)->getRow()*ptr->getSpaceshipHeight()*2);
        ptr->updatePosition(x, y);
        enemies.push_back(ptr);
    }
}

void playModel::SecondWave(){
    for(int i=0; i<8; i++){
        spaceship* ptr = new enemy();
        int x = (screen_w/16-(ptr->getSpaceshipWidth()/2) + i*screen_w/8)%screen_w;
        static_cast<enemy*>(ptr)->setRow(0);
        int y = -(ptr->getSpaceshipHeight()+static_cast<enemy*>(ptr)->getRow()*ptr->getSpaceshipHeight()*2);
        ptr->updatePosition(x, y);
        enemies.push_back(ptr);
    }
    for(int i=0; i<3; i++){
        spaceship* ptr = new specialEnemy();
        int x =(screen_w/6-(ptr->getSpaceshipWidth()/2) + i*screen_w/3)%screen_w;
        static_cast<enemy*>(ptr)->setRow(1);
        int y = -(ptr->getSpaceshipHeight()+static_cast<specialEnemy*>(ptr)->getRow()*ptr->getSpaceshipHeight());
        ptr->updatePosition(x,y);
        enemies.push_back(ptr);
    }
}

void playModel::FinalWave()
{
    spaceship* ptr = new finalEnemy();
    int x = screen_w/2 - ptr->getSpaceshipWidth()/2;
    int y = -ptr->getSpaceshipHeight();
    ptr->updatePosition(x,y);
    enemies.push_back(ptr);
}

void playModel::updateEnemyPosition(){
    for(vettore<deep_ptr<spaceship>>::iterator it = enemies.begin(); it!=enemies.end();it++)
        (*it)->updatePosition();
}

void playModel::healPlayer() {p->heal();}

void playModel::shieldCooldown()
{
    for(auto it = enemies.begin(); it!= enemies.end(); it++){
        if(typeid (finalEnemy) == typeid (**it))
            static_cast<finalEnemy*>(it->get())->refillShield();
    }
};

unsigned int playModel::enemySize() const{return enemies.size();}

unsigned int playModel::getScreenW()const{return screen_w;}

unsigned int playModel::getScreenH()const{return screen_h;}

vettore<deep_ptr<spaceship>>& playModel::getVettore() {return enemies;}

const vettore<deep_ptr<spaceship>>& playModel::getVettore() const {return enemies;}

int playModel::getEnemyHealth(vettore<deep_ptr<spaceship>>::iterator it) const {return (*it)->getHP();}

void playModel::damageEnemy(vettore<deep_ptr<spaceship>>::iterator it) {
    if(typeid (**it) == typeid (finalEnemy)){
        finalEnemy* ptr = static_cast<finalEnemy*>(it->get());
        if(ptr->getShield()>0)
            ptr->decreaseShield(p->getDmg());
        else
            ptr->decreaseHP(p->getDmg());
    }
    else
        (*it)->decreaseHP(p->getDmg());
}

void playModel::damagePlayer(unsigned int i) {p->decreaseHP(i);}

void playModel::movePlayer(int x, int y){p->updatePosition(x,y);}

void playModel::removeEnemy(unsigned int i) { enemies.erase(i);}

bool playModel::enemiesCleared() const {return enemies.size()==0;}

bool playModel::playerDead() const {return p->getHP()<=0;}

spaceship* playModel::getEnemy(unsigned int i) {return enemies[i].get();}

player* playModel::getPlayerPtr() {return p.get();}



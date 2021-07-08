#include "finalenemy.h"

finalEnemy::finalEnemy(unsigned int h, unsigned int d): specialEnemy(h,d,false), maxShield(getMaxHP()/3), shield(maxShield){}

finalEnemy::finalEnemy(const finalEnemy & fe): specialEnemy(fe), maxShield(fe.maxShield), shield(fe.maxShield){}

const int &finalEnemy::getShield() const {return shield;}

void finalEnemy::decreaseShield(unsigned int i) {shield-=i;}

unsigned int &finalEnemy::getSpaceshipWidth() const {return width;}

unsigned int &finalEnemy::getSpaceshipHeight() const {return height;}

unsigned int finalEnemy::width = 512;
unsigned int finalEnemy::height = 256;

//void finalEnemy::refillShield() {shield=maxShield;}

#include "finalenemy.h"

finalEnemy::finalEnemy(unsigned int h, unsigned int d, unsigned int s): specialEnemy(h,d,false), maxShield(s), shield(maxShield){}

finalEnemy::finalEnemy(const finalEnemy & fe): specialEnemy(fe), maxShield(fe.maxShield), shield(fe.maxShield){}

finalEnemy *finalEnemy::clone() const {return new finalEnemy(*this);}

const int &finalEnemy::getShield() const {return shield;}

void finalEnemy::decreaseShield(unsigned int i) {shield-=i;}

unsigned int &finalEnemy::getSpaceshipWidth() const {return width;}

unsigned int &finalEnemy::getSpaceshipHeight() const {return height;}

void finalEnemy::updatePosition(int x, int y)
{
    unsigned int r =rand()%5;
    unsigned int step = rand()%4 +1;
    setX(getX() + ((r==2) ? 0 : (r<2 ? step : -step)) + x);
    setY(getY() + (y ? y : 1));
}

unsigned int finalEnemy::width = 512;
unsigned int finalEnemy::height = 256;

void finalEnemy::refillShield() {shield=maxShield;}

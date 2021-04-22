#include "spaceship.h"

//costruttori
spaceship::spaceship(double h, const bullet* b): maxHP(h), hpLeft(maxHP), bult(new bullet(*b)) {}

spaceship::spaceship(const spaceship& s): maxHP(s.maxHP), hpLeft(s.hpLeft), bult(new bullet(*s.bult)) {}

spaceship::~spaceship() =default;

//static field
double spaceship::hpRecovery = 100;

//metodi
void spaceship::heal(){
    hpLeft+=hpRecovery;
    if(hpLeft>maxHP)
        hpLeft=maxHP;
}

void spaceship::decreaseHP(const bullet* b) {maxHP -= b->getDmg();}

double spaceship::getMaxHP() const{return maxHP;}

double spaceship::getHP() const{return hpLeft;}

const bullet* spaceship::getBull() const{return bult;}

void spaceship::changeGun(const bullet* b){bult=b;}

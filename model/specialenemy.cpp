#include "specialenemy.h"

specialEnemy::specialEnemy(unsigned int h, unsigned int d, bool dWd): divideWhenDead(dWd), superGun(!dWd) {
    if(!divideWhenDead)
        setDmg(4);
}

bool specialEnemy::divides() const {return divideWhenDead;}

unsigned int &specialEnemy::getSpaceshipWidth() const {return width;}

unsigned int &specialEnemy::getSpaceshipHeight() const {return height;}

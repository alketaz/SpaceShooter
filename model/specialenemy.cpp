#include "model/specialenemy.h"

specialEnemy::specialEnemy(unsigned int h, unsigned int d, bool dWd): enemy(h,d), divideWhenDead(dWd), superGun(!dWd) {
    if(!divideWhenDead)
        setDmg(d*2);
}

specialEnemy::specialEnemy(const specialEnemy& se):enemy(se), divideWhenDead(se.divideWhenDead), superGun(se.superGun){}

unsigned int specialEnemy::width = 256;

unsigned int specialEnemy::height = 128;

bool specialEnemy::divides() const {return divideWhenDead;}

unsigned int &specialEnemy::getSpaceshipWidth() const {return width;}

unsigned int &specialEnemy::getSpaceshipHeight() const {return height;}

specialEnemy *specialEnemy::clone() const
{
    return new specialEnemy(*this);
}

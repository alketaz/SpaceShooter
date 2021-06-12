#ifndef SPECIALENEMY_H
#define SPECIALENEMY_H

#include "model/enemy.h"

class specialEnemy : public enemy
{
private:
    bool divideWhenDead;
    bool superGun;
public:
    specialEnemy(bool =true);
};

#endif // SPECIALENEMY_H

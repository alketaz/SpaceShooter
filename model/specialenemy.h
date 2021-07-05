#ifndef SPECIALENEMY_H
#define SPECIALENEMY_H

#include "model/enemy.h"

class specialEnemy : public enemy
{
private:
    bool divideWhenDead, superGun;
    static unsigned int width, height;

public:
    specialEnemy(unsigned int =8, unsigned int =2, bool =true);
    specialEnemy(const specialEnemy&);

    bool divides() const;

    unsigned int& getSpaceshipWidth() const;
    unsigned int& getSpaceshipHeight() const;

    specialEnemy* clone() const;

};

#endif // SPECIALENEMY_H

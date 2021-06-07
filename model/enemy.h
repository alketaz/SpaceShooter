#ifndef ENEMY_H
#define ENEMY_H

#include "spaceship.h"

class enemy: public spaceship{
private:

public:
    enemy(unsigned int w =64, unsigned int h =64, int xPos =-99999, int yPos =-99999);
};

#endif // ENEMY_H

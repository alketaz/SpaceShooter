#ifndef ENEMY_H
#define ENEMY_H

#include "spaceship.h"

class enemy: public spaceship{  
public:
    enemy(unsigned int =3, unsigned int =1);
};

#endif // ENEMY_H

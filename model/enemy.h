#ifndef ENEMY_H
#define ENEMY_H

#include "spaceship.h"

class enemy: public spaceship{  
private:
    unsigned int row;

public:
    enemy(unsigned int =3, unsigned int =1);
    enemy(const enemy&);
    virtual void setRow(unsigned int);
    virtual const unsigned int& getRow() const;
    enemy* clone() const;
};

#endif // ENEMY_H

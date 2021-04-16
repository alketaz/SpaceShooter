#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "bullet.h"

class spaceship{
private:
    double hp;
    bullet* bult;
public:
    spaceship(double =100, const bullet* =new bullet());

    spaceship(const spaceship&);

    virtual ~spaceship() =0;

    void decreaseHP(const bullet*);

};

/*spaceship::~spaceship() =default;*/

#endif // SPACESHIP_H

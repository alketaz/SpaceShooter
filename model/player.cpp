#include "player.h"
#include <iostream>

player::player(unsigned int mhp, unsigned int mS): spaceship(mhp, 2), maxSpecial(mS), specialLeft(maxSpecial){}

player::player(const player& p): spaceship(p.getMaxHP(), p.getDmg()), maxSpecial(p.maxSpecial), specialLeft(maxSpecial){}

void player::heal(){setHP(getMaxHP());}

unsigned int player::getSpecial() const{return specialLeft;}

player *player::clone() const
{
    return new player(*this);
}

void player::updatePosition(int x, int y)
{
    setX(getX()+x);
    setY(getY()+y);
    if(getX()>1920 - getSpaceshipWidth())
        setX(1920 - getSpaceshipWidth());

    if(getX()<0)
        setX(0);

    if(getY()>1080 - getSpaceshipHeight())
        setY(1080 - getSpaceshipHeight());

    if(getY()<0)
        setY(0);
}

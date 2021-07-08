#include "player.h"
#include <iostream>

//costruttori
player::player(unsigned int mhp, unsigned int mS): spaceship(mhp, 2), maxSpecial(mS), specialLeft(maxSpecial){}

player::player(const player& p): spaceship(p.getMaxHP(), p.getDmg()), maxSpecial(p.maxSpecial), specialLeft(maxSpecial){}


//metodi
void player::useSpecial(){
    if(specialLeft>0)
        specialLeft--;
    else
        throw std::exception(); //Rimpiazzare eccezione
}

void player::heal(){const_cast<int&>(getHP())=getMaxHP();}

/*void player::addSpecial(){
    if(specialLeft<maxSpecial)
        specialLeft++;
    else
        throw std::exception(); //Rimpiazzare eccezione
}*/

unsigned int player::getSpecial() const{return specialLeft;}

player *player::clone() const
{
    return new player(*this);
}

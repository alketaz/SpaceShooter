#include "player.h"
#include <iostream>

//static fields
unsigned int player::maxLives = 3;

//costruttori
player::player(double mhp, const bullet* b, unsigned int mS): spaceship(mhp, b), maxSpecial(mS), specialLeft(maxSpecial), livesLeft(maxLives){}

player::player(const player& p): spaceship(p.getMaxHP(), p.getBull()), maxSpecial(p.maxSpecial), specialLeft(maxSpecial), livesLeft(maxLives){}

//metodi
void player::useSpecial(){
    if(specialLeft>0)
        specialLeft--;
    else
        throw std::exception(); //Rimpiazzare eccezione
}

void player::addSpecial(){
    if(specialLeft<maxSpecial)
        specialLeft++;
    else
        throw std::exception(); //Rimpiazzare eccezione
}

unsigned int player::getSpecial() const{return specialLeft;}

unsigned int player::getLives() const{return livesLeft;}

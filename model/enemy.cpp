#include "enemy.h"

enemy::enemy(unsigned int h, unsigned int d): spaceship(h, d), row(0) {}

enemy::enemy(const enemy& e):spaceship(e), row(e.row){}

void enemy::setRow(unsigned int i){row = i;}

const unsigned int& enemy::getRow() const{return row;}

enemy *enemy::clone() const {return new enemy(*this);}

void enemy::updatePosition(int x, int y){
    setX(getX() + x);
    setY(getY() + (y ? y : 1));
}

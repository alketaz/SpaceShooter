#include "spaceship.h"
#include <QDebug>

//costruttori
spaceship::spaceship(unsigned int h, unsigned int d): maxHP(h), hpLeft(h), dmg(d), row(0), x(0), y(0) {}

spaceship::spaceship(const spaceship& s): maxHP(s.maxHP), hpLeft(s.hpLeft), dmg(s.dmg), row(0), x(s.x), y(s.y) {}

//static fields
unsigned int spaceship::hpRecovery = 2;
unsigned int spaceship::width = 64;
unsigned int spaceship::height = 64;

//metodi
void spaceship::setX(int i){x = i;}

const int& spaceship::getX() const{return x;}

void spaceship::setY(int i){y = i;}

const int& spaceship::getY() const{return y;}

void spaceship::setRow(unsigned int i){row = i;}

const unsigned int& spaceship::getRow() const{return row;}


unsigned int& spaceship::getSpaceshipWidth() const{return width;}

unsigned int& spaceship::getSpaceshipHeight() const{return height;}

void spaceship::decreaseHP(unsigned int i) {hpLeft -= i;}

const unsigned int& spaceship::getMaxHP() const{return maxHP;}

const unsigned int& spaceship::getHP() const{return hpLeft;}

void spaceship::setDmg(unsigned int d) {dmg=d;}

unsigned int spaceship::getDmg() const{return dmg;}

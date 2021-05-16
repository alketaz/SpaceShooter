#include "bullet.h"

bullet::bullet(double d): dmg(d){}

bullet::bullet(const bullet& b): dmg(b.dmg) {}

double bullet::getDmg() const{return dmg;}

#include "spaceship.h"

spaceship::spaceship(double h, const bullet* b): hp(h), bult(new bullet(*b)) {}

spaceship::spaceship(const spaceship& s): hp(s.hp), bult(new bullet(*s.bult)) {}

spaceship::~spaceship() =default;

void spaceship::decreaseHP(const bullet* b) {hp-=b->getDmg();}

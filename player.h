#ifndef PLAYER_H
#define PLAYER_H
#include "spaceship.h"
class player: public spaceship{
private:
    static double maxHp;
    unsigned int maxSpecial;
    unsigned int special;
    unsigned int maxLives;
    unsigned int livesLeft;
public:
    player(double, const bullet*, unsigned int);
    void heal();
    void changeGun(const bullet*);
    void useSpecial();
    void addSpecial();
};

#endif // PLAYER_H

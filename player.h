#ifndef PLAYER_H
#define PLAYER_H
#include "spaceship.h"
class player: public spaceship{
private:
    unsigned int maxSpecial;
    static unsigned int maxLives;
    double lifeLeft;
    unsigned int specialLeft;
    unsigned int livesLeft;
public:
    player(double, const bullet*, unsigned int);
    void heal();
    void changeGun(const bullet*);
    void useSpecial();
    void addSpecial();
    unsigned int getSpecial() const;
    unsigned int getLives()const;
    double getLife() const;
};

#endif // PLAYER_H

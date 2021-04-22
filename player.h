#ifndef PLAYER_H
#define PLAYER_H
#include "spaceship.h"
class player: public spaceship{
private:
    unsigned int maxSpecial;
    static unsigned int maxLives;
    unsigned int specialLeft;
    unsigned int livesLeft;
public:
    player(double =500, const bullet* =new bullet(), unsigned int =3);
    player(const player &);

    void useSpecial();
    void addSpecial();
    unsigned int getSpecial() const;
    unsigned int getLives()const;

};

#endif // PLAYER_H

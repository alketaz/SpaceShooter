#ifndef PLAYER_H
#define PLAYER_H
#include "spaceship.h"
class player: public spaceship{
private:
    unsigned int maxSpecial;
    unsigned int specialLeft;

public:
    player(unsigned int =10, unsigned int =3);
    player(const player &);
    ~player() =default;
    player& operator=(const player&);

    void heal();
    void useSpecial();
    //void addSpecial();
    unsigned int getSpecial() const;
};

#endif // PLAYER_H

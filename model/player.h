#ifndef PLAYER_H
#define PLAYER_H
#include "spaceship.h"
class player: public spaceship{
private:
    unsigned int maxSpecial, specialLeft;
    static unsigned int hpRecovery;

public:
    player(unsigned int =14, unsigned int =2);
    player(const player &);
    ~player() =default;
    player& operator=(const player&);

    void heal();
    void useSpecial();
    //void addSpecial();
    unsigned int getSpecial() const;
    player* clone() const;
};

#endif // PLAYER_H

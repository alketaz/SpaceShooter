#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "bullet.h"

class spaceship{
private:
    double maxHP;
    double hpLeft;
    /*const bullet* bult;*/
    static double hpRecovery;
    unsigned int width, height;
    int x, y;
public:
    spaceship(double =100, const bullet* =new bullet());
    spaceship(const spaceship&);
    virtual ~spaceship() =0;
    //metodi
    void heal();
    void decreaseHP(const bullet*);
    double getMaxHP() const;
    double getHP() const;
    const bullet* getBull() const;
    void changeGun(const bullet*);
};

#endif // SPACESHIP_H

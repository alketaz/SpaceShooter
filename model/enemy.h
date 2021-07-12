#ifndef ENEMY_H
#define ENEMY_H

#include "spaceship.h"

class enemy: public spaceship{  
private:
    unsigned int row;

public:
    enemy(unsigned int =4, unsigned int =1);
    enemy(const enemy&);
    void setRow(unsigned int);
    const unsigned int& getRow() const;
    enemy* clone() const override;
    void updatePosition(int =0, int =0) override;
};

#endif // ENEMY_H

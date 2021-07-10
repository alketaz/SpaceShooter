#ifndef FINALENEMY_H
#define FINALENEMY_H

#include "specialenemy.h"
#include <QObject>

class finalEnemy : public specialEnemy
{
private:
    unsigned int maxShield;
    int shield;
    static unsigned int width, height;

public:
    finalEnemy(unsigned int =14, unsigned int =2, unsigned int =14);
    finalEnemy(const finalEnemy&);
    finalEnemy* clone() const;

    const int& getShield() const;
    void decreaseShield(unsigned int);
    void refillShield();

    unsigned int& getSpaceshipWidth() const;
    unsigned int& getSpaceshipHeight() const;

};

#endif // FINALENEMY_H

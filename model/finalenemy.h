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
    finalEnemy(unsigned int =42, unsigned int =4);
    finalEnemy(const finalEnemy&);


    const int& getShield() const;
    void decreaseShield(unsigned int);

    unsigned int& getSpaceshipWidth() const;
    unsigned int& getSpaceshipHeight() const;

/*public slots:
    void refillShield();*/
};

#endif // FINALENEMY_H

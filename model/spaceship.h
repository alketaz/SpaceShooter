#ifndef SPACESHIP_H
#define SPACESHIP_H


class spaceship{
private:
    unsigned int maxHP, hpLeft, dmg, row;
    static unsigned int width, height;
    int x, y;

public:
    static double hpRecovery;

    spaceship(unsigned int, unsigned int);
    spaceship(const spaceship&);
    virtual ~spaceship() =default;

    //metodi
    virtual unsigned int getSpaceshipWidth();
    virtual unsigned int getSpaceshipHeight();
    void setX(int);
    virtual const int& getX() const;
    void setY(int);
    virtual const int& getY() const;
    void setRow(unsigned int);
    const unsigned int& getRow() const;
    void decreaseHP(unsigned int);
    const unsigned int& getMaxHP() const;
    const unsigned int& getHP() const;
    virtual unsigned int getDmg() const;
};

#endif // SPACESHIP_H

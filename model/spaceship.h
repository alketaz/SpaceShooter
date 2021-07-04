#ifndef SPACESHIP_H
#define SPACESHIP_H


class spaceship{
private:
    unsigned int maxHP, hpLeft, dmg, row;
    static unsigned int width, height, hpRecovery;
    int x, y;

public:

    spaceship(unsigned int, unsigned int);
    spaceship(const spaceship&);
    virtual ~spaceship() =default;

    //metodi
    virtual unsigned int& getSpaceshipWidth() const;
    virtual unsigned int& getSpaceshipHeight() const;
    void setX(int);
    const int& getX() const;
    void setY(int);
    const int& getY() const;
    //spostare in enemy
    virtual void setRow(unsigned int);
    virtual const unsigned int& getRow() const;
    //
    void decreaseHP(unsigned int);
    unsigned int& getMaxHP() const;
    unsigned int& getHP() const;
    void setDmg(unsigned int);
    unsigned int getDmg() const;
};

#endif // SPACESHIP_H

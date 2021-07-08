#ifndef SPACESHIP_H
#define SPACESHIP_H


class spaceship{
private:
    unsigned int maxHP, dmg;
    static unsigned int width, height;
    int hpLeft, x, y;

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
    void decreaseHP(unsigned int);
    void setMaxHP(unsigned int);
    const unsigned int& getMaxHP() const;
    const int& getHP() const;
    void setDmg(unsigned int);
    unsigned int getDmg() const;
    virtual spaceship* clone() const =0;
};

#endif // SPACESHIP_H

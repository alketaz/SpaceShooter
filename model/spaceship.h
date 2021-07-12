#ifndef SPACESHIP_H
#define SPACESHIP_H


class spaceship{
private:
    unsigned int maxHP, dmg;
    static unsigned int width, height;
    int hpLeft, x, y;

protected:
    void setX(int);
    void setY(int);
    void setDmg(unsigned int);
    void setHP(int);

public:
    spaceship(unsigned int, unsigned int);
    spaceship(const spaceship&);
    virtual ~spaceship() =default;

    const int& getX() const;
    const int& getY() const;
    void decreaseHP(unsigned int);
    void setMaxHP(unsigned int);
    const unsigned int& getMaxHP() const;
    const int& getHP() const;
    const unsigned int& getDmg() const;

    virtual void updatePosition(int =0, int =0) =0;
    virtual spaceship* clone() const =0;
    virtual unsigned int& getSpaceshipWidth() const;
    virtual unsigned int& getSpaceshipHeight() const;
};

#endif // SPACESHIP_H

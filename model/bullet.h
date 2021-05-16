#ifndef BULLET_H
#define BULLET_H

class bullet{
private:
    double dmg;
public:
    bullet(double d =50);
    bullet(const bullet&);
    double getDmg() const;
};

#endif // BULLET_H

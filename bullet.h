#ifndef BULLET_H
#define BULLET_H

class bullet{
private:
    double dmg;
public:
    bullet();
    bullet(const bullet&);
    double getDmg() const;
};

#endif // BULLET_H

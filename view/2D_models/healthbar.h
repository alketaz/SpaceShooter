#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <QGraphicsPixmapItem>
#include "view/2D_models/playermodel.h"
#include "model/spaceship.h"

class healthBar : public QGraphicsPixmapItem
{
private:
    std::vector<QPixmap> progress;
    unsigned int spriteSel;
    void setSprite(unsigned int =0);
public:
    healthBar();
public slots:
    void updateHealth(unsigned int);
    void restoreHealth();
};

#endif // HEALTHBAR_H

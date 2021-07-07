#ifndef PLAYERMODEL_H
#define PLAYERMODEL_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "view/2D_models/bulletmodel.h"

class playerModel : public QObject, public QGraphicsPixmapItem
{
private:
    QTimer* updateTimer;
    unsigned int spriteSel, width, height;
    std::vector<QPixmap> sprite;
    void setSprite(unsigned int =0);
    unsigned int dmg;
    bool hit;

public:
    playerModel();
    //void keyPressEvent(QKeyEvent* event);
    unsigned int getWidth() const;
    unsigned int getHeight() const;
    void setHit(bool);
    bool getHit() const;
    void setDmg(unsigned int);
    bool getDmg() const;

public slots:
    void changeSprite();
};

#endif // PLAYERMODEL_H

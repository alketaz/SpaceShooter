#ifndef PLAYERMODEL_H
#define PLAYERMODEL_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "bulletmodel.h"

class playerModel : public QObject, public QGraphicsPixmapItem
{
private:
    QTimer* updateTimer;
    unsigned int spriteSel;
    std::vector<QPixmap> sprite;
    void setSprite(unsigned int =0);
public:
    playerModel();
    void keyPressEvent(QKeyEvent* event);

public slots:
    void changeSprite();
};

#endif // PLAYERMODEL_H

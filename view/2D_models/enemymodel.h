#ifndef ENEMYMODEL_H
#define ENEMYMODEL_H

#include <QGraphicsPixmapItem>
#include <QTimer>
#include "model/enumClasses.h"

class enemyModel : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    enemyType type;
    unsigned int width, height;
    QTimer* updateTimer;
    unsigned int spriteSel;
    std::vector<QPixmap> sprite;
    void setSprite(unsigned int =0);
    bool hit;

public:
    enemyModel(enemyType);
    void setHit(bool);
    bool getHit() const;
    unsigned int getWidth() const;
    unsigned int getHeight() const;
    enemyType getType() const;

public slots:
    void changeSprite();
};

#endif // ENEMYMODEL_H

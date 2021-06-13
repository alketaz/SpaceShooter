#ifndef ENEMYMODEL_H
#define ENEMYMODEL_H

#include <QGraphicsPixmapItem>
#include <QTimer>

class enemyModel : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    //QTimer* timer;
    QTimer* updateTimer;
    unsigned int spriteSel;
    std::vector<QPixmap> sprite;
    void setSprite(unsigned int =0);

public:
    enemyModel();

signals:
    void itemMoved();

public slots:
    //void move();
    void changeSprite();
};

#endif // ENEMYMODEL_H

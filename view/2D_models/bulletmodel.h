#ifndef BULLETMODEL_H
#define BULLETMODEL_H

#include <QGraphicsRectItem>
#include <QTimer>
#include <QGraphicsScene>
#include "enemymodel.h"

class bulletModel : public QObject, public QGraphicsRectItem
{
private:
    QTimer* timer;
public:
    bulletModel();

public slots:
    void move();
};

#endif // BULLETMODEL_H

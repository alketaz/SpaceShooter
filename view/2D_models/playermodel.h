#ifndef PLAYERMODEL_H
#define PLAYERMODEL_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include "bulletmodel.h"

class playerModel : public QGraphicsRectItem
{
public:
    playerModel();
    void keyPressEvent(QKeyEvent* event);
};

#endif // PLAYERMODEL_H

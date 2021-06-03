#ifndef BULLETMODEL_H
#define BULLETMODEL_H

#include <QGraphicsRectItem>
#include <QTimer>

class bulletModel : public QGraphicsRectItem, public QObject
{
private:
    QTimer* timer;
public:
    bulletModel();

public slots:
    void move();
};

#endif // BULLETMODEL_H

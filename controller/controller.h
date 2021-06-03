#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "view/viewSelector.h"
#include <QGraphicsScene>

class controller : public QObject
{
    Q_OBJECT
public:
    explicit controller(QObject *parent = nullptr);
    virtual QGraphicsScene* getScene() const =0;

signals:
    void sceneRequest(viewSelector v);
};

#endif // CONTROLLER_H

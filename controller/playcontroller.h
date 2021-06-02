#ifndef PLAYCONTROLLER_H
#define PLAYCONTROLLER_H
#include <QObject>
#include "controller.h"
#include "view/gamescene.h"

class playcontroller: public controller
{
    Q_OBJECT;
private:
    gameScene* scene;
public:
    playcontroller();
    QGraphicsScene* getScene() const;
};

#endif // PLAYCONTROLLER_H

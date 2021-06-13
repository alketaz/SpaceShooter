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
    playModel* model;
    QTimer* moveTimer;

signals:

public:
    playcontroller();
    QGraphicsScene* getScene() const;

public slots:
    void tick();
    //void checkCollisions();
    void checkPlayerActions();
    void checkForBullets();
};

#endif // PLAYCONTROLLER_H

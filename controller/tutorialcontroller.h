#ifndef TUTORIALCONTROLLER_H
#define TUTORIALCONTROLLER_H

#include "controller/controller.h"
#include "view/tutorialscene.h"
#include "view/viewSelector.h"
#include <QObject>

class tutorialcontroller : public controller
{
    Q_OBJECT
private:
    tutorialScene* scene;

public:
    tutorialcontroller();
    QGraphicsScene* getScene() const;
};

#endif // TUTORIALCONTROLLER_H

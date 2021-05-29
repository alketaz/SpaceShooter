#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H

#include "controller/controller.h"
#include "view/mainmenu.h"

class menucontroller : public controller
{
    Q_OBJECT
private:
    QGraphicsScene* scene;
public:
    explicit menucontroller();
    QGraphicsScene* getScene() const override;

};

#endif // MENUCONTROLLER_H

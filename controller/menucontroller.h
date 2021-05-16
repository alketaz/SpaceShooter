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
    explicit menucontroller(QObject *parent = nullptr);
    void setScene();
    QGraphicsScene* getScene() const;
signals:

};

#endif // MENUCONTROLLER_H

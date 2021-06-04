#include "view/2D_models/bulletmodel.h"

bulletModel::bulletModel(): timer(new QTimer())
{
    setRect(0,0,4,16);
    connect(timer, &QTimer::timeout, this, [=](){emit move();});
    timer->start(16);
}

void bulletModel::move(){
    QList<QGraphicsItem*> impact = collidingItems();
    for(int i=0, n=impact.size(); i<n; i++){
        if(typeid(*(impact[i]))==typeid(enemyModel)){
            scene()->removeItem(this);
            delete this;
        }
    }
    if(pos().y()<-16)
        delete this;
    else
        setPos(x(), y()-8);
}

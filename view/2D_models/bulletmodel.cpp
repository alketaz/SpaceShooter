#include "view/2D_models/bulletmodel.h"

bulletModel::bulletModel(): timer(new QTimer())
{
    setRect(0,0,4,16);
    connect(timer, &QTimer::timeout, this, [=](){emit move();});
    timer->start(16);
}

void bulletModel::move(){
    if(pos().y()<-16)
        delete this;
    else
        setPos(x(), y()-8);
}

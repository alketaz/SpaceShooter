#include "playermodel.h"

playerModel::playerModel()
{
    setRect(0,0,64,64);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

void playerModel::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Left){
        setPos(x()-80, y());
        if(pos().x()<=0)
            setPos(0, y());
    }
    else if(event->key() == Qt::Key_Right){
        setPos(x()+80, y());
        if(pos().x()+64>=scene()->width())
            setPos(scene()->width()-64, y());
    }
    else if(event->key() == Qt::Key_Down){
        setPos(x(), y()+80);
        if(pos().y()+64>=scene()->height())
            setPos(x(), scene()->height()-64);
    }
    else if(event->key() == Qt::Key_Up){
        setPos(x(), y()-80);
        if(pos().y()<=scene()->height()-256)
            setPos(x(), scene()->height()-256);
    }
    else if(event->key() == Qt::Key_Space){
        bulletModel* bullet = new bulletModel();
        bullet->setPos(x()+30,y()-16);
        scene()->addItem(bullet);
    }
}

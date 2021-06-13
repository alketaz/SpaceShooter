#include "playermodel.h"

playerModel::playerModel(): updateTimer(new QTimer()), sprite(0)
{
    QPixmap ship1(":/img/user1.png");
    QPixmap ship2(":/img/user2.png");
    QPixmap ship3(":/img/user3.png");
    sprite.push_back(ship1);
    sprite.push_back(ship2);
    sprite.push_back(ship3);
    setSprite();
    setFlag(QGraphicsItem::ItemIsFocusable);
    updateTimer->start(200);
    connect(updateTimer, &QTimer::timeout, this, &playerModel::changeSprite);
}

void playerModel::setSprite(unsigned int i){
    setPixmap(sprite[i].scaled(64,80));
}

/*void playerModel::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Left){
        setPos(x()-16, y());
        if(pos().x()<=0)
            setPos(0, y());
    }
    else if(event->key() == Qt::Key_Right){
        setPos(x()+16, y());
        if(pos().x()+64>=scene()->width())
            setPos(scene()->width()-64, y());
    }
    else if(event->key() == Qt::Key_Down){
        setPos(x(), y()+16);
        if(pos().y()+64>=scene()->height())
            setPos(x(), scene()->height()-64);
    }
    else if(event->key() == Qt::Key_Up){
        setPos(x(), y()-16);
        if(pos().y()<=scene()->height()-256)
            setPos(x(), scene()->height()-256);
    }
    else if(event->key() == Qt::Key_Space){
        bulletModel* bullet = new bulletModel();
        bullet->setPos(x()+30,y()-16);
        scene()->addItem(bullet);
    }
}*/

void playerModel::changeSprite(){
    spriteSel+=1;
    spriteSel%=3;
    setSprite(spriteSel);
}

void playerModel::keyPressEvent(QKeyEvent* event){
    if(event->key() == Qt::Key_Left){
        setPos(x()-16, y());
        if(pos().x()<=0)
            setPos(0, y());
    }
    else if(event->key() == Qt::Key_Right){
        setPos(x()+16, y());
        if(pos().x()+64>=scene()->width())
            setPos(scene()->width()-64, y());
    }
    else if(event->key() == Qt::Key_Down){
        setPos(x(), y()+16);
        if(pos().y()+64>=scene()->height())
            setPos(x(), scene()->height()-64);
    }
    else if(event->key() == Qt::Key_Up){
        setPos(x(), y()-16);
        if(pos().y()<=scene()->height()-256)
            setPos(x(), scene()->height()-256);
    }
    else if(event->key() == Qt::Key_Space){
        bulletModel* bullet = new bulletModel();
        bullet->setPos(x()+30,y()-16);
        scene()->addItem(bullet);
    }
}

#ifndef TITLEITEM_H
#define TITLEITEM_H

#include <QGraphicsPixmapItem>

class titleItem : public QGraphicsPixmapItem
{
public:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};

#endif // TITLEITEM_H

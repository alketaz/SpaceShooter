#ifndef MAINWINDOWVIEW_H
#define MAINWINDOWVIEW_H

#include <QGraphicsView>
#include "mainmenu.h"

class mainwindowview : public QGraphicsView
{
private:
    void resizeEvent(QResizeEvent*);
public:
    mainwindowview();
};

#endif // MAINWINDOWVIEW_H

#ifndef MAINMENU_H
#define MAINMENU_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPalette>
#include <QPushButton>
#include <QApplication>

class mainmenu : public QGraphicsScene
{
    Q_OBJECT
private:
    void loadBackground();
    void loadTitle();
    void loadButtons();

public:
    mainmenu();

signals:
    void onPlayPressed();
    void onTutorialPressed();
    void onOptionsPressed();
    void onExitPressed();
};

#endif // MAINMENU_H

#ifndef MAINMENU_H
#define MAINMENU_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPalette>
#include <QPushButton>

class mainmenu : public QGraphicsScene
{
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

#ifndef TUTORIALSCENE_H
#define TUTORIALSCENE_H

#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsTextItem>
#include <QPushButton>
#include <QColor>

class tutorialScene : public QGraphicsScene
{
    Q_OBJECT
private:
    void loadBG();
    void loadTitle();
    void loadText();
    void loadButtons();
    unsigned int page;

public:
    tutorialScene();

signals:
    void menuPressed();
};

#endif // TUTORIALSCENE_H

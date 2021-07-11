#include "mainmenu.h"

mainmenu::mainmenu()
{
    setSceneRect(0,0,1920,1080);
    itemsBoundingRect();
    loadBackground();
    loadTitle();
    loadButtons();
}

void mainmenu::loadBackground(){
    QPixmap bg(":/img/game_bg.png");
    //bg = bg.scaled(sceneRect().width(),sceneRect().height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    QBrush brush(bg);
    setBackgroundBrush(brush);
}

void mainmenu::loadTitle() {
    QImage image(":/img/title.png");
    QGraphicsPixmapItem* title = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    int w = image.width();
    int h = image.height();
    title->setPos((width()-w)/2, (height()-h)/4);
    addItem(title);
}

void mainmenu::loadButtons() {
    QPushButton* playbtn = new QPushButton("Gioca");
    playbtn->setGeometry(width()/2-90, height()/2, 180, 90);
    playbtn->setStyleSheet("QPushButton {color: orange;"
                           "font-size: 20px;"
                           "font-weight: bold;"
                           "background-color: rgba(0, 0, 0, 50);"
                           "border: 5px solid orange;"
                           "border-radius: 10px;"
                           "outline: none;"
                           "outline-radius: 10px;"
                           "opacity: 0.9;}"
                           "QPushButton:hover {"
                           "background-color: rgba(150, 150, 150, 50);}");
    addWidget(playbtn);

    QPushButton* tutorialbtn = new QPushButton("Tutorial");
    tutorialbtn->setGeometry(width()/2-90, height()/2+110, 180, 90);
    tutorialbtn->setStyleSheet("QPushButton {color: orange;"
                               "font-size: 20px;"
                               "font-weight: bold;"
                               "background-color: rgba(0, 0, 0, 50);"
                               "border: 5px solid orange;"
                               "border-radius: 10px;"
                               "outline: none;"
                               "outline-radius: 10px;"
                               "opacity: 0.9;}"
                               "QPushButton:hover {"
                               "background-color: rgba(150, 150, 150, 50);}");
    addWidget(tutorialbtn);

    QPushButton* exitbtn = new QPushButton("Esci");
    exitbtn->setGeometry(width()/2-90, height()/2+220, 180, 90);
    exitbtn->setStyleSheet("QPushButton {color: orange;"
                           "font-size: 20px;"
                           "font-weight: bold;"
                           "background-color: rgba(0, 0, 0, 50);"
                           "border: 5px solid orange;"
                           "border-radius: 10px;"
                           "outline: none;"
                           "outline-radius: 10px;"
                           "opacity: 0.9;}"
                           "QPushButton:hover {"
                           "background-color: rgba(150, 150, 150, 50);}");
    addWidget(exitbtn);

    connect(playbtn, &QPushButton::clicked, this, &mainmenu::onPlayPressed);
    connect(tutorialbtn, &QPushButton::clicked, this, &mainmenu::onTutorialPressed);
    connect(exitbtn, &QPushButton::clicked, this, &QApplication::exit);    //ulteriore schermata per uscire
}

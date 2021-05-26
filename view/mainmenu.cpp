#include "mainmenu.h"
#include <qapplication.h>

mainmenu::mainmenu()
{
    setSceneRect(0,0,1920,1080);
    loadBackground();
    loadTitle();
    loadButtons();
}

void mainmenu::loadBackground(){
    QPixmap bg(":/img/bg.jpg");
    bg = bg.scaled(1920,1080,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    QBrush brush(bg);
    setBackgroundBrush(brush);
}

void mainmenu::loadTitle() {
    QImage image(":/img/title.png");
    QGraphicsPixmapItem* title = new QGraphicsPixmapItem(QPixmap::fromImage(image));
    int w = image.width();
    int h = image.height();
    title->setPos((sceneRect().width()-w)/2, (sceneRect().height()-h)/4);
    addItem(title);
}

void mainmenu::loadButtons() {
    QPushButton* playbtn = new QPushButton("Gioca");
    playbtn->setGeometry(sceneRect().width()/2-60, sceneRect().height()/2, 120, 60);
    /*playbtn->setText("Gioca");*/
    playbtn->setStyleSheet("QPushButton {color: orange;"
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
    tutorialbtn->setGeometry(sceneRect().width()/2-60, sceneRect().height()/2+80, 120, 60);
    /*tutorialbtn->setText("Tutorial");*/
    tutorialbtn->setStyleSheet("QPushButton {color: orange;"
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

    QPushButton* optionbtn = new QPushButton("Opzioni");
    optionbtn->setGeometry(sceneRect().width()/2-60, sceneRect().height()/2+160, 120, 60);
    /*optionbtn->setText("Opzioni");*/
    optionbtn->setStyleSheet("QPushButton {color: orange;"
                           "font-weight: bold;"
                           "background-color: rgba(0, 0, 0, 50);"
                           "border: 5px solid orange;"
                           "border-radius: 10px;"
                           "outline: none;"
                           "outline-radius: 10px;"
                           "opacity: 0.9;}"
                           "QPushButton:hover {"
                           "background-color: rgba(150, 150, 150, 50);}");
    addWidget(optionbtn);

    QPushButton* exitbtn = new QPushButton("Esci");

    exitbtn->setGeometry(sceneRect().width()/2-60, sceneRect().height()/2+240, 120, 60);
    /*exitbtn->setText("Esci");*/
    exitbtn->setStyleSheet("QPushButton {color: orange;"
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

    /*connect(playbtn, &QPushButton::clicked, this, &mainmenu::onPlayPressed);
    connect(tutorialbtn, &QPushButton::clicked, this, &mainmenu::onTutorialPressed);
    connect(optionbtn, &QPushButton::clicked, this, &mainmenu::onOptionsPressed);*/
    connect(exitbtn, &QPushButton::clicked, this, &QApplication::exit);    //ulteriore schermata per uscire
}

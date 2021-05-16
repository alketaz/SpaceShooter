#include "mainwindow.h"
#include "mainwindowview.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), view(new mainwindowview())
{
    setWindowTitle("QSpaceShooter");

    QIcon icon(":/img/icon.png");
    setWindowIcon(icon);

    setMinimumSize(QSize(1280, 720));
    resize(QSize(1920,1080));
    mainmenu* menu = new mainmenu;
    view->setScene(menu);
    setCentralWidget(view);
}

MainWindow::~MainWindow()
{
    delete view;
}


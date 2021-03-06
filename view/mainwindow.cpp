#include "view/mainwindow.h"
#include "view/mainwindowview.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), view(new mainwindowview()), contr(new menucontroller())
{
    setWindowTitle("QSpaceShooter");

    QIcon icon(":/img/icon.png");
    setWindowIcon(icon);

    setMinimumSize(QSize(1024, 480));
    resize(QSize(1280,720));
    setCentralWidget(view);
    updateScene(viewSelector::mainMenu);
}

void MainWindow::updateScene(viewSelector v){
    if (contr)
        delete contr;
    switch (v) {
        default:
        case viewSelector::mainMenu:
            contr = new menucontroller();
        break;
        case viewSelector::playScene:
            contr = new playcontroller();
        break;
        case viewSelector::tutorialScene:
            contr = new tutorialcontroller();
        break;
    }

    connect(contr, &controller::sceneRequest, this, &MainWindow::updateScene);

    view->setScene(contr->getScene());
}

void MainWindow::closeEvent (QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question(this, "QSpaceShooter",
                                                               tr("Sicuro di volere uscire da QSpaceShooter?\n"),
                                                               QMessageBox::No | QMessageBox::Yes,
                                                               QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes)
        event->ignore();
    else
        event->accept();
}

MainWindow::~MainWindow()
{
    delete view;
}


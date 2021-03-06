#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include "mainwindowview.h"
#include "controller/controller.h"
#include "controller/menucontroller.h"
#include "controller/playcontroller.h"
#include "controller/tutorialcontroller.h"
#include "viewSelector.h"
#include <QCloseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void updateScene(viewSelector v);

private:
    mainwindowview* view;
    controller* contr;
    void closeEvent(QCloseEvent *event) override;
};
#endif // MAINWINDOW_H

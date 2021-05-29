#include "view/mainwindow.h"

#include <QApplication>
#include "model/vettore.h"
#include "model/player.h"
#include "model/deep_ptr.h"
#include "model/spaceship.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

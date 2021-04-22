#include "mainwindow.h"

#include <QApplication>
#include "vettore.h"
#include "player.h"

int main(int argc, char *argv[])
{
    vettore<player> v;
    vettore<player>::iterator it=v.begin();
    ++it;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

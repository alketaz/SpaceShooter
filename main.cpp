#include "mainwindow.h"

#include <QApplication>
#include "vettore.h"
#include "player.h"
#include "deep_ptr.h"
#include <iostream>

int main(int argc, char *argv[])
{
    player* p = new player();
    deep_ptr<player> dp(p);
    vettore<deep_ptr<player>> v;
    v.push_back(dp);

    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();*/
}

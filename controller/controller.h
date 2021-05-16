#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

class controller : public QObject
{
    Q_OBJECT
public:
    explicit controller(QObject *parent = nullptr);
    virtual void setScene() =0;

signals:

};

#endif // CONTROLLER_H

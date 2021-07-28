#ifndef BASEMANAGEER_H
#define BASEMANAGEER_H

#include <QObject>

class Basemanageer : public QObject
{
    Q_OBJECT
public:
    explicit Basemanageer(QObject *parent = nullptr);

signals:

};

#endif // BASEMANAGEER_H

#ifndef SALE_DATA_H
#define SALE_DATA_H

#include <QObject>

class Sale_Data : public QObject
{
    Q_OBJECT
public:
    explicit Sale_Data(QObject *parent = nullptr);

signals:

};

#endif // SALE_DATA_H

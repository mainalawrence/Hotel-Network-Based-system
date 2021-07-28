#ifndef LISTORDERDETAILS_H
#define LISTORDERDETAILS_H

#include <QObject>
#include<Data/orderdetails.h>
#include<QList>
#include<Pos_Lib_global.h>

namespace Models {
class POS_LIB_EXPORT ListOrderDetails:public QObject
{
    Q_OBJECT
public:
    ListOrderDetails();
    Q_INVOKABLE void populate(QString name,QString amount,QString cost,QString total,QString tax);

public:
    std::vector<Data::OrderDetails>m_data;
};
}
#endif // LISTORDERDETAILS_H

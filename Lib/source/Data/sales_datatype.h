#ifndef SALES_DATATYPE_H
#define SALES_DATATYPE_H
#include<QJsonValue>
#include<QObject>
#include<QString>
#include<Pos_Lib_global.h>

class POS_LIB_EXPORT Sales_DataType
{
public:
      Sales_DataType(QString Rno,QString totalcost,QString payment,QString Date,QString Servedby,QString Description);
    QString Rno;
    QString totalcost;
    QString payment;
    QString Date;
    QString Servedby;
    QString Description;
};

#endif // SALES_DATATYPE_H

#ifndef REPORTTABLEDELEGATE_H
#define REPORTTABLEDELEGATE_H

#include <QObject>
#include<Pos_Lib_global.h>
#include<Data/sales_datatype.h>
#include<QList>

namespace Delegate {
class POS_LIB_EXPORT ReportTableDelegate : public QObject
{
    Q_OBJECT
public:
    typedef QList<Sales_DataType> Sales;
    Sales m_Sales;
    explicit ReportTableDelegate(QObject *parent = nullptr);

signals:

private:


};
}


#endif // REPORTTABLEDELEGATE_H

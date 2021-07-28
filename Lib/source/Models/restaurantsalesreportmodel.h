#ifndef RESTAURANTSALESREPORTMODEL_H
#define RESTAURANTSALESREPORTMODEL_H

#include <QAbstractTableModel>
#include<Pos_Lib_global.h>

class sales;
namespace Models {
class POS_LIB_EXPORT RestaurantSalesReportmodel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit RestaurantSalesReportmodel(QObject *parent = nullptr);
    enum RoleName{
        ReceitNumber=0,
        Totalcost,
        PaymentType,
        SaleDate,
        UserName,
        Details

    };
    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
     QHash<int,QByteArray> roleNames() const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
   // QList<sales> mysale;

};
}
#endif // RESTAURANTSALESREPORTMODEL_H

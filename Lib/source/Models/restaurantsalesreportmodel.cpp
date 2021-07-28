#include "restaurantsalesreportmodel.h"

namespace Models {


RestaurantSalesReportmodel::RestaurantSalesReportmodel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

int RestaurantSalesReportmodel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int RestaurantSalesReportmodel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QHash<int, QByteArray> RestaurantSalesReportmodel::roleNames() const
{
    QHash<int,QByteArray>roles;
    roles.insert(ReceitNumber,"ReciteNo");
    roles.insert(Totalcost,"totalcost");
    roles.insert(PaymentType,"paytype");
    roles.insert(SaleDate,"salesdate");
    roles.insert(UserName,"soldby");
    roles.insert(Details,"Details");
    return roles;

}

QVariant RestaurantSalesReportmodel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
}

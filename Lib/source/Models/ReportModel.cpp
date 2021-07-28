#include "ReportModel.h"
#include<QtDebug>

namespace Models {
BarReportModel::BarReportModel(QObject *parent)
    : QAbstractTableModel(parent)
{

}

int BarReportModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return  mysale.size();
}

int BarReportModel::columnCount(const QModelIndex &parent) const
{
    if(parent.isValid()){
        return 0;
    }
    return roleNames().size();
}

QVariant BarReportModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    auto items=mysale.at(index.row());
    if (!index.isValid())
        return QVariant();
    switch (role) {
    case ReceitNumber:{
        return QVariant(items.Rno);
        break;
    }
    case Totalcost:{
        return QVariant(items.totalcost);
        break;
    }
    case PaymentType:{
        return QVariant(items.payment);
        break;
    }
    case SaleDate:{
        return QVariant(items.Date);
        break;
    }
    case UserName:{
        return QVariant(items.Servedby);
        break;
    }
    case Details:{
        return QVariant(items.Description);
        break;
    }
}
    return QVariant();
}

QHash<int, QByteArray> BarReportModel::roleNames() const
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

void BarReportModel::setSales(QList<Saless> &data)
{
    auto index=mysale.size();
    beginInsertRows(QModelIndex(), index, index );
    mysale.empty();
    mysale=data;
   endInsertRows();
}

}

#include "reporttablemodel.h"
#include<QtDebug>

namespace Models {
ReportTablemodel::ReportTablemodel(QObject *parent)
    : QAbstractTableModel(parent)
{

}


int ReportTablemodel::rowCount(const QModelIndex &parent) const
{
    (void)parent;
    if (parent.isValid())
        return 0;

    return m_LData->m_Sales.count();
}

int ReportTablemodel::columnCount(const QModelIndex &parent) const
{
    (void)parent;
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    return roleNames().count() ;
}

QVariant ReportTablemodel::data(const QModelIndex &index, int role) const
{
 Delegate::ReportTableDelegate del;

    QVariant val;
    if (!index.isValid())
        return QVariant();
    const int row=index.row();
    const int col=role;

    switch (col) {
    case ReceitNumber:{
        val=m_LData->m_Sales.at(row).Rno;
        break;
    }
    case Totalcost:{
        val=m_LData->m_Sales.at(row).totalcost;
        break;
    }
    case PaymentType:{
        val=m_LData->m_Sales.at(row).payment;
        break;
    }

    case SaleDate:{
        val=m_LData->m_Sales.at(row).Date;
        break;
    }
    case UserName:{
     val=m_LData->m_Sales.at(row).Servedby;
     break;
    }
    case Details:{
        val=m_LData->m_Sales.at(row).Description;
        break;
    }
    }
    return val;
}

QHash<int, QByteArray> ReportTablemodel::roleNames() const
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

}


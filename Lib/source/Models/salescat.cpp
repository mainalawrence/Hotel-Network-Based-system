#include "salescat.h"

using namespace Models;
SalesCat::SalesCat(QObject *parent)
    : QAbstractListModel(parent)
{
}

int SalesCat::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return  m_Ordersale.size();
}

QVariant SalesCat::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    auto col=role;
    auto row=m_Ordersale.at(index.row());
    switch (col) {
    case TablName:{
        return QVariant(row.TableName).toString();
        break;
    }
    case Totalcost:{
        return QVariant(row.TotalCost).toDouble();
        break;
    }

    case WaiterId:{
        return QVariant(row.WaiterId).toString();
        break;
    }
    case Amount:{
        return QVariant(row.Amount).toString();
        break;
    }
    case OrderList:{
        return  QVariant(row.OrderList).toByteArray();
        break;
    }
    case OrderNumber:{
        return QVariant(row.OrderNumber).toString();
        break;
    }
    case WaiterName:{
        return QVariant(row.WaiterName).toString();
        break;
    }
    }
    return QVariant();
}

bool SalesCat::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        auto col=role;
        auto row=m_Ordersale.at(index.row());
        switch (col) {
        case TablName:{
            row.TableName=value.toString();
            break;
        }
        case Totalcost:{
            row.TotalCost=value.toDouble();
            break;
        }
        case WaiterId:{
            row.WaiterId=value.toString();
            break;
        }
        case Amount:{
            row.Amount=value.toString();
            break;
        }
        case OrderList:{
            row.OrderList=value.toByteArray();
            break;
        }
        case OrderNumber:{
            row.OrderNumber=value.toString();
            break;
        }
        case WaiterName:{
            row.WaiterName=value.toString();
            break;
        }

        }
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

QHash<int, QByteArray> SalesCat::roleNames() const
{
    QHash<int, QByteArray>roles;
    roles.insert( TablName,"tablName");
    roles.insert( Totalcost,"totalCost");
    roles.insert( WaiterId,"waiterId");
    roles.insert( Amount,"amount");
    roles.insert( OrderList,"orderList");
    roles.insert( WaiterName,"WaiterName");
    roles.insert( OrderNumber,"orderNumber");
    return roles;
}

Qt::ItemFlags SalesCat::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

bool SalesCat::populate(QList<SalesC> &data)
{
    if(data.isEmpty()){
        return false;
    }
    else {
        auto index=m_Ordersale.size();
        if(!m_Ordersale.empty())
        {
            beginRemoveRows(QModelIndex(),index,index);
            m_Ordersale.clear();
            endRemoveRows();
        }
        if(m_Ordersale.empty())
        {
            m_counter=index;
            beginInsertRows(QModelIndex(),index,index);
            m_Ordersale=data;
            endInsertRows();
            return true;
        }
        return true;
    }

}

bool SalesCat::remove(int index)
{
    if(index>m_Ordersale.size()||index<0) return false;
    beginRemoveRows(QModelIndex(),index,index);
    m_Ordersale.removeAt(index);
    endRemoveRows();
    return true;
}

bool SalesCat::clear()
{
    m_Ordersale.empty();
    if(m_Ordersale.isEmpty()){
        return true;
        qDebug()<<"empty";
    }
    else {
        qDebug()<<"not empty";
    }

    return false;
}

int SalesCat::counter() const
{
    return m_counter;
}

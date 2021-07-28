#include "salesviewmodel.h"
#include<QDebug>

namespace Models {


SalesViewModel::SalesViewModel(QObject *parent)
    : QAbstractListModel(parent)
{
    removeitems();
}

SalesViewModel::~SalesViewModel()
{


}

int SalesViewModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    return m_orders.count();
}

QVariant SalesViewModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    auto column=role;
    auto row=m_orders.at(index.row());
    switch (column) {
    case Name:{
        return QVariant(row.Name).toString();
        break;
    }

    case Amount:{
        return QVariant(row.Amount).toString();
        break;
    }
    case Total:{
        return QVariant(row.Total).toDouble();
        break;
    }
    case Tnumber:{
        return QVariant(row.TableName).toString();
        break;
    }
    case Orderid:{
        return QVariant(row.orderid).toString();
        break;
    }
    }
    return QVariant();
}

void SalesViewModel::populate(QString Name, QString Amount,double Total,QString TName,QString id)
{ qDebug()<<"total: " <<Total;
    auto index=m_orders.count();
    beginInsertRows(QModelIndex(), index, index);
    m_orders.insert(0,{Name,Amount,Total,TName,id});
    endInsertRows();
    m_Totalcost=m_orders.at(0).Total;
    m_TableNumber=m_orders.at(0).TableName;
    m_WaiterName=m_orders.at(0).Name;
    m_Amount=m_orders.at(0).Amount;
    emit TotalcostChanged();
    emit TableNumberChanged();
    emit WaiterNameChanged();
    emit AmountChanged();
    qDebug()<<"totalL: " <<m_orders.at(0).Total;

}

void SalesViewModel::removeitems()
{
    auto index=m_orders.count();
    beginRemoveRows(QModelIndex(),index,index);
    m_orders.clear();
    endRemoveRows();
    beginRemoveRows(QModelIndex(), index, index);
    endRemoveRows();
    emit TotalcostChanged();
    emit TableNumberChanged();
    emit WaiterNameChanged();
    emit AmountChanged();

}
bool SalesViewModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        auto row=m_orders.at(index.row());
        switch (role) {
        case Name:{
            row.Name=value.toString();
            break;
        }

        case Amount:{
            row.Amount=value.toString();
            break;
        }
        case Total:{
            row.Total=value.toDouble();
            break;
        }
        case Tnumber:{
            row.TableName=value.toString();
            break;
        }
        case Orderid:{
            row.orderid=value.toString();
            break;
        }
        }
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags SalesViewModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

double SalesViewModel::Totalcost() const
{
    return m_Totalcost;
}

void SalesViewModel::setTotalcost(double Totalcost)
{
    m_Totalcost = Totalcost;
}

QString SalesViewModel::WaiterName() const
{
    return m_WaiterName;
}

void SalesViewModel::setWaiterName(const QString &WaiterName)
{
    m_WaiterName = WaiterName;
}

QString SalesViewModel::TableNumber() const
{
    return m_TableNumber;
}

void SalesViewModel::setTableNumber(const QString &TableNumber)
{
    m_TableNumber = TableNumber;
}

QString SalesViewModel::Amounts() const
{
    return m_Amount;
}

void SalesViewModel::setAmount(const QString &Amount)
{
    m_Amount = Amount;
}

QString SalesViewModel::orderid() const
{
    return m_orderid;
}

void SalesViewModel::setOrderid(const QString &orderid)
{
    m_orderid = orderid;
}


QHash<int, QByteArray> Models::SalesViewModel::roleNames() const
{QHash<int, QByteArray>Names;
    Names.insert(Name,"name");
    Names.insert(Amount,"amount");
    Names.insert(Total,"total");
    Names.insert(Tnumber,"tnumber");
    Names.insert(Orderid,"itemid");

    return Names;
}
}

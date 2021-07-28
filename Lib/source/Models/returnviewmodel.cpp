#include "returnviewmodel.h"


namespace Models {
ReturnViewModel::ReturnViewModel(QObject *parent)
    : QAbstractListModel(parent)
{

}

int ReturnViewModel::rowCount(const QModelIndex &parent) const
{

    if (parent.isValid())
        return 0;

    return m_orders.size();
}
bool ReturnViewModel::removefromCat(int index)
{

    beginRemoveRows(QModelIndex(), index, index);
    m_orders.removeAt(index);
    endRemoveRows();
    return true;
}
QVariant ReturnViewModel::data(const QModelIndex &index, int role) const
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
    case Cost:{
        return QVariant(row.cost).toDouble();
        break;
    }
    case Amount:{
        return QVariant(row.Amount).toInt();
        break;
    }
    case Total:{
        return QVariant(row.Total).toDouble();
        break;
    }
    case SumTotal:{
        return QVariant(row.SumTotal).toDouble();
        break;
    }
    }
    return QVariant();
}

bool ReturnViewModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        auto row=m_orders.at(index.row());
        switch (role) {
        case Name:{
            value.toString()=row.Name;
            break;
        }
        case Cost:{
            row.cost= value.toDouble();
            break;
        }
        case Amount:{
            row.Amount=value.toInt();
            break;
        }
        case Total:{
            row.Total=value.toDouble();
            break;
        }
        case SumTotal:{
            row.SumTotal=value.toDouble() ;
            break;
        }
        }
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags ReturnViewModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> ReturnViewModel::roleNames() const
{
    QHash<int, QByteArray>Names;
    Names.insert(Name,"name");
    Names.insert(Cost,"cost");
    Names.insert(Amount,"amount");
    Names.insert(Total,"total");
    Names.insert(SumTotal,"totolsum");
    return Names;
}

void ReturnViewModel::populate(QString name, double cost, int amount, double total)
{
    auto index=m_orders.count();
    beginInsertRows(QModelIndex(), index, index);
    m_orders.append({name,amount,cost,total,total});
    endInsertRows();
}

bool ReturnViewModel::increaseAmount(int index, QString name, double cost, int amount)
{
    beginResetModel();
    m_orders.replace(index,{name,(amount+1),cost,cost*amount,(cost*amount*m_orders.count())});
    endResetModel();
    return true;
}

bool ReturnViewModel::decreseAmount(int index, QString name, double cost, int amount)
{
    beginResetModel();
    m_orders.replace(index,{name,(amount<=1?amount:amount-1),cost,cost*amount,(cost*amount*m_orders.count())});
    endResetModel();
    return true;
}
}

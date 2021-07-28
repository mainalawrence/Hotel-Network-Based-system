#include "ordercat.h"
#include<QDebug>

namespace Models {
OrderCat::OrderCat(QObject *parent)
    : QAbstractListModel(parent),m_orders{}
{

}

int OrderCat::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_orders.size();
}

QVariant OrderCat::data(const QModelIndex &index, int role) const
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

bool OrderCat::setData(const QModelIndex &index, const QVariant &value, int role)
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

Qt::ItemFlags OrderCat::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

bool OrderCat::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endInsertRows();
    return true;
}

bool OrderCat::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endRemoveRows();
    return true;
}

QHash<int, QByteArray> Models::OrderCat::roleNames() const
{
    QHash<int, QByteArray>Names;
    Names.insert(Name,"name");
    Names.insert(Cost,"cost");
    Names.insert(Amount,"amount");
    Names.insert(Total,"total");
    Names.insert(SumTotal,"totolsum");
    return Names;
}

void OrderCat::clearCat()
{for(int a=0;a<m_orders.size();a++){
        m_orders.removeAt(a);}
    auto index=m_orders.count();
    beginRemoveRows(QModelIndex(), index, index);
    m_totalcost=0;
    emit totalcostChanged();
    settotalcost();
    endRemoveRows();
}

void OrderCat::addonCat(QString name, double cost, int amount, double total)
{

    auto index=m_orders.count();
    beginInsertRows(QModelIndex(), index, index);
    m_orders.append({name,amount,cost,total,total});
    settotalcost();
    endInsertRows();
}

bool OrderCat::removefromCat(int index)
{
    beginRemoveRows(QModelIndex(), index, index);
    m_orders.removeAt(index);
    settotalcost();
    emit totalcostChanged();
    endRemoveRows();
    return true;
}

bool OrderCat::increaseAmount(int index,QString name,double cost,int amount)
{
    // name amount cost total sumt tax
    beginResetModel();
    m_orders.replace(index,{name,(++amount),cost,cost*amount,(cost*amount*m_orders.count())});
    settotalcost();
    endResetModel();
    return true;
}

bool OrderCat::decreseAmount(int index, QString name, double cost, int amount)
{
    beginResetModel();
    m_orders.replace(index,{name,(amount<=1?amount:--amount),cost,cost*amount,(cost*amount*m_orders.count())});
    settotalcost();
    endResetModel();
    return true;
}

double OrderCat::getTotalcost()
{
    return m_totalcost;

}
bool OrderCat::settotalcost()
{    m_totalcost=0.0;
     m_tax=0.0;
      if(m_orders.count()<0){
          m_totalcost=0.0;
          m_tax=0.0;
          return -1;
      }
      if(m_orders.size()>0){
          m_tax=0.0;
          m_totalcost=0.0;
          for(int i=0;i<m_orders.size();i++){
              m_totalcost += m_orders.at(i).Total;

          }
          emit totalcostChanged();

      }
      return true;
}


}

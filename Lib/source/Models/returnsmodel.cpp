#include "returnsmodel.h"


namespace Models{

ReturnsModel::ReturnsModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

int ReturnsModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return   m_Returns.size();
}

int ReturnsModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return roleNames().count();
}

QVariant ReturnsModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    auto col=role;
    auto row=m_Returns.at(index.row());
    switch (col) {
    case orderNo:{
        return QVariant(row.OrderNo);
        break;
    }
    case amount:{
        return QVariant(row.Amount);
        break;
    }
    case date:{
        return QVariant(row.Date);
        break;
    }
    case waitersName:{
        return QVariant(row.WaitersName);
        break;
    }
    case totalcost:{
        return QVariant(row.Totalcost);
        break;
    }
    case details:{
        return QVariant(row.Details);
        break;
    }

    }
    // FIXME: Implement me!
    return QVariant();
}

QHash<int, QByteArray> ReturnsModel::roleNames() const
{
    QHash<int ,QByteArray>RoleName;
    RoleName.insert( orderNo,"orderNo");
    RoleName.insert( amount,"amount");
    RoleName.insert(date,"date");
    RoleName.insert(waitersName,"waitersName");
    RoleName.insert(totalcost,"totalcost");
    RoleName.insert( details,"details");
    return RoleName;
}

void ReturnsModel::populate(QList<Returns> &data)
{
    m_Returns.empty();
    m_Returns=data;
}
}

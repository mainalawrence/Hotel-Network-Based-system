#include "salesdetailsmodel.h"
namespace Models {

SalesDetailsModel::SalesDetailsModel(QObject *parent)
    : QAbstractListModel(parent)
{
    m_data.append({"name","cost","amount","total"});
    m_data.append({"name","cost","amount","total"});
    m_data.append({"name","cost","amount","total"});
    m_data.append({"name","cost","amount","total"});
}

int SalesDetailsModel::rowCount(const QModelIndex &parent) const
{

    if (parent.isValid())
        return 0;

    return m_data.count();
}

QVariant SalesDetailsModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    auto row=m_data.at(index.row());
    switch (role) {
    case name:{
        return QVariant(row.name).toString();
        break;
    }
    case cost:{
        return QVariant(row.cost).toString();
        break;
    }
    case amount:{
        return QVariant(row.Amount).toString();
        break;
    }
    case total:{
        return QVariant(row.Total).toString();
        break;
    }
    }
    return QVariant();
}

bool SalesDetailsModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        auto row=m_data.at(index.row());
        switch (role) {
        case name:{
            row.name=value.toString();
            break;
        }
        case cost:{
            row.cost=value.toString();
            break;
        }
        case amount:{
            row.Amount=value.toString();
            break;
        }
        case total:{
            row.Total=value.toString();
            break;
        }
        }
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags SalesDetailsModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

void Models::SalesDetailsModel::populate(QJsonArray &data)
{auto index=m_data.count();

  auto obj =data.at(0);
    qDebug()<<obj;
    for(int a=0;a<data.size();a++)
    {

    }

    beginInsertRows(QModelIndex(),index,index);
    m_data.empty();

    endInsertRows();
}

QHash<int, QByteArray> SalesDetailsModel::roleNames() const
{
    QHash<int, QByteArray>roles;
    roles.insert(name,"name");
    roles.insert(cost,"cost");
    roles.insert(amount,"amount");
    roles.insert(total,"total");
    return roles;
}
}

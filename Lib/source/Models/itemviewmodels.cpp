#include "itemviewmodels.h"

namespace Models {
ItemViewModels::ItemViewModels(QObject *parent)
    : QAbstractTableModel(parent)
{
}
int ItemViewModels::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return   m_items.size();
}

int ItemViewModels::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return roleNames().count();
}

QVariant ItemViewModels::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    auto  col=role;
    auto row=m_items.at(index.row());
    switch (col) {
    case id:{
        return QVariant(row.id);
        break;
    }
    case Name:{
        return QVariant(row.Name);
        break;
    }
    case category:{
        return QVariant(row.category);
        break;
    }
    case itemgroup:{
        return QVariant(row.itemgroup);
        break;
    }
    case cost:{
        return QVariant(row.cost);
        break;
    }
    }
    return QVariant();
}

bool ItemViewModels::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        auto  col=role;
        auto row=m_items.at(index.row());
        switch (col) {
        case id:{
            row.id=QVariant(value).toString();
            break;
        }
        case Name:{
           row.Name=QVariant(value).toString();
            break;
        }
        case category:{
        row.category=QVariant(value).toString();
            break;
        }
        case itemgroup:{
        row.itemgroup=QVariant(value).toString();
            break;
        }
        case cost:{
            row.cost=QVariant(value).toString();
            break;
        }
        }
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags ItemViewModels::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> ItemViewModels::roleNames() const
{
    QHash<int, QByteArray>roles;
    roles.insert(id,"id");
    roles.insert( Name,"name");
    roles.insert(category,"category");
    roles.insert( itemgroup,"itemgroup");
    roles.insert(cost,"cost");
    return  roles;
}

void ItemViewModels::deleteItem(int index)
{
    beginRemoveRows(QModelIndex(), index, index );
    auto data= m_items.at(index);
    m_items.removeAt(index);
    endRemoveRows();
}

void ItemViewModels::populate(QList<itemView> &items)
{
    auto index=m_items.count();
  beginInsertRows(QModelIndex(),index,index);
  m_items=items;
  endInsertRows();
}
}

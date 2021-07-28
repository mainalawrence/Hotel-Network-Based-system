#include "orderitemsmodels.h"

namespace Models {
OrderItemsModels::OrderItemsModels(QObject *parent)
    : QAbstractTableModel(parent)
{
}

int OrderItemsModels::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_items.count();
}

QVariant OrderItemsModels::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    auto col=role;
    auto row=m_items.at(index.row());
    switch (col) {
    case Name:{
        return QVariant(row.Name);
    }
    case Cost:{
        return QVariant(row.Cost);
    }
    case itemid:{
        return QVariant(row.itemId);
    }

    }
    return QVariant();
}

int OrderItemsModels::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return roleNames().count();
}

QHash<int, QByteArray> Models::OrderItemsModels::roleNames() const
{
    QHash<int ,QByteArray>RoleName;
    RoleName.insert(Name,"name");
    RoleName.insert(Cost,"cost");
    RoleName.insert(itemid,"itemid");
    return RoleName;
}

void Models::OrderItemsModels::populate(QList<Orderdisp> &data)
{
    m_items.empty();
    m_items=data;
}

void OrderItemsModels::depopulate()
{
     m_items.empty();
}
}

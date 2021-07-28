#include "waitermodelview.h"

namespace Models {


WaiterModelView::WaiterModelView(QObject *parent)
    : QAbstractListModel(parent)
{

}

int WaiterModelView::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    return  m_details.size();
}

QVariant WaiterModelView::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    auto col=role;
    auto row=m_details.at(index.row());
    switch (col) {
    case 0:{
        return QVariant(row.Name).toString();
        break;
    }
    case 1:{
        return QVariant(row.IdNumber).toString();
        break;
    }
    }
    return QVariant();
}

QHash<int, QByteArray> Models::WaiterModelView::roleNames() const
{
    QHash<int, QByteArray>roles;
    roles.insert(0,"name");
    roles.insert(1,"idNumber");
    return roles;
}

void WaiterModelView::populate(QList<waiterDerails> &data)
{
    auto index= m_details.size();
    beginInsertRows(QModelIndex(),index,index);
    m_details=data;
    endInsertRows();
}
}

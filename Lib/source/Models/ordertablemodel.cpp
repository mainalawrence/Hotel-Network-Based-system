#include "ordertablemodel.h"

namespace Models {


OrderTablemodel::OrderTablemodel(QObject *parent)
    : QAbstractListModel(parent)
{

}

int OrderTablemodel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;
    return   m_Tablename.size();
}

void OrderTablemodel::populate(QList<Tables> &data)
{
    m_Tablename.empty();
    m_Tablename=data;
}

QVariant OrderTablemodel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if(role==0){
        return QVariant(m_Tablename.at(index.row()).tables);
    }
    return QVariant();
}

QHash<int, QByteArray> OrderTablemodel::roleNames() const
{
  QHash<int, QByteArray>tablesname;
       tablesname.insert(0,"tablename");

return tablesname;
}
}

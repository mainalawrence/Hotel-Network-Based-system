#include "userviewmodel.h"

namespace Models {
USerViewModel::USerViewModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

int USerViewModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_users.size();
}

int USerViewModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return  roleNames().size();
}
QVariant USerViewModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    auto row=m_users.at(index.row());
    auto col=role;
    switch (col) {
    case Firstname:{
        return QVariant(row.Firstname);
        break;
    }
    case lastname:{
        return QVariant(row.lastname);
        break;
    }
    case idnumber:{
        return QVariant(row.idnumber);
        break;
    }
    case passowrd:{
        return QVariant(row.passowrd);
        break;
    }
    case userName:{
        return QVariant(row.userName);
        break;
    }
    case Role:{
        return QVariant(row.role);
        break;
    }
    case gender:{
        return QVariant(row.gender);
        break;
    }
    case email:{
        return QVariant(row.email);
        break;
    }
    case address:{
        return QVariant(row.address);
        break;
    }

    }
    return QVariant();
}

void USerViewModel::removeUser(int index)
{
    beginRemoveRows(QModelIndex(),index,index);
    m_users.removeAt(index);
    endRemoveRows();
}
QHash<int, QByteArray> USerViewModel::roleNames() const
{   QHash<int, QByteArray>RoleNames;
    RoleNames.insert( Firstname,"Firstname");
    RoleNames.insert( lastname,"lastname");
    RoleNames.insert( idnumber,"idnumber");
    RoleNames.insert( passowrd,"passowrd");
    RoleNames.insert( userName,"userName");
    RoleNames.insert( Role,"Role");
    RoleNames.insert( gender,"gender");
    RoleNames.insert( email,"email");
    RoleNames.insert( address,"address");
    return  RoleNames;
}

bool USerViewModel::setData(const QModelIndex &index, const QVariant &value, int role)
{

    if (!index.isValid()) return {};
    auto row=m_users.at(index.row());
    auto col=role;
    switch (col) {
    case Firstname:{
       row.Firstname=value.toString();
        break;
    }
    case lastname:{
         row.lastname=value.toString();
        break;
    }
    case idnumber:{
       row.idnumber=value.toString();
        break;
    }
    case passowrd:{
       row.passowrd=value.toString();
        break;
    }
    case userName:{
       row.userName=value.toString();
        break;
    }
    case Role:{
      row.role=value.toString();;
        break;
    }
    case gender:{
        row.gender=value.toString();
        break;
    }
    case email:{
       row.email=value.toString();
        break;
    }
    case address:{
        row.address=value.toString();
        break;
    }
        emit dataChanged(index, index, QVector<int>() << role);
        return true;

    }
    return false;
}
void USerViewModel::populateusers(QList<Users> &data)
{
    auto index=m_users.count();
    beginInsertRows(QModelIndex(),index,index);
    m_users.empty();
    m_users=data;
    endInsertRows();
}
Qt::ItemFlags USerViewModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}
}

#include "workinghoursviewsmodle.h"

namespace Models {


WorkingHoursViewsModle::WorkingHoursViewsModle(QObject *parent)
    : QAbstractTableModel(parent)
{

}

int WorkingHoursViewsModle::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return  m_Data.count();
}

int WorkingHoursViewsModle::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return roleNames().count();
}

QVariant WorkingHoursViewsModle::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

  auto column=role;
  auto row=m_Data.at(index.row());
  switch (column) {
  case Id:{
      return QVariant(row.Id);
      break;
  }
  case Name:{
      return QVariant(row.Name);
      break;
  }
  case Login:{
      return QVariant(row.Name);
      break;
  }
  case LogOut:{
      return QVariant(row.LogOut);
      break;
  }
  case WorkingHours:{
      return QVariant(row.AveHours);
      break;
  }
  }
    return QVariant();
}

bool WorkingHoursViewsModle::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        auto column=role;
        auto row=m_Data.at(index.row());
        switch (column) {
        case Id:{
           row.Id=QVariant(value).toString();
            break;
        }
        case Name:{
            row.Name=QVariant(value).toString();
            break;
        }
        case Login:{
           row.Name=QVariant(value).toString();
            break;
        }
        case LogOut:{
            row.LogOut=QVariant(value).toString();
            break;
        }
        case WorkingHours:{
           row.AveHours=QVariant(value).toString();
            break;
        }
        }
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags WorkingHoursViewsModle::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> WorkingHoursViewsModle::roleNames() const
{
    QHash<int, QByteArray>roles;
    roles.insert(  Id,"id");
    roles.insert( Name,"name");
    roles.insert( Login,"login");
    roles.insert( LogOut,"logout");
    roles.insert( WorkingHours,"workingHours");
    return roles;
}
void WorkingHoursViewsModle::populate(QList<Models::WorkingHours> &data)
{
    auto index=m_Data.count();
    beginInsertRows(QModelIndex(),index,index);
    m_Data.empty();
    m_Data=data;
    endInsertRows();
}
}

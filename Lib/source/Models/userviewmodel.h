#ifndef USERVIEWMODEL_H
#define USERVIEWMODEL_H

#include <QAbstractTableModel>
#include<Pos_Lib_global.h>
#include<QVariant>

struct Users{
  QString  Firstname;
  QString lastname;
  QString idnumber;
  QString passowrd;
  QString userName;
  QString role;
  QString gender;
  QString email;
  QString address;
};

namespace Models {
class POS_LIB_EXPORT USerViewModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit USerViewModel(QObject *parent = nullptr);
    enum{
        Firstname=0,
        lastname,
        idnumber,
        passowrd,
        userName,
        Role,
        gender,
        email,
        address
    };

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QHash<int,QByteArray>roleNames()const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex &index)const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Q_INVOKABLE void removeUser(int index);
    void populateusers(QList<Users> &data);


private:
    QList<Users>m_users;
};
}
#endif // USERVIEWMODEL_H

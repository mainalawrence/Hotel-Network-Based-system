#ifndef USERENTRY_H
#define USERENTRY_H

#include <QObject>
#include<Pos_Lib_global.h>
#include<Controller/Main_Databasecontroller.h>
#include<Models/pos_users.h>
#include<QtDebug>

using namespace Controller;
namespace DataBase {
using namespace Models;
class POS_LIB_EXPORT UserEntry : public QObject
{
    Q_OBJECT
public:
    explicit UserEntry(QObject *parent = nullptr,Main_DatabaseController *databasecontroller=nullptr, Pos_Users* users=nullptr);

signals:

public slots:
     void userssaved();
private:
     Main_DatabaseController *databasecontroller{nullptr};
     Pos_Users *posUsers{nullptr};
};
}


#endif // USERENTRY_H

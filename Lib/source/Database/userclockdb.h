#ifndef USERCLOCKDB_H
#define USERCLOCKDB_H

#include <QObject>
#include<Pos_Lib_global.h>
#include<Controller/Main_Databasecontroller.h>
#include<Models/myclocktime.h>
#include<QtDebug>

using namespace Controller;
namespace DataBase {
using namespace Models;
class POS_LIB_EXPORT UserClockdb : public QObject
{
    Q_OBJECT
public:
    explicit UserClockdb(QObject *parent = nullptr,Main_DatabaseController *databasecontroller=nullptr,  MyClockTime *clockt =nullptr);


signals:
private:
     Main_DatabaseController *databasecontroller{nullptr};
     MyClockTime *clockt{nullptr};

};
}
#endif // USERCLOCKDB_H

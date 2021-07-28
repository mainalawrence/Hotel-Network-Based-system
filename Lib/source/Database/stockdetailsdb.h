#ifndef STOCKDETAILSDB_H
#define STOCKDETAILSDB_H

#include <QObject>
#include<Pos_Lib_global.h>
#include<Controller/Main_Databasecontroller.h>
#include<Models/stockdetails.h>
#include<QtDebug>

using namespace Controller;
namespace DataBase {
using namespace Models;
class POS_LIB_EXPORT Stockdetailsdb : public QObject
{
    Q_OBJECT
public:
    explicit Stockdetailsdb(QObject *parent = nullptr,Main_DatabaseController *databasecontroller=nullptr,  StockDetails *stocks=nullptr);

signals:
private:
    Main_DatabaseController *databasecontroller{nullptr};
    StockDetails *stocks{nullptr};

};
}
#endif // STOCKDETAILSDB_H

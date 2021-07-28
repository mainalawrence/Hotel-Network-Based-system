#include "stockdetailsdb.h"


namespace DataBase {
DataBase::Stockdetailsdb::Stockdetailsdb(QObject *parent, Controller::Main_DatabaseController *databasecontroller,  StockDetails *stocks):
     QObject(parent),databasecontroller(databasecontroller),stocks(stocks)
{

}
}

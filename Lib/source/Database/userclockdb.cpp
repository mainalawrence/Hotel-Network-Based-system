#include "userclockdb.h"


using namespace Controller;
namespace DataBase {
using namespace Models;
DataBase::UserClockdb::UserClockdb(QObject *parent, Main_DatabaseController *databasecontroller, MyClockTime *clockt):
     QObject(parent),databasecontroller(databasecontroller),clockt(clockt)

{

}
}

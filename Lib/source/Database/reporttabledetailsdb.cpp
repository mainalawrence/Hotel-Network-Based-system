#include "reporttabledetailsdb.h"
#include<QDebug>

namespace DataBase {
using namespace Models;
using namespace DataBase;
ReportTableDetailsDb::ReportTableDetailsDb(QObject *parent, ReportTablemodel *reportTablemodel, Database_controller *databaseController)
    : QObject(parent)
  ,reportTableModel(reportTablemodel),databaseConroller(databaseController)
{
}
}

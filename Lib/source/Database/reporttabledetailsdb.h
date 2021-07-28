#ifndef REPORTTABLEDETAILSDB_H
#define REPORTTABLEDETAILSDB_H

#include <QObject>
#include<Pos_Lib_global.h>
#include<Models/reporttablemodel.h>
#include<Controller/database_controller.h>
#include<Data/sales_datatype.h>

using namespace Models;

using namespace Controller;
namespace DataBase {

class POS_LIB_EXPORT ReportTableDetailsDb : public QObject
{
    Q_OBJECT
public:
    //typedef Sales_DataType Mysales;

    explicit ReportTableDetailsDb(QObject *parent = nullptr,ReportTablemodel *reportTablemodel=nullptr,Database_controller *databaseController=nullptr);

signals:
private:
    ReportTablemodel *reportTableModel{nullptr};
    Database_controller *databaseConroller{nullptr};



};
}
#endif // REPORTTABLEDETAILSDB_H

#ifndef REPORTTABLEMODEL_H
#define REPORTTABLEMODEL_H

#include <QAbstractTableModel>
#include<Pos_Lib_global.h>
#include<Controller/database_controller.h>
#include<QVariant>
#include<QList>
#include<QHash>
#include<QModelIndex>
#include<QJsonObject>
#include<QByteArray>
#include<Data/sales_datatype.h>
#include<Delegates/reporttabledelegate.h>
namespace Models {
class POS_LIB_EXPORT ReportTablemodel : public QAbstractTableModel
{
    Q_OBJECT

public:
    enum RoleName{
        ReceitNumber=0,
        Totalcost,
        PaymentType,
        SaleDate,
        UserName,
        Details

    };
    explicit ReportTablemodel(QObject *parent = nullptr);
    typedef  QList<Sales_DataType> Sales;


    // Header:
    //QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    Q_INVOKABLE int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    Q_INVOKABLE int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    Q_INVOKABLE QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Q_INVOKABLE  QHash<int,QByteArray> roleNames() const override;


    //void setLData(const Sales &LData);

private:
    int NumberofSales;
    Controller::Database_controller *db;
    //Sales_DataType *saledata{nullptr};
   // Sales ;
    Delegate::ReportTableDelegate * m_LData;
};
}


#endif // REPORTTABLEMODEL_H

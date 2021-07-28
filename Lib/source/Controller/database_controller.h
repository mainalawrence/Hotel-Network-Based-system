#ifndef DATABASE_CONTROLLER_H
#define DATABASE_CONTROLLER_H

#include <QObject>
#include<QJsonArray>
#include<QJsonObject>
#include<QJsonValue>
#include<QJsonDocument>
#include<QSql>
#include<QSqlQuery>
#include<QSqlDatabase>
#include<QDateTime>
#include<QVariant>
#include<Pos_Lib_global.h>
#include<Controller/Main_Databasecontroller.h>
#include<Data/sales_datatype.h>
#include <Models/ReportModel.h>
#include <Models/returnsmodel.h>
#include <Models/itemviewmodels.h>
#include<Models/salesdetailsmodel.h>
#include<Models/userviewmodel.h>
#include<Models/workinghoursviewsmodle.h>
#include<Models/orderitemsmodels.h>
#include<Models/waitermodelview.h>
#include<Models/salescat.h>
#include<Models/ordertablemodel.h>
#include<QVector>
#include<QFile>
class Saless;
class SalesC;
class Returns;
class Users;
class itemView;
class WorkingHours;
class Orderdisp;
class SalesModel;
class waiterDerails;
class Tables;
namespace Controller

{
class POS_LIB_EXPORT  Database_controller : public Main_DatabaseController
{
    Q_OBJECT
public:
    explicit Database_controller(QObject *parent = nullptr);
    bool CreatetableRow(QString data)const;

    bool CreateRow(const QString &Tablename,const QString UID,const QJsonObject &jsonObject)const override;
    bool DeleteRow(const QString &Tablename,const QString &id)const override;
    bool DeleteRowS(const QString &Tablename,const QString &id)const;
    bool updateRow(const QString &tablename,const QString &id,const QJsonObject &jsonobject)const override;
    QJsonObject readRow(const QString &Tablename, QString &id)const override;
    QJsonArray Find(const QString &Tablename, const QString &searchText)const override;
    bool CreatejsonTable(QString tableName)const override;
    bool CreateOderTable(QString tableName)const;
    bool CreateorderRow(const QString &Tablename,const QJsonObject &jsonObject)const;
    bool updateclockRow(const QString,const QJsonObject &jsonobject);
    QString getorderNumber(QString Tnumber);
    // bool CreateSaleTable(QString tableName)const;
    QHash<QString,QVariant> readTable(const QString &Tablename)const override;
    QJsonDocument readTable_Date(const QString &Tablename,const QString Date)const override;
    QJsonDocument readTable_Id(const QString &Tablename,const QString id)const override;
    QString readclock(const QString id);
    QString getServer() const;
    void setServer(const QString &value);
    QString getDatabaseName() const;
    void setDatabaseName(const QString &value);
    bool createTable();
    bool creatabletable();
    QStringList res;
    //////////////////////////////////
    QList<SalesC> readtableorders(const QString tablename);
    QList<Saless> readTablebar_sales(const QString tablename,const QString id,const QString name);
    QList<Returns> readTable_returns(const QString tablename,const QString id,const QString name);
    QList<Users> readTable_Users(const QString tablename,const QString id,const QString name);
    QList<Models::WorkingHours> readTable_usersclock(const QString id);
    QList<itemView> readTable_stock(const QString id);
    QList<Orderdisp> readTable_orders(const QString tableName,const QString category,const QString group);
    QList<waiterDerails>readWaiter();
    QList<Tables>readtables();

    //the list
    QList<Saless>readrestaurantsale_id(QString t_name,QString u_id);
    QList<Saless>readbarsales_id(QString t_name,QString u_id);
    QList<Returns>readrestaurantreturns_id(QString t_name,QString u_id);
    QList<Returns>readbarreturns_id(QString t_name,QString u_id);
    //public slots:
    QStringList logincheck(QString ,QString);

    QString getServerName() const;
    void setServerName(const QString &value);

    QString getDataBaseUserName() const;
    void setDataBaseUserName(const QString &value);

    QString getDatabasepassword() const;
    void setDatabasepassword(const QString &value);

    int getDatabaseport() const;
    void setDatabaseport(int value);

    bool getDatabaseconnected() const;

signals:
    void Databaseconnected();
    void dbconnected(bool);

private:
    Main_DatabaseController* maindb{nullptr};
    QSqlDatabase db;
    bool databaseinitialization();
    QString ServerName;
    QString DatabaseName;
    QString DataBaseUserName;
    QString Databasepassword;
    int databaseport;
    void Readfile();
    bool m_databaseconnected=false;
};
}
#endif // DATABASE_CONTROLLER_H

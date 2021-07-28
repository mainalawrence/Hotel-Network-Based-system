#ifndef MASTERCONTROLLER_H
#define MASTERCONTROLLER_H
#include <QObject>
#include<QTimer>
#include<chrono>
#include<QFile>
#include<QDataStream>
#include<QCryptographicHash>
#include<QString>
#include<QScopedPointer>
#include"navigation-controller.h"
#include "Controller/database_controller.h"
#include<Models/pos_users.h>
#include<Database/userentry.h>
#include<Database/userentry.h>
#include<Database/stockdetailsdb.h>
#include<Models/stockdetails.h>
#include<Models/myclocktime.h>
#include<Database/userclockdb.h>
#include<Database/reporttabledetailsdb.h>
#include<Models/reporttablemodel.h>
#include<Models/salescat.h>
#include<Models/waitermodelview.h>
#include<Models/ordertablemodel.h>

#include<Models/returnsmodel.h>
#include<Models/userviewmodel.h>
#include<Models/ordertablemodel.h>
#include<Models/orderitemsmodels.h>
#include<Models/itemviewmodels.h>
#include<Models/appsettings.h>
#include<Models/orderup.h>
#include<Models/sales.h>
#include<Models/workinghoursviewsmodle.h>
#include<Printer/printecontrol.h>
#include<Pos_Lib_global.h>

class Returns;
class Users;
class Orderdisp;
class Tables;
class itemView;
namespace Controller {

using namespace Models;
class POS_LIB_EXPORT MasterController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString ui_clockInn READ getClockin WRITE setClockin NOTIFY Clockinchanged)
    Q_PROPERTY(QString ui_ordbarnum READ getOrdbarnum WRITE setOrderNumber NOTIFY OrdbarnumChanged)
    Q_PROPERTY(QString ui_ordrestnum READ getOrdrestNum WRITE setOrdrestNum NOTIFY OrdrestnumChanged)
    Q_PROPERTY(QString ui_clockin READ clockin CONSTANT)
    Q_PROPERTY(QString ui_OrderCategory READ OrderCategory  WRITE sETOrderCategory )
    Q_PROPERTY(QString ui_Category READ Category CONSTANT)
    Q_PROPERTY(QString ui_userid READ Userid CONSTANT)
    Q_PROPERTY(QString ui_username READ username CONSTANT)
    Q_PROPERTY(QString ui_userRole READ userRole CONSTANT)
    Q_PROPERTY(QString ui_Ordernumber READ getOrderNumber WRITE setOrderNumber)
    Q_PROPERTY(bool ui_dbconnected MEMBER dbconnecteds CONSTANT)
    Q_PROPERTY(QString ui_message READ message NOTIFY textChanged)
    Q_PROPERTY(Controller::NavigationController* ui_navigationController READ navigationController CONSTANT)
    Q_PROPERTY(Models::Pos_Users* ui_Posusers READ posuser CONSTANT )
    Q_PROPERTY(DataBase::UserEntry *ui_createuser  READ createuser CONSTANT )
    Q_PROPERTY(Models::StockDetails *ui_StockDetails READ StockDetails CONSTANT)
    Q_PROPERTY(DataBase::Stockdetailsdb *ui_createStock  READ createStock CONSTANT )
    Q_PROPERTY(Models::MyClockTime* ui_NewTime READ NewTime CONSTANT)
    Q_PROPERTY(DataBase::UserClockdb *ui_CreateTime READ createTime CONSTANT)
    Q_PROPERTY(Models::OrderUp* ui_Saveorders READ Saveorders CONSTANT)
    Q_PROPERTY(Models::BarReportModel *ui_RestSaleReport READ RestSaleReport CONSTANT)
    Q_PROPERTY(Models::BarReportModel *ui_BarSaleReport READ BarSaleReport CONSTANT)
    Q_PROPERTY(Models::ReturnsModel *ui_RestReturnReport READ RestReturnReport CONSTANT)
    Q_PROPERTY(Models::ReturnsModel *ui_BarReturnReport READ BarReturnReport CONSTANT)
    Q_PROPERTY(Models::USerViewModel *ui_UsersViewModel READ UsersViewModel CONSTANT)
    Q_PROPERTY(Models::OrderTablemodel *ui_OrderTablemodels READ OrderTablemodels CONSTANT)
    Q_PROPERTY(Models::BarReportModel *ui_WaiterSaleReport READ WaiterSaleReport CONSTANT)
    Q_PROPERTY(Models::ReturnsModel *ui_WaiterReturnReport READ WaiterReturnReport CONSTANT)
    Q_PROPERTY(Models::OrderItemsModels* ui_OrderDrinks READ OrderDrinks CONSTANT)
    Q_PROPERTY(Models::OrderItemsModels* ui_OrderBreakfast READ OrderBreakfast CONSTANT)
    Q_PROPERTY(Models::OrderItemsModels* ui_Ordermeal READ Ordermeal CONSTANT)
    Q_PROPERTY(Models::OrderItemsModels* ui_OrderSnacks READ OrderSnacks CONSTANT)
    Q_PROPERTY(Models::OrderItemsModels* ui_SalesorderedDetails READ SalesorderedDetails CONSTANT)
    Q_PROPERTY(Models::OrderItemsModels* ui_OrderBarItemsModels READ OrderBarItemsModels CONSTANT)
    Q_PROPERTY(Models::OrderItemsModels*  ui_OrderRestItemsModels READ OrderRestItemsModels CONSTANT)
    Q_PROPERTY(Models::ItemViewModels* ui_itemviewsmodel READ itemviewsmodel CONSTANT)
    Q_PROPERTY(Models::AppSettings *ui_Appsettings READ Appsettings CONSTANT)
    Q_PROPERTY(Models::SalesCat *ui_salecat  READ salecat CONSTANT)
    Q_PROPERTY(Models::Sales *ui_restSales READ restSales CONSTANT)
    Q_PROPERTY(Models::Sales *ui_barSales READ barSales CONSTANT)
    Q_PROPERTY(Models::Sales *ui_restreturn READ restreturn CONSTANT)
    Q_PROPERTY(Models::Sales *ui_barreturn READ barreturn CONSTANT)
    Q_PROPERTY(Models::BarReportModel *ui_WRestSaleReport READ WRestSaleReport CONSTANT)
    Q_PROPERTY(Models::BarReportModel *ui_WBarSaleReport READ WBarSaleReport CONSTANT)
    Q_PROPERTY(Models::ReturnsModel *ui_WRestReturnReport READ WRestReturnReport CONSTANT)
    Q_PROPERTY(Models::ReturnsModel *ui_WBarReturnReport READ WBarReturnReport CONSTANT)
    Q_PROPERTY(Models::BarReportModel *ui_CRestSaleReport READ CRestSaleReport CONSTANT)
    Q_PROPERTY(Models::ReturnsModel *ui_CRestReturnReport READ CRestReturnReport CONSTANT)
    Q_PROPERTY( Models::WaiterModelView *ui_waiterModelView READ waiterModelView CONSTANT)
    Q_PROPERTY( Models::OrderTablemodel *ui_ordertables  READ ordertables CONSTANT)

    //the data is new

    Q_PROPERTY( Models::BarReportModel* ui_restaurantsales_id READ restaurantsales_id  CONSTANT)
    Q_PROPERTY( Models::BarReportModel* ui_barsales_id READ barsales_id  CONSTANT)
    Q_PROPERTY( Models::ReturnsModel* ui_restaurantreturns_id READ restaurantreturns_id  CONSTANT)
    Q_PROPERTY( Models::ReturnsModel* ui_barreturns_id READ barreturns_id  CONSTANT)

    //the login clock report
    Q_PROPERTY(Models::BarReportModel* ui_restaurantsales_clock_id READ restaurantsales_clock_id  CONSTANT)
    Q_PROPERTY(Models::BarReportModel* barsales_clock_id READ barsales_clock_id  CONSTANT)
    Q_PROPERTY(Models::ReturnsModel* restaurantreturns_clock_id READ restaurantreturns_clock_id  CONSTANT)
    Q_PROPERTY(Models::ReturnsModel* barreturns_clock_id READ barreturns_clock_id  CONSTANT)
public:
    explicit MasterController(QObject *parent = nullptr,Database_controller *maincontroler=nullptr,Pos_Users *newUser=nullptr);
    ~MasterController();
    typedef Sales_DataType Mysales;
    const QString username()const;
    const QString userRole()const;
    const QString message()const;
    const QString Userid()const;
    const QString clockin()const;
    const QString OrderCategory() const;
    const QString Category() const;
  Q_INVOKABLE void sETOrderCategory(QString category);
    NavigationController *navigationController()const;
    Models::Pos_Users *posuser();
    Models::StockDetails* StockDetails();
    DataBase::UserEntry *createuser();
    DataBase::Stockdetailsdb *createStock();
    DataBase::UserClockdb *createTime();
    Models::MyClockTime* NewTime();
    Models::OrderUp* Saveorders();
    Models::BarReportModel *WaiterSaleReport();
    Models::ReturnsModel *WaiterReturnReport();
    Models::BarReportModel *RestSaleReport();
    Models::BarReportModel *BarSaleReport();
    Models::ReturnsModel *RestReturnReport();
    Models::ReturnsModel *BarReturnReport();
    Models::USerViewModel *UsersViewModel();
    Models::OrderTablemodel *OrderTablemodels();
    Models::OrderItemsModels* OrderBarItemsModels();
    Models::OrderItemsModels* OrderRestItemsModels();
    Models::OrderItemsModels* OrderDrinks();
    Models::OrderItemsModels* OrderBreakfast();
    Models::OrderItemsModels* Ordermeal();
    Models::OrderItemsModels* OrderSnacks();
    Models::OrderItemsModels* SalesorderedDetails();
    Models::ItemViewModels* itemviewsmodel();
    Models::AppSettings *Appsettings();
    Models::SalesCat *salecat();
    Models::Sales *restSales();
    Models::Sales *barSales();
    Models::Sales *restreturn();
    Models::Sales *barreturn();
    Models::BarReportModel *WRestSaleReport();
    Models::BarReportModel *WBarSaleReport();
    Models::ReturnsModel *WRestReturnReport();
    Models::ReturnsModel *WBarReturnReport();
    Models::ReturnsModel *CRestReturnReport();
    Models::BarReportModel *CRestSaleReport();
    Models::WaiterModelView *waiterModelView();
    Models::OrderTablemodel *ordertables();


    //SPECIAL
    Models::BarReportModel* restaurantsales_id();
    Models::BarReportModel* barsales_id();
    Models::ReturnsModel* restaurantreturns_id();
    Models::ReturnsModel* barreturns_id();

    //the login clock view information
    Models::BarReportModel* restaurantsales_clock_id();
    Models::BarReportModel* barsales_clock_id();
    Models::ReturnsModel* restaurantreturns_clock_id();
    Models::ReturnsModel* barreturns_clock_id();
private:

    void userssaved();
    Q_INVOKABLE void gettimePoint();
    Q_INVOKABLE void getorders();
    QString getOrderNumber() const;
    void setOrderNumber(const QString &OrderNumber);

    QString getOrdbarnum() const;
    void setOrdbarnum(const QString &ordbarnum);

    QString getOrdrestNum() const;
    void setOrdrestNum(const QString &ordrestNum);
    Q_INVOKABLE  void getorderNum();
    Q_INVOKABLE void settheclock();
    QString getClockin() const;
    void setClockin(const QString &Clockin);

signals:
    void textChanged();
    void OrdbarnumChanged();
    void OrdrestnumChanged();
    void Clockinchanged();
public slots:
    Q_INVOKABLE void onLoginsystemsales();
    void onLogin(QString,QString);
    void onLogout();
    void onClockin(QString,QString);
    void onCreateuser();
    void onUpdateUser();
    void onCreateStock();
    void onneworder();
    void onSaleSaved();
    void onReturnorder();
    void onCreateclock();
    void onClockout();
    void onBClockclicked();
    void onLoadingReport();
    void onItemdelete(QString id,int index);
    void onDroprow(QString tablename,QString id,int index);
    void onDeletPosuser(QString id,int index);
    void onUpdateuser(QString uid);
    void onSettings();
    void onGetOrderNumber();
    //the report slots
    void onSearchBarReturn(QString Orederid);
    void onSearchBarSales(QString Date);
    void onSearchRestaurantSales(QString Date);
    void onSearchRestaurantReturn(QString Orederid);
    //the Pos user slots
    void onViewUserclock(QString userId);
    void updateordervier();
    void onUpdatestockusers();
    void onCashierviewsales(QString userId);
    void onLoadCashierView();

    // the naccw
    void onReportViewOpen();
    void onReportviewclosed();
    void onRestaurantSalesbtn(QString u_id);
    void onRestaurantReturnbtn(QString u_id);
    void onBarSalesbtn(QString u_id);
    void onBarreturnsbtn(QString u_id);
    //the clock view sales
    void   onReportViewClockOpen();
    void   onReportviewClockclosed();
private:

    void PopulateRestSalemodel();
    void PopulateBarSalemodel();
    void PopulateRestReturnmodel();
    void PopulateBarReturnmodel();
    void PopulateUserViewmodel();
    void PopulateorderTablesmodel();
    void PopulateBarorderItesm();
    void PopulateRestorderItesm();
    void populateitemView();
    void PopulateWaiterSalemodel(QString id);
    void PopulateWaiterReturnmodel();
    void Readsettings();
    void populatethegroups();
    class Implimentation;
    QScopedPointer<Implimentation>implimentation;
    QString BusinessName;
    bool dbconnecteds;
    QString m_username;
    QString Role;
    QString userid;
    QString m_OrderCategory;
    QString m_Category;
    QString m_Clockin;
    QString m_OrderNumber;
    QString m_ordbarnum;
    QString m_ordrestNum;
    QTimer *timer;
    
};
}
#endif // MASTERCONTROLLER_H

#include "mastercontroller.h"
#include<QDebug>
namespace Controller {


class MasterController::Implimentation
{
public:
    Implimentation(MasterController* _masterc,Database_controller *_maindatabaec,Pos_Users *pauseuser)
        :masterC(_masterc),newuser(pauseuser),database(_maindatabaec)
    {
        navigation=new NavigationController(masterC);
        newuser=new Pos_Users(masterC);
        createuse=new DataBase::UserEntry(masterC,_maindatabaec,newuser);
        database=new Database_controller(masterC);
        createStock=new DataBase::Stockdetailsdb(masterC,_maindatabaec,newstock);
        newstock=new Models::StockDetails(masterC);
        newTime=new Models::MyClockTime(masterC);
        createtime=new DataBase::UserClockdb(masterC,_maindatabaec,newTime);
        //Rmodel=new Models::ReportTablemodel(masterC);
        // db=new DataBase::ReportTableDetailsDb(masterC,Rmodel,_maindatabaec);
        BarSaleReport=new BarReportModel(masterC);
        RestSaleReport=new BarReportModel(masterC);
        WaiterSaleReport=new BarReportModel(masterC);
        RestReturnReport=new Models::ReturnsModel (masterC);
        BarReturnReport=new Models::ReturnsModel (masterC);
        WaiterReturnReport=new Models::ReturnsModel (masterC);
        UsersViewModel=new Models::USerViewModel(masterC);
        OrderTablemodels=new Models::OrderTablemodel(masterC);
        OrderBarItemsModels =new  Models::OrderItemsModels (masterC);
        OrderRestItemsModels=new Models::OrderItemsModels(masterC);
        itemviewsmodel= new Models::ItemViewModels(masterC);
        Appsettings=new Models::AppSettings(masterC);
        workingHours=new Models::WorkingHoursViewsModle(masterC);
        OrderDrinks=new Models::OrderItemsModels(masterC);
        OrderBreakfast=new Models::OrderItemsModels(masterC);
        Ordermeal=new Models::OrderItemsModels(masterC);
        OrderSnacks=new Models::OrderItemsModels(masterC);
        Saveorders=new Models::OrderUp(masterC);
        SalesorderedDetails=new Models::OrderItemsModels(masterC);
        salecat=new Models::SalesCat(masterC);
        restSales=new Models::Sales(masterC);
        barSales=new Models::Sales(masterC);
        barreturn=new Models::Sales(masterC);
        resreturns=new Models::Sales(masterC);
        //waiter
        WBarSaleReport=new BarReportModel(masterC);
        WRestSaleReport=new BarReportModel(masterC);
        WRestReturnReport=new Models::ReturnsModel (masterC);
        WBarReturnReport=new Models::ReturnsModel (masterC);
        CRestReturnReport=new Models::ReturnsModel(masterC);
        CRestSaleReport=new Models::BarReportModel(masterC);
        waiterModelView=new Models::WaiterModelView(masterC);
       ordertables=new Models::OrderTablemodel(masterC);

       //the new data
       /*--------------above-----------------*/
       restaurantsales_id=new Models::BarReportModel(masterC);
       barsales_id =new Models::BarReportModel(masterC);
       restaurantreturns_id=new Models::ReturnsModel(masterC);
       barreturns_id=new Models::ReturnsModel(masterC);

       //implimentation of clock view variable
       restaurantsales_clock_id=new Models::BarReportModel(masterC);
       barsales_clock_id=new Models::BarReportModel(masterC);
       restaurantreturns_clock_id=new Models::ReturnsModel(masterC);
       barreturns_clock_id=new Models::ReturnsModel(masterC);

    }
    NavigationController *navigation{nullptr};
    MasterController *masterC{nullptr};
    Pos_Users *newuser{nullptr};
    Database_controller *database{nullptr};
    DataBase::UserEntry* createuse{nullptr};
    DataBase::Stockdetailsdb *createStock{nullptr};
    Models::StockDetails *newstock{nullptr};
    Models::MyClockTime* newTime{nullptr};
    DataBase::UserClockdb* createtime{nullptr};
    Models::BarReportModel *BarSaleReport{nullptr};
    Models::BarReportModel *RestSaleReport{nullptr};
    Models::BarReportModel *WaiterSaleReport{nullptr};
    Models::ReturnsModel *RestReturnReport{nullptr};
    Models::ReturnsModel *BarReturnReport{nullptr};
    Models::ReturnsModel *WaiterReturnReport{nullptr};
    Models::USerViewModel *UsersViewModel{nullptr};
    Models::OrderTablemodel* OrderTablemodels{nullptr};
    Models::OrderItemsModels* OrderBarItemsModels{nullptr};
    Models::OrderItemsModels* OrderRestItemsModels{nullptr};

    Models::OrderItemsModels* SalesorderedDetails{nullptr};
    Models::OrderItemsModels* OrderDrinks{nullptr};
    Models::OrderItemsModels* OrderBreakfast{nullptr};
    Models::OrderItemsModels* Ordermeal{nullptr};
    Models::OrderItemsModels* OrderSnacks{nullptr};
    Models::OrderUp* Saveorders{nullptr};
    Models::SalesCat *salecat{nullptr};
    Models::ItemViewModels* itemviewsmodel{nullptr};
    Models::AppSettings *Appsettings{nullptr};
    Models::WorkingHoursViewsModle* workingHours{nullptr};
    Models::Sales *restSales{nullptr};
    Models::Sales *barSales{nullptr};
    Models::Sales *barreturn{nullptr};
    Models::Sales *resreturns{nullptr};
    //waiter
    Models::BarReportModel *WBarSaleReport{nullptr};
    Models::BarReportModel *WRestSaleReport{nullptr};
    Models::ReturnsModel *WRestReturnReport{nullptr};
    Models::ReturnsModel *WBarReturnReport{nullptr};
    Models::ReturnsModel  *CRestReturnReport{nullptr};
    Models::BarReportModel *CRestSaleReport{nullptr};
    Models::WaiterModelView *waiterModelView{nullptr};
    Models::OrderTablemodel *ordertables{nullptr};



    /*--------------bottom-----------------*/
    Models::BarReportModel *restaurantsales_id{nullptr};
    Models::BarReportModel *barsales_id{nullptr};
    Models::ReturnsModel *restaurantreturns_id{nullptr};
    Models::ReturnsModel *barreturns_id{nullptr};


    //the clock sales view details
     Models::BarReportModel *restaurantsales_clock_id{nullptr};
     Models::BarReportModel *barsales_clock_id{nullptr};
     Models::ReturnsModel *restaurantreturns_clock_id{nullptr};
     Models::ReturnsModel *barreturns_clock_id{nullptr};

};
MasterController::MasterController(QObject *parent, Database_controller *maincontroler, Pos_Users *newUser) :
    QObject(parent)
{
    implimentation.reset(new Implimentation(this,maincontroler,newUser));
    getorderNum();
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this,&MasterController::updateordervier);
    if(implimentation->salecat->counter()==0){
        timer->stop();
    }
    timer->start(1000);

    populatethegroups();
    Readsettings();
    PopulateBarorderItesm();
    PopulateRestorderItesm();
    PopulateRestSalemodel();
    PopulateBarSalemodel();
    PopulateRestReturnmodel();
    PopulateBarReturnmodel();
    PopulateUserViewmodel();
    PopulateorderTablesmodel();
    populateitemView();
    //  PopulateWaiterSalemodel(); please note this is not located
    PopulateWaiterReturnmodel();

    getorders();

}
MasterController::~MasterController()
{


}

const QString MasterController::username() const
{
    return m_username;

}

const QString MasterController::userRole() const
{
    return Role;

}
const QString MasterController::message() const
{
    return BusinessName;

}

const QString MasterController::Userid() const
{
    return userid;
}

const QString MasterController::clockin() const
{
    return m_Clockin;
}

const QString MasterController::OrderCategory() const
{
    return m_OrderCategory;
}

const QString MasterController::Category() const
{
    return m_Category;
}

void MasterController::sETOrderCategory(QString category)
{
    m_OrderCategory.clear();
    m_OrderCategory=category;
}

NavigationController *MasterController::navigationController()const
{
    return implimentation->navigation;

}

Pos_Users *MasterController::posuser()
{
    return implimentation->newuser;

}

StockDetails *MasterController::StockDetails()
{
    return implimentation->newstock;

}

DataBase::UserEntry *MasterController::createuser()
{
    return implimentation->createuse;
}

DataBase::Stockdetailsdb *MasterController::createStock()
{
    return implimentation->createStock;
}

DataBase::UserClockdb *MasterController::createTime()
{
    return implimentation->createtime;
}

MyClockTime *MasterController::NewTime()
{
    return implimentation->newTime;
}

OrderUp *MasterController::Saveorders()
{
    return implimentation->Saveorders;
}

BarReportModel *MasterController::WaiterSaleReport()
{
    return  implimentation->WaiterSaleReport;
}

ReturnsModel *MasterController::WaiterReturnReport()
{
    return implimentation->WaiterReturnReport;
}

BarReportModel *MasterController::RestSaleReport()
{
    return implimentation->RestSaleReport;
}

BarReportModel *MasterController::BarSaleReport()
{
    return implimentation->BarSaleReport;
}

ReturnsModel *MasterController::RestReturnReport()
{
    return implimentation->RestReturnReport;
}

ReturnsModel *MasterController::BarReturnReport()
{
    return implimentation->BarReturnReport;
}

USerViewModel *MasterController::UsersViewModel()
{
    return implimentation->UsersViewModel;
}

OrderTablemodel *MasterController::OrderTablemodels()
{
    return  implimentation->OrderTablemodels;
}

OrderItemsModels *MasterController::OrderBarItemsModels()
{
    return implimentation->OrderBarItemsModels;

}

OrderItemsModels *MasterController::OrderRestItemsModels()
{
    return implimentation->OrderRestItemsModels;
}

OrderItemsModels *MasterController::OrderDrinks()
{
    return  this->implimentation->OrderDrinks;
}

OrderItemsModels *MasterController::OrderBreakfast()
{
    return  this->implimentation->OrderBreakfast;
}

OrderItemsModels *MasterController::Ordermeal()
{
    return  this->implimentation->Ordermeal;
}

OrderItemsModels *MasterController::OrderSnacks()
{
    return  this->implimentation->OrderSnacks;
}

OrderItemsModels *MasterController::SalesorderedDetails()
{
    return  this->implimentation->SalesorderedDetails;
}

ItemViewModels *MasterController::itemviewsmodel()
{
    return implimentation->itemviewsmodel;
}

AppSettings *MasterController::Appsettings()
{
    return implimentation->Appsettings;
}

SalesCat *MasterController::salecat()
{
    return  implimentation->salecat;
}

Sales *MasterController::restSales()
{
    return implimentation->restSales;
}

Sales *MasterController::barSales()
{
    return implimentation->barSales;
}

Sales *MasterController::restreturn()
{
    return implimentation->resreturns;
}

Sales *MasterController::barreturn()
{
    return implimentation->resreturns;
}

BarReportModel *MasterController::WRestSaleReport()
{
    return implimentation->WRestSaleReport;
}

BarReportModel *MasterController::WBarSaleReport()
{
    return implimentation->WBarSaleReport;
}

ReturnsModel *MasterController::WRestReturnReport()
{
    return implimentation->WRestReturnReport;
}

ReturnsModel *MasterController::WBarReturnReport()
{
    return implimentation->WBarReturnReport;
}

ReturnsModel *MasterController::CRestReturnReport()
{
    return implimentation->CRestReturnReport;
}

BarReportModel *MasterController::CRestSaleReport()
{
    return implimentation->CRestSaleReport;
}

WaiterModelView *MasterController::waiterModelView()
{
    return implimentation->waiterModelView;
}

OrderTablemodel *MasterController::ordertables()
{
    return implimentation->ordertables;
}

BarReportModel *MasterController::restaurantsales_id()
{
    return implimentation->restaurantsales_id;
}

BarReportModel *MasterController::barsales_id()
{
    return implimentation->barsales_id;
}

ReturnsModel *MasterController::restaurantreturns_id()
{
    return implimentation->restaurantreturns_id;
}

ReturnsModel *MasterController::barreturns_id()
{
    return implimentation->barreturns_id;
}

BarReportModel *MasterController::restaurantsales_clock_id()
{
    return implimentation->restaurantsales_clock_id;
}

BarReportModel *MasterController::barsales_clock_id()
{
    return implimentation->barsales_clock_id;
}

ReturnsModel *MasterController::restaurantreturns_clock_id()
{
    return implimentation->restaurantreturns_clock_id;
}

ReturnsModel *MasterController::barreturns_clock_id()
{
    return implimentation->barreturns_clock_id;
}



void MasterController::gettimePoint()
{

}



void MasterController::onLogin(QString use,QString pass)
{
    m_username="";
    Role="";
    auto ress= this->implimentation->database->logincheck(use,pass);
    if(!ress.isEmpty()){
        m_username=ress.at(1);
        Role= ress.at(2).toLower();
        userid=ress.at(0);
        if(Role.toLower()=="bar cashier"){
            this->navigationController()->goCreateCashierView();
        }
        if(Role.toLower()=="waiter"){
            this->navigationController()->goCreateSalesView();
        }
        else if(Role.toLower()=="bar cashier"){
            this->navigationController()->goCreateCashierView();
        }
        else if(Role.toLower()=="hotel cashier"){
            this->navigationController()->goCreateCashierView();
        }
        else  if(Role.toLower()=="manager"){
            this->navigationController()->goCreateManagerView();
        }
        else if(Role.toLower()=="supervisor"||"director"){
            this->navigationController()->goCreateManagerView();
        }
        else if(Role.toLower()=="hotel cashier"){
            this->navigationController()->goCreateCashierView();
        }
    }

    else {
        qDebug()<<"wrong password or username";

    }
}

void MasterController::onLogout()
{
    m_username="";
    Role="";
    this->navigationController()->goCreateLoginoutView();
    this->navigationController()->goCreateLoginView();
}
void MasterController::onClockin(QString use,QString pass)
{
    m_username.clear();
    Role.clear();
    userid.clear();
    auto ress= this->implimentation->database->logincheck(use,pass);
    if(!ress.isEmpty()){
        m_username=ress.at(1);
        Role= ress.at(2).toLower();
        userid=ress.at(0);
        this->navigationController()->goCreateClockview();
        PopulateWaiterSalemodel(ress.at(0));
    }
    else {
        qDebug()<<"wrong password or username";
    }
}
void MasterController::onCreateuser()
{
    qDebug() << "You executed the Save command!";
    implimentation->database->CreateRow("users",implimentation->newuser->userid(),implimentation->newuser->toJson());
    qDebug() << "New client saved.";
}
void MasterController::onUpdateUser()
{
    implimentation->database->updateRow("users",implimentation->newuser->userid(),implimentation->newuser->toJson());
}

void MasterController::onCreateStock()
{
    implimentation->database->CreateRow("Stocks",implimentation->newstock->Itemid(),implimentation->newstock->toJson());
    qDebug() <<"new stock created";
}

void MasterController::onneworder()
{
    qDebug()<<"order category"<<m_OrderCategory;
    if(m_OrderCategory=="Bar"){
        implimentation->database->CreateorderRow("bar_orders",implimentation->Saveorders->toJson());
        qDebug()<<"new bar order created";
    }
    else {
        implimentation->database->CreateorderRow("restaurant_orders",implimentation->Saveorders->toJson());
        qDebug()<<"new Restaurant order created";
    }

}


void MasterController::onSaleSaved()
{   void Readsettings();
    if(m_Category=="Bar"){
        implimentation->database->CreateorderRow("bar_sales",implimentation->barSales->toJson());
        qDebug() <<"new bar sale created";
    }
    if(m_Category=="Restaurant"){
        implimentation->database->CreateorderRow("restaurant_sales",implimentation->restSales->toJson());
        qDebug() <<"new rest sale created";
    }
    getorders();
}

void MasterController::onReturnorder()
{

    if(m_Category=="Bar"){
        implimentation->database->CreateorderRow("bar_returns",implimentation->barSales->toJson());
        qDebug() <<"new bar return created";
    }
    if(m_Category=="Restaurant"){
        implimentation->database->CreateorderRow("restaurant_returns",implimentation->restSales->toJson());
        qDebug() <<"new rest return created";
    }
}
void MasterController::onCreateclock()
{
    implimentation->database->CreateRow("users_clock",implimentation->newTime->GetUserid(),implimentation->newTime->toJson());
    qDebug() <<"new Clock created";
}
void MasterController::onClockout()
{

    qDebug()<<"m_Clockin: "<<m_Clockin;
    implimentation->database->updateclockRow(userid+QDate::currentDate().toString("MMMMdyyyy"),implimentation->newTime->toJson());
}
void MasterController::onBClockclicked()
{
    implimentation->navigation->goCreateLoginView();
}

void MasterController::onLoadingReport()
{
    //auto data=implimentation->database->readTable("bar_sales");
    QList<Sales>m_items;

    //    //this->implimentation->Rmodel->setLData(sales);
}

void MasterController::onItemdelete(QString id,int index)
{
    implimentation->database->DeleteRow("stocks",id);
    implimentation->itemviewsmodel->deleteItem(index);
}

void MasterController::onDroprow(QString tablename, QString id,int index)
{
    implimentation->database->DeleteRowS(tablename,id);
    implimentation->salecat->remove(index);
}

void MasterController::onDeletPosuser(QString id, int index)
{   implimentation->UsersViewModel->removeUser(index);
    implimentation->database->DeleteRow("users",id);
}

void MasterController::onUpdateuser(QString uid)
{
    implimentation->database->updateRow("users",uid,implimentation->newuser->toJson());
}

void MasterController::onSettings()
{
    QJsonDocument docsettings;
    QFile file("settings.txt");
    docsettings.setObject( implimentation->Appsettings->toJson());
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&file);
    out<< docsettings.toJson(); //.toBinaryData();
    file.flush();
    file.close();
}

void MasterController::onGetOrderNumber()
{
    getorderNum();
}

void MasterController::onSearchBarReturn(QString Orederid)//returns
{
    //  need to convert from json document ot vector;
    auto data= this->implimentation->database->readTable_Id("bar_Returns",Orederid);
    //implimentation->BarReturnReport->populate();

}

void MasterController::onSearchBarSales(QString Date)
{
    auto data=implimentation->database->readTable_Date("bar_sales",Date);
    //implimentation->BarSaleReport->setSales(data);
}

void MasterController::onSearchRestaurantSales(QString Date)
{
    auto data= this->implimentation->database->readTable_Date("restaurant_orders",Date);
    // implimentation->RestReturnReport->populate();
}

void MasterController::onSearchRestaurantReturn(QString Orederid)//returtn
{
    auto data= this->implimentation->database->readTable_Id("restaurant_Returns",Orederid);
    // implimentation->RestReturnReport->populate();

}

void MasterController::onViewUserclock(QString userId)
{
    auto data=this->implimentation->database->readTable_usersclock(userId);
    implimentation->workingHours->populate(data);
}

void MasterController::updateordervier()
{

}

void MasterController::onUpdatestockusers()
{
    auto data=implimentation->database->readTable_Users("users","","");
    this->implimentation->UsersViewModel->populateusers(data);
    auto datas=implimentation->database->readTable_stock("");
    this->implimentation->itemviewsmodel->populate(datas);

}

void MasterController::onCashierviewsales(QString userid)
{
    if(m_Category=="Bar")
    {
        auto barSales=this->implimentation->database->readTablebar_sales("bar_sales",userid,"");
        this->implimentation->WBarSaleReport->setSales(barSales);

        auto barReturn= this->implimentation->database->readTable_returns("bar_returns",userid,"");
        this->implimentation->WBarReturnReport->populate(barReturn);
    }
    else
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  {
        auto restreturns=this->implimentation->database->readTable_returns("restaurant_returns",userid,"");
        this->implimentation->WRestReturnReport->populate(restreturns);

        auto restsale=this->implimentation->database->readTablebar_sales("restaurant_sales",userid,"");
        this->implimentation->WRestSaleReport->setSales(restsale);
    }
}

void MasterController::onLoadCashierView()
{
    auto data=this->implimentation->database->readWaiter();
    this->implimentation->waiterModelView->populate(data);
}

void MasterController::onReportViewOpen()
{
    //populating the restaurant sale from db
    auto RS_data=implimentation->database->readrestaurantsale_id("db_name","u_id");
    implimentation->restaurantsales_id->setSales(RS_data);
    //populate restaurant returns from db
    auto Rr_data=implimentation->database->readrestaurantreturns_id("db_name","u_id");
    implimentation->restaurantreturns_id->populate(Rr_data);
    //populate bar sales from db
    auto Bs_data=implimentation->database->readbarsales_id("db_name","u_id");
    implimentation->barsales_id->setSales(RS_data);
    //populate bar returns from db
    auto Br_data=implimentation->database->readbarreturns_id("db_name","u_id");
    implimentation->barreturns_id->populate(Br_data);
}

void MasterController::onReportviewclosed()
{
    //delete the restaurant sales located memory pointer
   // implimentation->restaurantsales_id->FreeMm();//a function to free all memory alocated
    delete implimentation->restaurantsales_id;


    //delete the restaurant returns located memory
   // implimentation->restaurantreturns_id->FreeMm();//a function to free all memory alocated
    delete implimentation->restaurantreturns_id;
    //delete the Bar sales located memory
   // implimentation->barsales_id->FreeMm();//a function to free all memory alocated
    delete implimentation->barsales_id;
    //delete the Bar Returns located memory
  //  implimentation->barreturns_id->FreeMm();//a function to free all memory alocated
    delete implimentation->barreturns_id;

}

void MasterController::onRestaurantSalesbtn(QString u_id)
{
    auto RS_data=implimentation->database->readrestaurantsale_id("db_name",u_id);
    implimentation->restaurantsales_id->setSales(RS_data);
}

void MasterController::onRestaurantReturnbtn(QString u_id)
{
    //populate restaurant returns from db
    auto Rr_data=implimentation->database->readrestaurantreturns_id("db_name",u_id);
    implimentation->restaurantreturns_id->populate(Rr_data);
}

void MasterController::onBarSalesbtn(QString u_id)
{
    //populate bar sales from db
    auto Bs_data=implimentation->database->readbarsales_id("db_name",u_id);
    implimentation->barsales_id->setSales(Bs_data);
}

void MasterController::onBarreturnsbtn(QString u_id)
{
    //populate bar returns from db
    auto Br_data=implimentation->database->readbarreturns_id("db_name",u_id);
    implimentation->barreturns_id->populate(Br_data);
}

void MasterController::onReportViewClockOpen()
{
    //the clock sales view detail
    //populating the restaurant sale from db
    auto RS_data=implimentation->database->readrestaurantsale_id("db_name","u_id");
    implimentation->restaurantsales_clock_id->setSales(RS_data);
    //populate restaurant returns from db
    auto Rr_data=implimentation->database->readrestaurantreturns_id("db_name","u_id");
    implimentation->restaurantreturns_clock_id->populate(Rr_data);
    //populate bar sales from db
    auto Bs_data=implimentation->database->readbarsales_id("db_name","u_id");
    implimentation->barsales_clock_id->setSales(RS_data);
    //populate bar returns from db
    auto Br_data=implimentation->database->readbarreturns_id("db_name","u_id");
    implimentation->barreturns_clock_id->populate(Br_data);
}

void MasterController::onReportviewClockclosed()
{

    /* -------------> steps to delete and free memory<--------------->*/
/*
    delete (the data type)
    (data type)=nullprt;

    //deleting an array
    delete[] (type);
*/
    //delete the restaurant sales located memory pointer
//    implimentation->restaurantsales_clock_id->FreeMm();//a function to free all memory alocated
    delete implimentation->restaurantsales_clock_id;
    implimentation->restaurantsales_clock_id=nullptr;
    //delete the restaurant returns located memory
   // implimentation->restaurantreturns_clock_id->FreeMm();//a function to free all memory alocated
    delete implimentation->restaurantreturns_clock_id;
     implimentation->restaurantreturns_clock_id=nullptr;
    //delete the Bar sales located memory
    //implimentation->barsales_clock_id->FreeMm();//a function to free all memory alocated
    delete implimentation->barsales_clock_id;
    implimentation->barsales_clock_id=nullptr;
    //delete the Bar Returns located memory
   // implimentation->barreturns_clock_id->FreeMm();//a function to free all memory alocated
    delete implimentation->barreturns_clock_id;
     implimentation->barreturns_clock_id=nullptr;
}

void MasterController::getorderNum()
{

    m_ordbarnum=implimentation->database->getorderNumber("bar_orders");
    m_ordrestNum=implimentation->database->getorderNumber("restaurant_orders");
}

void MasterController::settheclock()
{
    m_Clockin=implimentation->database->readclock(userid+QDate::currentDate().toString("MMMMdyyyy"));

}

void MasterController::Readsettings()
{
    QJsonDocument data;
    QFile file("settings.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    while (!file.atEnd()) {
        data =QJsonDocument::fromJson(file.readAll());
    }
    m_Category=data["AppCategorly"].toString();
    BusinessName=data["BusinessName"].toString();
}

void MasterController::populatethegroups()
{
    auto drinksdata= implimentation->database->readTable_orders("stock","","Drinks");
    auto Breakfastdata= implimentation->database->readTable_orders("stock","","Breakfast");
    auto mealdata= implimentation->database->readTable_orders("stock","","Heavy meal");
    auto Snacksdata= implimentation->database->readTable_orders("stock","","Snacks");
    this->implimentation->Ordermeal->populate(mealdata);
    this->implimentation->OrderDrinks->populate(drinksdata);
    this->implimentation->OrderBreakfast->populate(Breakfastdata);
    this->implimentation->OrderSnacks->populate(Snacksdata);
}

QString MasterController::getClockin() const
{
    return m_Clockin;
}

void MasterController::setClockin(const QString &Clockin)
{
    m_Clockin = Clockin;
}

void MasterController::onLoginsystemsales()
{

    auto restreturns= this->implimentation->database->readTable_returns("restaurant_returns",userid,"");
    this->implimentation->WRestReturnReport->populate(restreturns);

    auto barSales=this->implimentation->database->readTablebar_sales("bar_sales",userid,"");
    this->implimentation->WBarSaleReport->setSales(barSales);

    auto restsale=this->implimentation->database->readTablebar_sales("restaurant_sales",userid,"");
    this->implimentation->WRestSaleReport->setSales(restsale);

    auto barReturn= this->implimentation->database->readTable_returns("bar_returns",userid,"");
    this->implimentation->WBarReturnReport->populate(barReturn);
    for(auto &a:restsale){
        qDebug()<<"the list size"<<restsale.size();
        qDebug()<<a.Date<<a.Rno<<a.Date<<a.Servedby<<a.totalcost;
    }

}

QString MasterController::getOrdrestNum() const
{
    return m_ordrestNum;
}

void MasterController::setOrdrestNum(const QString &ordrestNum)
{
    m_ordrestNum = ordrestNum;
}

QString MasterController::getOrdbarnum() const
{
    return m_ordbarnum;
}

void MasterController::setOrdbarnum(const QString &ordbarnum)
{
    m_ordbarnum = ordbarnum;
}

QString MasterController::getOrderNumber() const
{
    return m_OrderNumber;
}

void MasterController::setOrderNumber(const QString &OrderNumber)
{
    m_OrderNumber = OrderNumber;
}

void MasterController::getorders()
{
    if(m_Category=="Bar")
    {
        auto data= implimentation->database->readtableorders("bar_orders");
        implimentation->salecat->populate(data);

    }
    if(m_Category=="Restaurant")
    {
        auto data= implimentation->database->readtableorders("restaurant_orders");
        implimentation->salecat->populate(data);
    }

}
void MasterController::PopulateRestSalemodel()
{
    auto data=this->implimentation->database->readTablebar_sales("restaurant_sales","","");
    this->implimentation->RestSaleReport->setSales(data);
}
void MasterController::PopulateBarSalemodel()
{
    auto data=this->implimentation->database->readTablebar_sales("bar_sales","","");
    this->implimentation->BarSaleReport->setSales(data);
}
void MasterController::PopulateRestReturnmodel()
{
    auto data= this->implimentation->database->readTable_returns("restaurant_returns","","");
    this->implimentation->RestReturnReport->populate(data);
}
void MasterController::PopulateBarReturnmodel()
{
    auto data= this->implimentation->database->readTable_returns("bar_returns","","");
    this->implimentation->BarReturnReport->populate(data);
}

void MasterController::PopulateUserViewmodel()
{
    auto data=implimentation->database->readTable_Users("users","","");
    this->implimentation->UsersViewModel->populateusers(data);
}

void MasterController::PopulateorderTablesmodel()
{ auto data=implimentation->database->readtables();

}
void MasterController::PopulateBarorderItesm()
{
    auto data=implimentation->database->readTable_orders("stocks","Bar","");
    this->implimentation->OrderBarItemsModels->populate(data);
}
void MasterController::PopulateRestorderItesm()
{
    auto data=implimentation->database->readTable_orders("stocks","Restaurant","");
    this->implimentation->OrderRestItemsModels->populate(data);

}
void MasterController::populateitemView()
{
    auto data=implimentation->database->readTable_stock("");
    this->implimentation->itemviewsmodel->populate(data);
}
void MasterController::PopulateWaiterSalemodel(QString id)
{



}
void MasterController::PopulateWaiterReturnmodel()
{

    //this->implimentation->WaiterReturnReport->populate(data);
}
}

#include <QApplication>
#include <QQmlApplicationEngine>
#include<QtQuickControls2>
#include<QQmlContext>
#include<QIcon>
//controls
#include<Controller/mastercontroller.h>
#include<Controller/navigation-controller.h>
#include<Controller/database_controller.h>
//data
#include<Data/Data_collection.h>
#include<Data/string_data.h>
#include<Data/double_data.h>
#include<Data/int_data.h>
//models
#include<Models/pos_users.h>
#include<Models/stockdetails.h>
#include<Models/sales.h>
#include<Models/myclocktime.h>
#include<Database/userentry.h>
#include<Models/reporttablemodel.h>
#include<Models/ReportModel.h>
#include<Models/ordercat.h>
#include<Models/appsettings.h>
#include<Models/salescat.h>
#include<Models/waitermodelview.h>
#include<Models/salesviewmodel.h>
#include<Models/returnviewmodel.h>
#include<Models/workinghoursviewsmodle.h>
#include<Models/orderup.h>
#include<Models/salesdetailsmodel.h>
#include<Printer/printecontrol.h>

#include<Database/userentry.h>
#include<Database/reporttabledetailsdb.h>
#include<Controller/Main_Databasecontroller.h>
#include<Controller/database_controller.h>
#include<Delegates/BarReportDelegate.h>


int main(int argc, char *argv[])
{

    auto icon= QImage("../images/logo.png");
    // qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon( QPixmap::fromImage(icon)));
    qmlRegisterType<Controller::MasterController>("pos",1,0,"Mastercontroller");
    qmlRegisterType<Controller::NavigationController>("pos", 1, 0,"NavigationController");
    qmlRegisterType<Controller::Database_controller>("pos", 1, 0,"Databasecontroller");
    qmlRegisterType<Data::String_Data>("pos", 1, 0,"String_Data");
    qmlRegisterType<Data::Int_data>("pos", 1, 0,"Int_data");
    qmlRegisterType<DataBase::ReportTableDetailsDb>("pos",1,0,"ReportTableDB");
    qmlRegisterType<Models::ReportTablemodel>("pos",1,0,"ReportTable");
    qmlRegisterType<Models::BarReportModel>("pos",1,0,"BarReportModel");
    qmlRegisterType<Delegate::BarReportDelegate>("pos",1,0,"BarReportDelegate");
    qmlRegisterType<Models::SalesDetailsModel>("pos",1,0,"SalesDetailsModel");
    qmlRegisterType<Models::OrderUp>("pos",1,0,"Saveorders");
    qmlRegisterType<Models::WorkingHoursViewsModle>("pos", 1, 0,"WorkingHoursViewsModle");
    qmlRegisterType<Models::ReturnViewModel>("pos", 1, 0,"ReturnViewModel");
    qmlRegisterType<Models::SalesViewModel>("pos", 1, 0,"SalesViewModel");
    qmlRegisterType<Models::WaiterModelView>("pos", 1, 0,"WaiterModelView");
    qmlRegisterType<Models::SalesCat>("pos", 1, 0,"SalesCat");
    qmlRegisterType<Models::OrderCat>("pos", 1, 0,"OrderCat");
    qmlRegisterType<Models::Pos_Users>("pos", 1, 0,"Pos_Users");
    qmlRegisterType<Models::StockDetails>("pos", 1, 0,"StockDetails");
    qmlRegisterType<Models::AppSettings>("pos", 1, 0,"AppSettings");
    qmlRegisterType<Models::Sales>("pos",1,0,"Sales");
    qmlRegisterType<Models::MyClockTime>("pos",1,0,"Myclock");
    qmlRegisterType<DataBase::UserEntry>("pos",1,0,"Duser");
    DataBase::UserEntry dbuserSave;
    Printer::PrinteControl printers;
    Controller::MasterController MasterController;
    QQmlApplicationEngine engine;
    QQuickStyle::setStyle("Universal");
    engine.rootContext()->setContextProperty("dbuserSave",&dbuserSave);
    engine.rootContext()->setContextProperty("PrinteControl",&printers);
    engine.rootContext()->setContextProperty("masterController",&MasterController);
    engine.load(QUrl(QStringLiteral("qrc:/Views/main.qml")));
    return app.exec();

}

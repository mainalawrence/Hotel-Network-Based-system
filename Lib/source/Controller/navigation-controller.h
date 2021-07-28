#ifndef NAVIGATIONCONTROLLER_H
#define NAVIGATIONCONTROLLER_H


#include <QObject>
#include <Pos_Lib_global.h>


namespace Controller{
class POS_LIB_EXPORT NavigationController:public QObject
{
    Q_OBJECT
public:
    explicit NavigationController(QObject* parent = nullptr)
        :QObject(parent)
    {}
signals:
    void goCreateWaiterView();
    void goCreateManagerView();
    void goCreateLoginView();
    void goCreateWaiter();
    void goCreateEmployeeView();
    void goCreateSettingsView();
    void goCreateCashierView();
    void goCreateReturnView();
    void goCreateReportView();
    void goCreateSalesView();
    void goCreateStockitemsView();
    void goCreateClockview();
    void goCreateLoginoutView();
    void goCreatestartView();
    void godeletprevius();
};
}
#endif

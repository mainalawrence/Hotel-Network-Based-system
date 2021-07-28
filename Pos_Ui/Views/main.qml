import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import pos 1.0

ApplicationWindow {
    id:root
    visible: true
    width:1920
    height:1080
    title: masterController.ui_message
    Connections{
        target:masterController.ui_navigationController
        onGoCreateWaiterView:mainview.replace("Waiter.qml", StackView.Immediate)
        onGoCreateManagerView:mainview.replace("Manager.qml", StackView.Immediate)
        onGoCreateLoginView:mainview.push("Login.qml",StackView.Immediate)
        onGoCreateEmployeeView:mainview.replace("UserViewModel.qml", StackView.Immediate)
        onGoCreateSettingsView:mainview.replace("Settingsview.qml", StackView.Immediate)
        onGoCreateCashierView:mainview.replace("CashierWindow.qml", StackView.Immediate)
        onGoCreateReturnView:mainview.replace("ReturnsView.qml", StackView.Immediate)
        onGoCreateReportView:mainview.replace("ReportView.qml", StackView.Immediate)
        onGoCreateSalesView:mainview.replace("Sales.qml", StackView.Immediate)
        onGoCreateStockitemsView:mainview.replace("StockItems.qml", StackView.Immediate)
        onGoCreateClockview:mainview.replace("UserClockin.qml", StackView.Immediate)
        onGoCreateLoginoutView:mainview.clear()
    }
    StackView{
        id:mainview
        anchors.fill: parent
        initialItem: Qt.resolvedUrl("Login.qml")
    }
}


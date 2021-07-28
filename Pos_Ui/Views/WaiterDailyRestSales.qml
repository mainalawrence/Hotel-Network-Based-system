import QtQuick 2.0
import QtQuick.Controls 1.4

Item{
    anchors.fill: parent
    Rectangle{
        id:rectroot
        height: parent.height
        width: parent.width
        anchors.margins: 10
        TableView{
            anchors.fill: parent
            id:returnstable
            model:masterController.ui_WRestReturnReport
            TableViewColumn{
                role:'ReciteNo'
                title: "Recite No"
                width: 100


            }
            TableViewColumn{
                role:'totalcost'
                title: "Total cost"
                width: 100
            }
            TableViewColumn{
                role:'paytype'
                title: "Payment type"
                width: 100
            }
            TableViewColumn{
                role:'salesdate'
                title: "Date"
                width: 100
            }
            TableViewColumn{
                role:'soldby'
                title: "Waiter name"
                width: 100
            }
            TableViewColumn{
                role:'Details'
                title: "Details"
                width: parent.width- 700
            }
        }
    }
}

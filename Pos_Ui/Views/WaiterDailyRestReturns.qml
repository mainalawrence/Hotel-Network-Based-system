import QtQuick 2.0
import QtQuick.Controls 1.4

Item{
    anchors.fill: parent
    Rectangle{
        id:returnroot
        anchors.centerIn: parent
        anchors.margins: 10
        height: parent.height
        width: parent.width
        TableView{
            id:returnstable
             anchors.fill: parent
            height: returnroot.height
            width: returnroot.width-150
            model: masterController.ui_WRestReturnReport
            TableViewColumn{
                role:'orderNo'
                title: "Order No"
                width: 100
            }

            TableViewColumn{
                role:'amount'
                title: "Amount "
                width: 100
            }
            TableViewColumn{
                role:'totalcost'
                title: "Total Cost "
                width: 100
            }
            TableViewColumn{
                role:'date'
                title: "Date"
                width: 100
            }
            TableViewColumn{
                role:'waitersName'
                title: "Waiters Name"
                width: 100
            }
            TableViewColumn{
                role:'details'
                title: "Details"
                width: 100
            }
        }    }
}

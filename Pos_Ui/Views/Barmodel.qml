import QtQuick 2.0
import QtQuick.Controls 2.5
import pos 1.0

Item {
    OrderCat{
        id:ordercat
    }

    Rectangle{
        anchors.fill: parent
            GridView{
                id:view
                anchors.fill: parent
                cellHeight: 101
                cellWidth: 101
                model:masterController.ui_OrderBarItemsModels
                delegate: delegate
                clip: true
                focus: true
            }
        Component{
            id:delegate
            Rectangle{
                id:rect
                height:90
                width:90
                color:GridView.isCurrentItem?"red":"green"
                Text{
                    anchors.centerIn: parent
                    text:model.name + "\n"+ model.cost + " \n"+model.itemid+ "\n "+model.tax
                    font.pixelSize: 12
                    font.bold:true
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: ordercat.addonCat(model.name,1,model.cost,model.cost,model.tax)
                }
            }
        }
    }

}


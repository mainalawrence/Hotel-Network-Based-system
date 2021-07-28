import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Controls 1.4

Item {
    id: rootreturns

Page{
    id:creditepage
    Button{height: 30;width: 40;iconSource:"../images/home.png"  ;onClicked:{masterController.ui_navigationController.goCreateManagerView()}}
    visible:true
    anchors.fill: parent
    Frame{
        anchors.centerIn:parent
        height:parent.height-parent.height/4
        width:parent.width-400
        clip: true
        Column{
            anchors{
                top: parent.top
                horizontalCenter: parent.horizontalCenter
            }
            
        }
        Button{
            id:submitreturns
            text: "Enter"
            anchors.horizontalCenter: parent.horizontalCenter;
            anchors.bottom: parent.bottom
            onClicked: {

            }
        }

    }

}


}

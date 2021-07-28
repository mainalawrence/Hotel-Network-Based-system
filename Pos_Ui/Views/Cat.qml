import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import pos 1.0

Item {
    OrderCat{
        id:ordercat
    }
    Frame{
        anchors.fill: parent
        background:Rectangle{
            border.color: "black"
        }
        ListView {
            id:catview
            anchors.fill: parent
            spacing: 4
            clip: true
            model: ordercat
            delegate: numberDelegate
        }
    }
Component {
    id: numberDelegate
    Row{
        spacing:15
        Row{
            Label{clip:truncated ;text:model.name; topPadding:13;Text{anchors.centerIn: parent}}
            Button{text:"-"
                onClicked:ordercat.increaseAmount(model.index)
                 style: ButtonStyle {background: Rectangle {
                     implicitWidth:45
                     implicitHeight:40
                     radius: 5
                     border.color: "#000"
                }Text {
                     id: clearbtn
                     anchors.centerIn: parent
                     font.pixelSize:16
                     font.bold:true
                 }}}
            Rectangle{id:recamount;clip:true;height:40; width:30;Text{anchors.centerIn: parent; text:model.amount}}
            Button{text:"+"
                onClicked:{}
                 style: ButtonStyle {background: Rectangle {
                     implicitWidth:45
                     implicitHeight:40
                     radius: 5
                     border.color: "#000"
                }Text {
                     anchors.centerIn: parent
                     font.pixelSize:16
                     font.bold:true
                 }}}
            }

        Button{text:"Del";
            onClicked: ordercat.removefromCat(model.index)
             style: ButtonStyle {background: Rectangle {
                 implicitWidth:45
                 implicitHeight:40
                 radius: 5
                 border.color: "#000"
            }Text {
                 anchors.centerIn: parent
                 font.pixelSize:16
                 font.bold:true
             }}}
    }
}

}


import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3

Page {
    id:waiterpage
    header: ToolBar{
    width: parent.width
    spacing: 10
    Row{
        spacing: 5
    TextField{
        placeholderText: "   search"
        font.pixelSize: 12
        inputMethodHints:Qt.NoFocus

    }
    Button{
        id:searchbtn
        text: "Search"
        contentItem:Text{
            text:searchbtn.text
            font.pixelSize: 12
            color: "white"
        }
        background: Rectangle{
            width: searchbtn.width
            height: searchbtn.height
            color: "black"
        }
    }
}
}
 StackView{
     id:mainview
     anchors.fill: parent
     initialItem: qsTr("Hotelmodel.qml")
 }


}




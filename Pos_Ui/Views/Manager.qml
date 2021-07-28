import QtQuick 2.0
import QtQuick.Controls 2.5
import './Clock'

Page {
   // 578 800

    property int smallscreensizesize:200
    property int largescreensize:200
id:root
    header: ToolBar{
        padding: 30
        height: 100
        width: parent.width
        background: Rectangle{
            color: "gray"
        }

        Clock{
            id:id_root
        }

        Row{
            spacing: 10
            Label{
            text:"Welcome "+masterController.ui_username.toString().toUpperCase()// the name of the user
            }
        Column{
            id:datetime
            spacing: 3
            Text{
                text:Qt.formatDate(id_root.currentDate,"MMM/dd/yyyy")
                font.pixelSize:16
            }
            Text{
                text:Qt.formatTime(id_root.currentDate,"h:mm.s ap")
                font.pixelSize:16
            }
        }
    }
    }

    Frame{
        anchors.centerIn: parent
        anchors.topMargin:-100
        height:500
        width: maingride.width+50
        background: Rectangle{
            color: "white"
        }

        Grid{
            id:maingride
            clip: true
            anchors.centerIn: parent
            anchors.margins: 20
            spacing: 10
            columns:3
                Rectangle{
                    id:report
                    height: 160
                    width: root.height<700 ?370:smallscreensize
                    color:"#1B4166"
                    radius: 4
                    Image {
                        id: reportimg
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.Left

                        source: "../images/close.png"
                    }
                    Text{
                        id:txtreport
                        anchors.margins:50
                        anchors.left: reportimg.right
                        anchors.verticalCenter: parent.verticalCenter
                        text: qsTr("Report")
                        font.pointSize: 18
                        color: "white"
                        font.bold:true

                    }
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            masterController.ui_navigationController.goCreateReportView()
                        }
                    }
                }
                Rectangle{
                    id:employee
                    height: 160
                   width: root.height<900 ?370:smallscreensize
                    color: "#1B4166"
                    radius: 4
                    Image {
                        id: imgEmployee
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.Left
                        height: 50
                        width: 50
                        source: "../images/Employe.png"
                    }
                    Text{
                        id:txtEmployee
                        anchors.margins:50
                         anchors.left: imgEmployee.right
                         anchors.verticalCenter: parent.verticalCenter
                        text: qsTr("Employee")
                        font.pointSize: 18
                        color: "white"
                        font.bold:true
                    }
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            masterController.ui_navigationController.goCreateEmployeeView()
                        }
                    }
                }

                Rectangle{
                    id:sales
                    height: 160
                    width: root.height<900 ?370:smallscreensize
                    color: "#1B4166"
                    radius: 4
                    Image {
                        id: imgsales
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.Left
                        source: "../images/close.png"
                    }
                    Text{
                        id:txtsales
                        anchors.margins:50
                         anchors.left: imgsales.right
                         anchors.verticalCenter: parent.verticalCenter
                        text: qsTr("Sales")
                        font.pointSize: 18
                        color: "white"
                        font.bold:true
                    }
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                             masterController.ui_navigationController.goCreateCashierView()
                        }
                    }
                }



                Rectangle{
                    id:stock
                    height: 160
                   width: root.height<900 ?370:smallscreensize
                    color: "#1B4166"
                    radius: 4
                    Image {
                        id: imgstock
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.Left
                        source: "../images/close.png"
                    }
                    Text{
                        id:txtstock
                         anchors.left: imgstock.right
                         anchors.margins:50
                         anchors.verticalCenter: parent.verticalCenter
                        text: qsTr("Stock")
                        font.pointSize: 18
                        color: "white"
                        font.bold:true
                    }
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            masterController.ui_navigationController.goCreateStockitemsView();
                        }
                    }
                }

                Rectangle{
                    id:setting
                    height: 160
                    width: root.height<900 ?370:smallscreensize
                    color: "#1B4166"
                    radius: 4
                    Image {
                        id: imgsetting
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.Left
                        source: "../images/tools.png"
                        height: 50
                        width: 50

                    }
                    Text{
                        id:txtsetting
                        anchors.left: imgsetting.right
                        anchors.margins:50
                        anchors.verticalCenter: parent.verticalCenter
                        text: qsTr("Setting")
                        font.pointSize: 18
                        color: "white"
                        font.bold:true
                    }
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            masterController.ui_navigationController.goCreateSettingsView()
                        }
                    }
                }

                Rectangle{
                    id:logout
                    height: 160
                    width: root.height<900?370:smallscreensize
                    color: "#1B4166"
                    radius: 4
                    Image {
                        id: imglogout
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.Left
                        source: "../images/close.png"
                    }
                    Text{
                        id:txtlogout
                        anchors.left: imglogout.right
                        anchors.margins:50
                        anchors.verticalCenter: parent.verticalCenter
                        text: qsTr("Logout")
                        font.pointSize: 18
                        color: "white"
                        font.bold:true
                    }
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            Qt.quit()
                        }
                    }
                }
}}


}


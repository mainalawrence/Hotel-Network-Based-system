import QtQuick 2.0
import QtQuick 2.14
import QtQuick.Controls 2.3
import QtQuick.Controls 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 2.14

import "Clock"
import QtQml 2.14
import pos 1.0
Item{
    property string backGroundcolor: "gray"
    property bool masterview:true
    property bool salesbool:false
    property Myclock newclock:masterController.ui_NewTime
    Clock{
        id:id_root
    }

    Rectangle{
        id:mainrect
        visible:  masterview
        anchors.fill: parent
        color:backGroundcolor
        Frame{
            id:mainframe
            anchors.centerIn: parent
            height: 500
            width: 500
            background: Rectangle{
                border.color: "gray"
            }
            Label{
                id:userlbl
                text: "Welcome "+(masterController.ui_username).toLocaleUpperCase()
                font.pixelSize: 16
                anchors.top: parent.top
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottomMargin: 40
                anchors.topMargin:20
            }
            Button{
                text: "Sales"
                onClicked: {
                    salesbool=true
                    masterview=false
                }
            }

            Clock{
                id:timelbl
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: userlbl.bottom
                anchors.bottomMargin: 50
                anchors.topMargin:20
                height: 150
                width: 150
            }
            Grid{
                anchors.horizontalCenter: parent.horizontalCenter
                y:timelbl.y+200
                x:timelbl.x-clockinbtn.width
                spacing: 10
                rows: 2
                Button{
                    id:clockinbtn
                    width: 100
                    height: Text.height
                    text: " Clock In "
                    onClicked:{
                        masterController.onBClockclicked()
                        newclock.ui_Username.ui_value=masterController.ui_username
                        newclock.ui_userid.ui_value=masterController.ui_userid
                        newclock.ui_clockin.ui_value=clocklbl.text
                        masterController.onCreateclock()
                    }
                    }
                Button{
                    id:clockoutbtn
                    text:"Clock Out"
                    width: 100
                    height: Text.height
                    onClicked: {
                        masterController.settheclock()
                        console.log(masterController.ui_clockInn)
                        masterController.onBClockclicked()
                        newclock.ui_Username.ui_value=masterController.ui_username
                        newclock.ui_userid.ui_value=masterController.ui_userid
                        newclock.ui_clockin.ui_value=masterController.ui_clockInn
                        newclock.ui_Clockout.ui_value=clocklbl.text
                        masterController.onClockout()
                    }
                }
            }
            Label{
                id:clocklbl
                anchors.right: parent.right
                anchors.bottom:  parent.bottom
                anchors.rightMargin:10
                text:Qt.formatTime(id_root.currentDate,"h:m.s ap")
                color:"Black"
            }
        }

    }

    Item {
        visible: salesbool
        anchors.fill: parent
        Page{
            id:waitersales
            anchors.fill: parent
            SwipeView {
                id: view
                currentIndex: 1
                anchors.fill: parent

                Item {
                    id: secondPage3
                    Button{height: 30;width: 40;text:"<<"  ;onClicked:{masterController.ui_navigationController.goCreateLoginView()}}
                    Rectangle{
                        height: parent.height/16
                        anchors{
                            top: parent.top
                            horizontalCenter:  parent.horizontalCenter
                        } anchors.bottomMargin: 10
                        id:returnlabel
                        Text {
                            anchors.centerIn: parent
                            font.pixelSize: 14
                            text: qsTr("Restaurant Sales")
                        }
                    }
                    Frame{
                        anchors.top: returnlabel.bottom
                        anchors.horizontalCenter: parent.horizontalCenter
                        height: parent.height-parent.height/8
                        width: parent.width-parent.width/8
                        WaiterDailyRestSales{
                         anchors.fill: parent
                        }
                    }


                }

                Item {
                    id: secondPage33
                    Button{height: 30;width: 40;text:"<<"  ;onClicked:{masterController.ui_navigationController.goCreateLoginView()}}
                    Rectangle{
                        height: parent.height/16
                        anchors{
                            top: parent.top
                            horizontalCenter:  parent.horizontalCenter
                        } anchors.bottomMargin: 10
                        id:returnlabel3
                        Text {
                            anchors.centerIn: parent
                            font.pixelSize: 14
                            text: qsTr("Bar Sales")
                        }
                    }
                    Frame{
                        anchors.top: returnlabel3.bottom
                        anchors.horizontalCenter: parent.horizontalCenter
                        height: parent.height-parent.height/8
                        width: parent.width-parent.width/8
                        WaiterDailyBarSales{
                         anchors.fill: parent
                        }
                    }


                }

                Item {
                    id: secondPage
                    Button{height: 30;width: 40;text:"<<"  ;onClicked:{masterController.ui_navigationController.goCreateLoginView()}}
                    Rectangle{
                        height: parent.height/16
                        anchors{
                            top: parent.top
                            horizontalCenter:  parent.horizontalCenter
                        } anchors.bottomMargin: 10
                        id:resreturnlbl
                        Text {
                            anchors.centerIn: parent
                            font.pixelSize: 14
                            text: qsTr("Restaurant Returns")
                        }
                    }
                    Frame{
                        anchors.top: resreturnlbl.bottom
                        anchors.horizontalCenter: parent.horizontalCenter
                        height: parent.height-parent.height/8
                        width: parent.width-parent.width/8
                        WaiterDailyRestReturns{
                            anchors.fill: parent
                        }
                    }


                }

                Item {
                    id: salepage
                    Button{height: 30;width: 40;text:"<<"  ;onClicked:{masterController.ui_navigationController.goCreateLoginView()}}
                    Rectangle{
                        height: parent.height/16
                        anchors{
                            top: parent.top
                            horizontalCenter:  parent.horizontalCenter
                        } anchors.bottomMargin: 10
                        id:saleslabel
                        Text {
                            anchors.centerIn: parent
                            font.pixelSize: 14
                            text: qsTr("Bar Returns")
                        }
                    }

                    Frame{
                        anchors.top: saleslabel.bottom
                        anchors.horizontalCenter: parent.horizontalCenter
                        height: parent.height-parent.height/8
                        width: parent.width-parent.width/8
                        WaiterDailyBarReturns{
                         anchors.fill: parent
                        }
                    }
                }
            }
            PageIndicator {
                id: indicator
                count: view.count
                currentIndex:view.currentIndex
                anchors.bottom: view.bottom
                anchors.horizontalCenter: parent.horizontalCenter
            }

        }
    }
    Binding{
        target: masterController.ui_NewTime
        property:"newclock"
        restoreMode:Binding.RestoreBindingOrValue
        value:masterController.ui_userid
        when: clockinbtn.pressed|clockoutbtn.pressed
    }
    Component.onCompleted: {
        masterController.onLoginsystemsales()
    }
    Component.onDestruction: {

    }


}


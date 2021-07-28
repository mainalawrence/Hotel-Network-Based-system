import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.3
import QtQuick.VirtualKeyboard 2.1
import "Clock"
import pos 1.0


Item {
    id: name
    //anchors.fill: parent

    property string backGroundcolor: "gray"
    property bool  timerpageS: false

    Myclock{
        id:myclock
    }

        Rectangle{
            id:rectroot
            anchors.fill: parent
            Clock{
                id:id_root
            }
            Image {
                id: myimg
                source: "../images/hotel.jpeng"
                anchors.fill: parent
                height: 200
                width:rectroot.width/2+10
                Label{
                    anchors.right: parent.right
                    anchors.topMargin: 40
                    anchors.top: parent.top
                    anchors.rightMargin: 20
                    text:Qt.formatTime(id_root.currentDate,"h:m.s ap")
                    color:"Black"
                    font.pixelSize:16
                }
            }
//    InputPanel {
//                id: inputPanel
//                z: 99
//                x: 0
//                y: rectroot.height
//                width: rectroot.width
//                states: State {
//                    name: "visible"
//                    when: inputPanel.active
//                    PropertyChanges {
//                        target: inputPanel
//                        y: rectroot.height - inputPanel.height
//                    }
//                }
//                transitions: Transition {
//                    from: ""
//                    to: "visible"
//                    reversible: true
//                    ParallelAnimation {
//                        NumberAnimation {
//                            properties: "y"
//                            duration: 250
//                            easing.type: Easing.InOutQuad
//                        }
//                    }
//                }
//            }
            Column{
                id:columnid
                spacing: 10
                y:rectroot.height/6
                anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width/4
                Label {
                    color: "#565758"
                    text: "User Name   "
                    anchors.left: parent.left
                    font.pixelSize: 14
                    font.italic: true
                }
                TextField {
                    id:usernametxt
                    width: parent.width
                    focus: true
                    placeholderText: "User Name..."
                    KeyNavigation.backtab:passwordtxt
                    Keys.onEnterPressed:passwordtxt
                }
                Label {
                    color: "#565758"
                    text: "Password "
                    anchors.left: parent.left
                    font.italic: true
                    font.pixelSize: 14
                }
                TextField {
                    id: passwordtxt
                    width: parent.width
                    focus: true
                    echoMode: TextInput.Password
                    placeholderText: "Enter Password..."
                    inputMethodHints: Qt.ImhNoAutoUppercase | Qt.ImhPreferLowercase | Qt.ImhSensitiveData | Qt.ImhNoPredictiveText
                    onAccepted: enterbtn.activeFocus
                    KeyNavigation.backtab: usernametxt
                    Keys.onEnterPressed:enterbtn
                }

                RowLayout {
                    id:buttons
                    spacing: 5
                    Button {
                        id:enterbtn
                        text: "Enter "
                        focus: true
                        enabled:activateenterclockbtn()
                        contentItem: Text {
                            text: enterbtn.text
                            font: enterbtn.font
                            opacity: enabled ? 1.0 : 0.3
                            color: enterbtn.down ? "#17a81a" : "#21be2b"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            elide: Text.ElideRight
                        }
                        background: Rectangle{
                            implicitHeight: 30
                            implicitWidth: columnid.width/2
                            opacity: enabled ? 1 : 0.7
                            border.color: enterbtn.down ? "#17a81a" : "#21be2b"
                            border.width: 1
                            radius: 4
                        }
                        onClicked: {
                            masterController.onLogin(usernametxt.text.toLowerCase(),passwordtxt.text.toLowerCase())
                            passwordtxt.clear()
                            usernametxt.clear()
                        }
                    }
                    Button {
                        id:clockbtn
                        text: "Clock"
                        focus: true
                        enabled: activateenterclockbtn()
                        onClicked: {
                           masterController.onClockin(usernametxt.text.toLowerCase(),passwordtxt.text.toLowerCase())
                            passwordtxt.clear()
                            usernametxt.clear()
                        }
                        contentItem: Text {
                            text: clockbtn.text
                            font: clockbtn.font
                            opacity: enabled ? 1.0 : 0.7
                            color: clockbtn.down ? "#17a81a" : "#21be2b"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            elide: Text.ElideRight
                        }
                        background: Rectangle{
                            implicitHeight: 30
                            implicitWidth: columnid.width/2
                            opacity: enabled ? 1 : 0.3
                            border.color: clockbtn.down ? "#17a81a" : "#21be2b"
                            border.width: 1
                            radius: 4
                        }
                    }

}
}
}

        function backmainlogin(){
            mainstackview.replace(mainlogin)
        }
        function activateenterclockbtn(){
            if(passwordtxt.text.length>0&&usernametxt.text.length>0){ return true}
            else {
                return false;
            }
        }

}

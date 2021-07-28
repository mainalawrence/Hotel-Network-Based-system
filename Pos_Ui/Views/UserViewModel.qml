import QtQuick 2.0
import pos 1.0
import QtQml 2.14
import QtQuick.Controls 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4
import "../BasicFunctions.js" as Js

Page{
    Button{height: 20;width: 40;iconSource: "../images/home.png";onClicked: masterController.ui_navigationController.goCreateManagerView()}
    property Pos_Users newuser: masterController.ui_Posusers


    StackView{
        id:mainstackview
        anchors.fill: parent
        initialItem:mainuserwindow

    }
    Page {
        id:mainuserwindow
        Button{height: 30;width: 40;iconSource:"../images/home.png"  ;onClicked: masterController.ui_navigationController.goCreateManagerView()}
        TableView{
            anchors.centerIn: parent
            id:users
            height:parent.height-parent.height/4
            width: parent.width-parent.width/8
            model: masterController.ui_UsersViewModel
            onClicked:{console.log(users.__currentRow);  mainstackview.replace(userdetailspage)}
            TableViewColumn{
                role:"Firstname";
                title:"First Name" ;
                width:100
            }
            TableViewColumn{
                role:"lastname";
                title:"Last Name" ;
                width:100
            }
            TableViewColumn{
                role:"idnumber";
                title:"ID Number" ;
                width:80
            }
            TableViewColumn{
                role:"passowrd";
                title:"Passowrd";
                width:100
            }
            TableViewColumn{
                role:"userName";
                title:"Username" ;
                width:100
            }
            TableViewColumn{
                role:"Role";
                title:"Role";
                width:100
            }
            TableViewColumn{
                role:"gender";
                title:"Gender" ;
                width:70
            }
            TableViewColumn{
                role:"email";
                title:"Email" ;
                width:100
            }
            TableViewColumn{
                role:"address";
                title:"Address" ;
                width:100
            }
            TableViewColumn{

                delegate: Button{
                    height: 30
                    iconSource: "../images/whiteremove.png"
                    onClicked: {
                        masterController.onDeletPosuser(model.idnumber,model.index)
                    }
                } width:20
            }
        }



    }
    Page{
        id:userdetailspage
        Button{iconSource: "../images/back.png";onClicked: masterController.ui_navigationController.goCreateEmployeeView()}
        WorkingHoursViewsModle{
            id:workingHModel
        }

        visible: false
        TabView {
            id: frame
            anchors.fill: parent
            anchors.margins: 40
            Tab {
                title: "Working Hours"
                Rectangle{
                    anchors.centerIn: parent
                    TableView {
                        height:parent.height-100
                        width: 500
                        anchors.centerIn: parent

                        TableViewColumn {
                            role: "id"
                            title: "ID"
                            width: 100
                        }
                        TableViewColumn {
                            role: "name"
                            title: "Name"
                            width: 100
                        }TableViewColumn {
                            role: "login"
                            title: "Login"
                            width: 100
                        }
                        TableViewColumn {
                            role: "logout"
                            title: "Logout"
                            width: 100
                        }
                        TableViewColumn {
                            role: "workingHours"
                            title: "Hours"
                            width: 100
                        }
                        model: workingHModel
                    }
                }

            }
            Tab { title: "New "
                Rectangle{
                    anchors.fill: parent
                    Frame{
                        id:mainframe
                        anchors.centerIn: parent
                        height: parent.height-20
                        width: 400
                        clip: true
                        Column{
                            anchors.left: parent.left
                            spacing: 20
                            Row{spacing: 5 ;Label{padding:firstnametxt.height/2-10; text: "First Name";width: 60} TextField{ id:firstnametxt;onTextChanged:newuser.ui_firstname.ui_value=text; width:300; placeholderText: "Name..."} }
                            Row{spacing: 5 ;Label{padding:lastnametxt.height/2-10;text: "Last Name";width: 60} TextField{id:lastnametxt;onTextChanged:newuser.ui_lastname.ui_value=text; width:300;placeholderText: "Name..."} }
                            Row{spacing: 5 ;Label{padding:addresstxt.height/2-10;text: "Address";width: 60} TextField{id:addresstxt;onTextChanged:newuser.ui_address.ui_value=text; width:300;placeholderText: "Address.."} }
                            Row{spacing: 5 ;Label{padding:idnumbertxt.height/2-10;text: "ID number";width: 60} TextField{id:idnumbertxt;onTextChanged:newuser.ui_idnumber.ui_value=text;width:300; placeholderText: "Id.."} }
                            Row{spacing: 5 ;Label{padding:userNametxt.height/2-10;text: "UserName";width: 60} TextField{id:userNametxt;onTextChanged:newuser.ui_userName.ui_value=text;width:300; placeholderText: "Username..."} }
                            Row{spacing: 5 ;Label{padding:passwordtxt.height/2-10;text: "Password";width: 60} TextField{id:passwordtxt;onTextChanged:newuser.ui_password.ui_value=text;width:300; placeholderText: "password"} }
                            Row{spacing: 5 ;Label{padding:emailtlx.height/2-10;text: "Email";width: 60} TextField{id:emailtlx;width:300;onTextChanged:newuser.ui_email.ui_value=text; placeholderText: "Email.."} }
                            Row{spacing: 5;Label{padding:gendercbx.height/2-10;text: "Gender";width: 60} ComboBox{
                                    id:gendercbx;width: 300;
                                    onCurrentTextChanged:newuser.ui_gender.ui_value=gendercbx.currentText
                                    model:["Male","Female","Other"]
                                    // firstnametxt lastnametxt addresstxt idnumbertxt userNametxt passwordtxt gendercbx rolecbx
                                }}
                            Row{spacing: 5;Label{padding:rolecbx.height/2-10;text: "Role";width: 60} ComboBox{
                                    id:rolecbx;width: 300;model:["Supervisor","Director","Manager","Bar Cashier","Hotel Cashier","Waiter"]
                                    onCurrentTextChanged: newuser.ui_role.ui_value=rolecbx.currentText
                                }}
                            Row{spacing: 2; Button{width:90; text:"Discard"
                                    onClicked: {
                                        masterController.ui_navigationController.goCreateManagerView()
                                       //console.log( masterController.ui_Posusers.ui_AlluserDetails)
                                    }
                                } Button{width:90;text:"Add New"
                                    onClicked: {
                                        masterController.ui_createuser
                                    }
                                } Button{width:90;text:"Edit"
                                onClicked: masterController.onUpdateuser()
                                }
                                Button{id:userssavedbtn;width:90;text:"Save"
                                    enabled: Js.ifempty(idnumbertxt.text)
                                    onClicked: {
                                        masterController.onCreateuser()
                                        masterController.onUpdatestockusers()
                                        firstnametxt.text="";lastnametxt.text="";addresstxt.text="";idnumbertxt.text="";userNametxt.text="";
                                        passwordtxt.text="";emailtlx.text="";
                                        saveduser.open();
                                        // dbuserSave.userssaved()
                                        //masterController.ui_navigationController.goCreateManagerView()
                                    }
                                }}

                        }
                        Binding{
                            target:newuser;
                            property:"newuser"
                            restoreMode: Binding.RestoreBindingOrValue
                            value:firstnametxt.text+ lastnametxt.text+ addresstxt.text+ idnumbertxt.text+ userNametxt.text+ passwordtxt.text+ gendercbx.currentText+ rolecbx.currentText
                            when:userssavedbtn.pressed
                        }
                    }

                }



            }

            style: TabViewStyle {
                frameOverlap: 1
                tab: Rectangle {
                    color: styleData.selected ? "white" :"lightsteelblue"
                    border.color:  "white"
                    implicitWidth: Math.max(text.width + 4, 80)
                    implicitHeight: 60
                    radius: 2
                    Text {
                        id: text
                        anchors.centerIn: parent
                        text: styleData.title
                        color: styleData.selected ? "black" : "white"
                    }
                }
                frame: Rectangle { color: "white" }
            }
        }
    }
    Dialog{
        id:saveduser
        Label{
            anchors.fill:parent
            text: {
                "Saved !!! "
            }

        }

    }

}

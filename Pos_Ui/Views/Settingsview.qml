import "../BasicFunctions.js" as BFun
import QtQuick 2.0
import QtQml 2.14
import QtQuick.Controls 2.5
import pos 1.0

Item {
    id:root
    property AppSettings appsettings:masterController.ui_Appsettings
    Frame{
        anchors.fill: parent
        background: Rectangle{
            color: "white"
        }
        Frame{
            anchors.centerIn: parent
            height:root.height-root.height/16
            width: root.width/2-root.width/8
            clip: true
            background: Rectangle{
                color: "Gray"
            }
            Column{
                anchors.left: parent.left
                spacing:3
                Row{spacing: 40 ;Label{padding:serverName.height/2-10;font.italic: true; text: "Business Name";width: 60}
                    TextField{id:businessName;onTextChanged:appsettings.ui_BusinessName.ui_value=businessName.text;font.bold:true;  color: "white" ; width:300; placeholderText: "Business Name"} }
                Row{spacing: 40 ;Label{padding:serverName.height/2-10;font.italic: true; text: "Server id";width: 60}
                    TextField{ id:serverName;font.bold:true; onTextChanged:appsettings.ui_Serveraddress.ui_value=serverName.text; color: "white" ; width:300; placeholderText: "Server id..."} }
                Row{spacing: 40 ;Label{padding:serverporttxt.height/2-10;font.italic: true;text: "Server port ";width: 60}
                    TextField{id:serverporttxt;onTextChanged:appsettings.ui_serverport.ui_value=BFun.stringtoInt(serverporttxt.text) ;font.bold:true;color: "white" ;width:300;placeholderText: "  Server port"} }
                Row{spacing: 40 ;Label{padding:dbaddresstxt.height/2-10;font.italic: true;text: "Db Address";width: 60}
                    TextField{id:dbaddresstxt;onTextChanged:appsettings.ui_DatabaseAddress.ui_value=BFun.stringtoInt(dbaddresstxt.text); font.bold:true;width:300;color: "white" ;placeholderText: " Db Address"} }
                Row{spacing: 40 ;Label{padding:dbport.height/2-10;font.italic: true;text: "Db port";width: 60}
                    TextField{id:dbport; font.bold:true;onTextChanged:appsettings.ui_DatabasePort.ui_value=BFun.stringtoInt(dbport.text);width:300;color: "white" ;placeholderText: " Db port"}}
                Row{spacing: 40 ;Label{padding:dbDatabaseUserNametxt.height/2-10;font.italic: true;text: "Db Username";width: 60}
                    TextField{id:dbDatabaseUserNametxt; onTextChanged:appsettings.ui_DatabaseName.ui_value=dbDatabaseUserNametxt.text;font.bold:true;width:300;color: "white" ;placeholderText: " Database UserName"} }
                Row{spacing: 40 ;Label{padding:dbport.height/2-10;font.italic: true;text: "Db Password";width: 60}
                    TextField{id:dbpasswordtxt; onTextChanged:appsettings.ui_Password.ui_value=dbpasswordtxt.text; font.bold:true;width:300;color: "white" ;placeholderText: " Database password"} }
                Row{spacing: 40 ;Label{padding:dbport.height/2-10;font.italic: true;text: "Db Name";width: 60}
                    TextField{id:dbNametxt; onTextChanged:appsettings.ui_DatabaseName.ui_value=dbpasswordtxt.text; font.bold:true;width:300;color: "white" ;placeholderText: " Database Name"} }
                Row{spacing: 40 ;Label{padding:dbDrivers.height/2-10;font.italic: true;text: "Db Drivers";width: 60}
                    TextField{id:dbDrivers; onTextChanged:appsettings.ui_appCategorly.ui_value=dbDrivers.currentText; font.bold:true;width:300;color: "white" ;placeholderText: " Database Drivers"} }
                Row{ spacing: 45;Label{padding:categorydp.height/2-10; text: "Category";width: 60}
                    ComboBox{id:categorydp;width: 250;model:["Bar","Restaurant"]
                 onCurrentTextChanged:appsettings.ui_appCategorly.ui_value=categorydp.currentText}
                }
            }
            Row{
                spacing: 20
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
                Button{id: discardbtn;
                    onClicked: {
                        masterController.ui_navigationController.goCreateManagerView()}
                    text: "Discard";background:Rectangle{anchors.fill: parent;color: discardbtn.down ? "gray" : "white"; height: 20;width: 100;radius: 5; opacity: enabled ? 1 : 0.3}}
                Button{ id: okbtn;
                    onClicked: {
                        masterController.onSettings();
                        console.log(masterController.ui_Appsettings.ui_AllDetails)
                        //masterController.ui_navigationController.goCreateManagerView()
                    }
                    text: "Ok";background:Rectangle{anchors.fill: parent;color: okbtn.down ? "gray" : "white"; height: 20;width: 100;radius: 5; opacity: enabled ? 1 : 0.3}}
            }
        }
    }
    Binding{
            target: appsettings
            property:"Appsettings"
            restoreMode: Binding.RestoreBindingOrValue
            value:serverName.text+ serverporttxt.text + businessName.text +categorydp.text+dbpasswordtxt.text+dbDatabaseUserNametxt.text+dbport.text+ dbDrivers.text+dbNametxt.text;
            when:okbtn.pressed
    }

}

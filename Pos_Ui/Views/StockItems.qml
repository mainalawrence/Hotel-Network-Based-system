import QtQuick 2.14
import QtQml 2.14
import pos 1.0
import QtQuick.Controls 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4
import "../BasicFunctions.js" as BFun
Item {
    id: rootstockits
    property StockDetails newstock: masterController.ui_StockDetails
    Button{height: 30;width: 40;iconSource:"../images/home.png"  ;onClicked: masterController.ui_navigationController.goCreateManagerView()}
    Frame{
        id:rootframe
        anchors.fill: parent
        anchors.margins: 30
        Row{
            spacing: 30
            anchors.fill: parent
            TableView{
                model: masterController.ui_itemviewsmodel  //the model is to be over here
                id:stockviewtable
                height: rootframe.height
                width: rootframe.width/2

                TableViewColumn{
                    title: "Item Id"
                    role:"id"
                    width: 100
                    horizontalAlignment:Text.AlignHCenter
                }
                TableViewColumn{
                    title: "Name"
                    role:"name"
                    width: 100
                    horizontalAlignment:Text.AlignHCenter
                }
                TableViewColumn{
                    title: "Category"
                    role:"category"
                    width: 100
                    horizontalAlignment:Text.AlignHCenter
                }
                TableViewColumn{
                    title: "Item_Group"
                    role:"itemgroup"
                    width: 100
                    horizontalAlignment:Text.AlignHCenter
                }
                TableViewColumn{
                    title: "Cost"
                    role:"cost"
                    width: 100
                    horizontalAlignment:Text.AlignHCenter
                }

                TableViewColumn{

                    delegate: Button{
                        iconSource: "../images/whiteremove.png"
                        onClicked: {
                            masterController.onItemdelete(model.id,model.index)  }
                    } width: 20
                }
            }
                Frame{
                    spacing: 40
                    clip: true
                    height: rootframe.height
                     Column{
                     spacing: 20
                    Row{spacing: 5 ;Label{padding:id.height/2-10;text:"Id" ;width: 60}TextField{ id:id ;width:200;
                                   placeholderText: "Id";onTextChanged: newstock.ui_stockid.ui_value=id.text;  } }
                    Row{spacing: 5;Label{padding:category.height/2-10;text: "Category";width: 60} ComboBox{
                            id:category;width: 200;model:["Restaurant","Bar"]
                            onCurrentTextChanged: newstock.ui_category.ui_value=category.currentText
                        }}
                    Row{spacing: 5;Label{padding:itemgroup.height/2-10;text: "Item Group";width: 60} ComboBox{
                            id:itemgroup;width: 200;model:["Drinks","Breakfast","Heavy meal","Snacks"]
                            onCurrentTextChanged:newstock.ui_itemgroup.ui_value=itemgroup.currentText
                        }}
                    Row{spacing: 5 ;Label{padding:nametxt.height/2-10; text: "Name";width: 60}
                                   TextField{ id:nametxt;onTextChanged: newstock.ui_stockname.ui_value=text
                                       width:200; placeholderText: "Name..."} }
                    Row{spacing: 5 ;Label{padding:costtxt.height/2-10;text: "Cost";width: 60}
                                   TextField{id:costtxt;width:200;
                                       onTextChanged: newstock.ui_stockcost.ui_value=BFun.stringtoDouble(text);placeholderText: "Cost..."} }
                     Row{spacing: 2;
                        Button{width:90; text:"Discard"
                            onClicked: {
                                masterController.ui_navigationController.goCreateManagerView()
                            }
                        } Button{width:90;text:"Add New"
                            onClicked: {
                                id.text="";nametxt.text="";costtxt.text="";taxtxt.text=""
                            }
                        } Button{width:90;text:"Edit"}
                        Button{ id:savebtn;enabled:BFun.ifempty(id.text); width:90;text:"Save"
                            onClicked: {
                                masterController.onCreateStock()
                                id.text=" ";nametxt.text="";costtxt.text="";taxtxt.text=""
                                masterController.onUpdatestockusers()
                            }
                        }}
                }
                     background: Rectangle{
                         border.color: "transparent"
                     }
            }
        }
        background: Rectangle{
            border.color: "transparent"
        }
    } Binding{
        target: masterController.ui_createStock
        property:"newstock"
        restoreMode: Binding.RestoreBindingOrValue
        value:id.text+ nametxt.text + costtxt.text  +itemgroup.currentText+category.currentText;
        when:savebtn.pressed
    }
}


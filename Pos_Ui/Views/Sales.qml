import QtQuick 2.14
import QtQml 2.14
import QtQuick.Controls 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.14
import pos 1.0
import "Clock"
import "../BasicFunctions.js" as Basicjs
Item {
    id: rootstockits
    property double totalCost;
    property double totalTax;
    property bool enablebtnclick:true
    property int orderbtnsize: 65
    property int ordercellsize: 70
    property bool viewrecite: false
    property bool viewroot: true
    property var tablenumber
    property string ordertype
    property string orderNumber

    property Saveorders saveorders: masterController.ui_Saveorders
    Clock{
        id:id_root
    }
    OrderCat{
        id:ordercat
    }
    Rectangle{
        visible: viewroot
        anchors.fill: parent
        anchors.margins: 10
        Row{
            anchors.fill: parent
            TabView{
                id:roottbr
                //anchors.margins: 40
                height: parent.height
                width: parent.width/4*3
                Tab{
                    title: "Restaurant"
                    Frame{
                        background: Rectangle{border.color: "#000" ;border.width: 2.5 }
                        Rectangle{
                            anchors.fill: parent
                            GridView{ id:view ;anchors.fill: parent; cellHeight: ordercellsize; cellWidth: ordercellsize ;model:masterController.ui_OrderRestItemsModels
                                delegate: delegate ;clip: true; focus: true}
                            Component{
                                id:delegate
                                Rectangle{ id:rect ;height:orderbtnsize ;width:orderbtnsize; color:GridView.isCurrentItem?"red":"green"
                                    Text{
                                        anchors.centerIn: parent
                                        text:model.name + "\n"+ model.cost
                                        font.pixelSize: 12 ;font.bold:true
                                        padding: 5
                                    }
                                    MouseArea{
                                        anchors.fill: parent

                                        onClicked: {
                                            ordercat.addonCat(model.name,model.cost,1,model.cost,model.tax)
                                            Basicjs.orderDetails(model.name,model.cost,1,model.total,model.tax)
                                            enabled=false
                                            console.log(JSON.stringify( Basicjs.Datab))
                                        }
                                    }
                                }
                            } }
                    }
                }
                Tab{
                    title: "Bar"
                    Frame{
                        background: Rectangle{
                            border.color: "#000"
                            border.width: 2.5
                        }
                        Rectangle{
                            anchors.fill: parent
                            GridView{
                                id:orderview
                                anchors.fill: parent
                                cellHeight: ordercellsize
                                cellWidth: ordercellsize
                                model:masterController.ui_OrderBarItemsModels
                                delegate: delegate
                                clip: true
                                focus: true
                            }
                            Component{
                                id:delegate
                                Rectangle{
                                    id:rect
                                    height:orderbtnsize
                                    width:orderbtnsize
                                    color:GridView.isCurrentItem?"red":"green"
                                    Text{
                                        anchors.centerIn: parent
                                        text:model.name + "\n"+ model.cost
                                        font.pixelSize: 12
                                        font.bold:true
                                        padding: 5
                                    }
                                    MouseArea{
                                        anchors.fill: parent
                                        onClicked:{
                                            enabled=false
                                            ordercat.addonCat(model.name,model.cost,1,model.cost,model.tax)}
                                    }
                                }
                            }
                        }
                    }
                }
                Tab{
                    title: "Drinks"
                    Frame{
                        background: Rectangle{
                            border.color: "#000"
                            border.width: 2.5
                        }
                        Rectangle{
                            anchors.fill: parent
                            GridView{
                                id:drinksorderview
                                anchors.fill: parent
                                cellHeight: ordercellsize
                                cellWidth: ordercellsize
                                model:masterController.ui_OrderDrinks
                                delegate: delegate
                                clip: true
                                focus: true
                            }
                            Component{
                                id:delegate
                                Rectangle{
                                    id:rect
                                    height:orderbtnsize
                                    width:orderbtnsize
                                    color:GridView.isCurrentItem?"red":"green"
                                    Text{
                                        anchors.centerIn: parent
                                        text:model.name + "\n"+ model.cost
                                        font.pixelSize: 12
                                        font.bold:true
                                        padding: 5
                                    }
                                    MouseArea{
                                        anchors.fill: parent
                                        onClicked:{ ordercat.addonCat(model.name,model.cost,1,model.cost,model.tax)
                                            enabled=false
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                Tab{
                    title: "Breakefast"
                    Frame{
                        background: Rectangle{
                            border.color: "#000"
                            border.width: 2.5
                        }
                        Rectangle{
                            anchors.fill: parent
                            GridView{
                                id:breakefastorderview
                                anchors.fill: parent
                                cellHeight: ordercellsize
                                cellWidth: ordercellsize
                                model:masterController.ui_OrderBreakfast
                                delegate: delegate
                                clip: true
                                focus: true
                            }
                            Component{
                                id:delegate
                                Rectangle{
                                    id:rect
                                    height:orderbtnsize
                                    width:orderbtnsize
                                    color:GridView.isCurrentItem?"red":"green"
                                    Text{
                                        anchors.centerIn: parent
                                        text:model.name + "\n"+ model.cost
                                        font.pixelSize: 12
                                        font.bold:true
                                        padding: 5
                                    }
                                    MouseArea{
                                        anchors.fill: parent
                                        onClicked:{ordercat.addonCat(model.name,model.cost,1,model.cost,model.tax)
                                            enabled=false}
                                    }
                                }
                            }
                        }
                    }
                }
                Tab{
                    title: "Heavy Meal"
                    Frame{
                        background: Rectangle{
                            border.color: "#000"
                            border.width: 2.5
                        }
                        Rectangle{
                            anchors.fill: parent
                            GridView{
                                id:heavymealorderview
                                anchors.fill: parent
                                cellHeight: ordercellsize
                                cellWidth: ordercellsize
                                model:masterController.ui_Ordermeal
                                delegate: delegate
                                clip: true
                                focus: true
                            }
                            Component{
                                id:delegate

                                Rectangle{
                                    id:rect
                                    height:orderbtnsize
                                    enabled:orderbtnsize
                                    width:orderbtnsize
                                    color:GridView.isCurrentItem?"red":"green"
                                    Text{
                                        anchors.centerIn: parent
                                        text:model.name + "\n"+ model.cost
                                        font.pixelSize: 12
                                        font.bold:true
                                        padding: 5
                                    }
                                    MouseArea{
                                        anchors.fill: parent
                                        onClicked: { ordercat.addonCat(model.name,model.cost,1,model.cost,model.tax)
                                            enabled=false}
                                    }
                                }
                            }
                        }
                    }
                }
                Tab{
                    title: "Snacks"
                    Frame{
                        background: Rectangle{
                            border.color: "#000"
                            border.width: 2.5
                        }
                        Rectangle{
                            anchors.fill: parent
                            GridView{
                                id:snacks
                                anchors.fill: parent
                                cellHeight:ordercellsize
                                cellWidth: ordercellsize
                                model:masterController.ui_OrderSnacks
                                delegate: delegate
                                clip: true
                                focus: true
                            }
                            Component{
                                id:delegate
                                Rectangle{
                                    id:rect
                                    height:orderbtnsize
                                    width:orderbtnsize
                                    enabled: true
                                    color:enabled?"green":"red"
                                    Text{
                                        anchors.centerIn: parent
                                        text:model.name + "\n"+ model.cost + " \n"
                                        font.pixelSize: 12
                                        font.bold:true
                                        padding: 5
                                    }
                                    MouseArea{
                                        anchors.fill: parent

                                        onClicked:{
                                            enabled=false

                                            ordercat.addonCat(model.name,model.cost,1,model.cost,model.tax)

                                        }
                                    }
                                }
                            }
                        }
                    }
                }

                style: TabViewStyle {
                    frameOverlap: 1
                    tab: Rectangle {
                        color: styleData.selected ? "white" :"lightsteelblue"
                        border.color:styleData.selected ? "#000":"white"
                        border.width: 2.5
                        implicitWidth: Math.max(text.width + 25, 80)
                        implicitHeight: 60
                        radius: 5
                        Text {
                            id: text
                            anchors.centerIn: parent
                            text: styleData.title
                            font.pixelSize:16
                            color: styleData.selected ? "black" : "white"
                        }

                    }
                    frame: Rectangle { color: "white";border.color:"black" }
                }
            }

            Column{
                spacing:3
                rightPadding: 20
                Rectangle{
                    implicitHeight: 60
                    width: parent.width/4
                    Row{
                        spacing: 3
                        Button{
                            id:orderupbtn
                            text: "Order up";
                            onClicked: {
                                saveorders.ui_saleDate.ui_value=(Qt.formatTime(id_root.currentDate,"h:m:s ap")+" "+Qt.formatDate(id_root.currentDate,"dd.MM.yyyy")).toString()
                                saveorders.ui_TableNo.ui_value =tablenumber
                                saveorders.ui_Sales.ui_value=Basicjs.Datab
                                saveorders.ui_SoldBy.ui_value=masterController.ui_username
                                saveorders.waiterid.ui_value=masterController.ui_userid
                                saveorders.ui_orderNumbers.ui_value=rootstockits.orderNumber
                                saveorders.waiterid.ui_value=masterController.ui_userid
                                viewroot=false
                                viewrecite=true

                            }
                            style: ButtonStyle {background: Rectangle {implicitWidth:Math.max(orderup.width + 25, 80);implicitHeight: 60;radius: 5
                                    border.width: control.activeFocus ? 2 : 1 ;border.color:"#000"}Text {id: orderup ;anchors.centerIn: parent ;font.pixelSize:16}
                            }
                        }
                        //ComboBox for the tables
                        Button{text: "Table";
                            onClicked: {tablesdialog.open()}
                            style: ButtonStyle {background: Rectangle {implicitWidth:Math.max(tables.width + 25, 80);implicitHeight: 60;radius: 5
                                    border.width: control.activeFocus ? 2 : 1 ;border.color:"#000"}Text {id: tables ;anchors.centerIn: parent ;font.pixelSize:16}
                            }
                        }

                        //cat clear button
                        Button{text:"Clear"
                            style: ButtonStyle {background: Rectangle {

                                    implicitWidth:Math.max(clearbtn.width + 25, 80);implicitHeight: 60 ;radius: 5 ;border.width: control.activeFocus ? 2 : 1;border.color:"#000"
                                }Text {id: clearbtn ;anchors.centerIn: parent;font.pixelSize:16}}
                            onClicked: {ordercat.clearCat()
                                catview
                            }
                        }
                    }
                }
                //the orderscat
                Frame{
                    height: rootstockits.height/2
                    width: rootstockits.width/4
                    background:Rectangle{border.color: "black"}
                    ListView {
                        id:catview
                        anchors.fill: parent
                        spacing: 4
                        clip: true
                        model: ordercat
                        delegate: numberDelegate
                    }
                }
                Rectangle{ width:catview.width ;height: 60
                    Column{
                        Text{
                            text:"Total Cost: "
                        }
                        Text {
                            id:totalcostxtx;
                            font.bold:true
                            font.pixelSize: 12
                            onTextChanged:saveorders.ui_TotalCost.ui_value=text;
                            text:Number(ordercat.ui_totalcost).toFixed(2)
                        }
                    }
                }
                Component {
                    id: numberDelegate
                    Row{
                        spacing:15
                        Row{
                            Label{clip:truncated ;text:model.name; topPadding:13;Text{anchors.centerIn: parent}}
                            Button{text:"-"
                                onClicked:{
                                    Basicjs.subtructed(model.index,model.name,model.cost,model.amount,model.total)
                                    ordercat.decreseAmount(model.index,model.name,model.cost,model.amount,model.tax)
                                }
                                style: ButtonStyle {background: Rectangle {implicitWidth:25 ;implicitHeight:25 ;radius: 5;border.color: "#000"
                                    }Text {
                                        id: clearbtn
                                        anchors.centerIn: parent
                                        font.pixelSize:16
                                        font.bold:true
                                    }}}
                            Rectangle{id:recamount;clip:true;height:20; width:20;Text{anchors.centerIn: parent; text:model.amount}}
                            Button{text:"+"
                                onClicked:{
                                    Basicjs.added(model.index,model.name,model.cost,model.amount,model.total)
                                    ordercat.increaseAmount(model.index,model.name,model.cost,model.amount,model.tax);
                                }
                                style: ButtonStyle {background: Rectangle {implicitWidth:25;implicitHeight:25; radius: 5;border.color: "#000"}
                                    Text {anchors.centerIn: parent;font.pixelSize:16;font.bold:true}}}
                        }
                        Button{iconSource: "../images/remove.png"
                            height: 25
                            width: 25
                            onClicked: ordercat.removefromCat(model.index)
                            style: ButtonStyle {background: Rectangle { implicitWidth:25; implicitHeight:25;radius: 5 ;border.color: "#000"
                                }Text { anchors.centerIn: parent; font.pixelSize:16 ;font.bold:true}}}
                    }
                }
            }
        }
    }
    Dialog{modality:  Qt.ApplicationModal; id:tablesdialog
        height: 500
        width: 500
        title: "Select Table Number...."
        Column{
            anchors.fill:parent
            spacing: 5

            ButtonGroup {
                id: buttonGroup
                onClicked:{
                       masterController.getorderNum()
                    if(buttonGroup.checkedButton.text.toString()==="Bar"){
                        orderNumber=0;
                        orderNumber=masterController.ui_ordbarnum.toString()
                        masterController.sETOrderCategory(buttonGroup.checkedButton.text.toString())
                    }
                    else{
                        orderNumber=0;
                        orderNumber=masterController.ui_ordrestnum.toString()
                        masterController.sETOrderCategory(buttonGroup.checkedButton.text.toString())
                    }

                }
            }

            Rectangle{
                id:orderlist
                width: parent.width
                height: 40
                ListView {
                    anchors.fill: parent
                    orientation: Qt.RightToLeft
                    model: ["Restaurant", "Bar"]
                    delegate: RadioDelegate {
                        text: modelData
                        ButtonGroup.group: buttonGroup
                    }
                }

            }
            Rectangle{
                width: parent.width
                height: parent.height-orderlist.height
                GridView{
                    cellHeight:45
                    cellWidth: 70
                    anchors.fill: parent
                    model: masterController.ui_OrderTablemodels
                    delegate: delegate
                }}
        }


    }
    Dialog{
        id:assureprint
        title: "Print"
        Label{
            anchors.centerIn: parent
            text: "Print?"
            font.pixelSize: 14
        }
        standardButtons: StandardButton.Ok | StandardButton.Cancel
        onAccepted:{
            var res=printitem.grabToImage(function(result){
                //result.saveToFile("C:/Users/Public/Pictures/img.png");
                PrinteControl.printfun(result.image);
                if(PrinteControl.done===true){
                    masterController.onneworder()
                    masterController.onLogout()}})
        }
        onRejected: Dialog.Close
    }
    Component{id:delegate;
        Rectangle{height:40;width: 60;Text{anchors.centerIn: parent;color: "white"; text:model.tablename;}color: "gray"; radius: 5
            MouseArea{anchors.fill: parent; onClicked: {
                    tablenumber=model.tablename
                    tablesdialog.close()
                }}
        }
    }
    Component{
        id:ordertypedelegate
        RadioDelegate {
            text: modelData
            checked: index == 0
            ButtonGroup.group: buttonGroup

        }
    }


    Binding{
        target: masterController.ui_Saveorders
        property:"saveorders"
        restoreMode: Binding.RestoreBindingOrValue
        value:totaltaxtxt.text;
        when:assureprint.Ok
    }
    Item {
        id: rootrecite
        visible: viewrecite
        anchors.fill: parent
        Page{
            anchors.fill: parent
            Row{
                spacing: 70
                Button{
                    iconSource: "../images/home.png"
                    width:30
                    onClicked: {
                        viewroot=true
                        viewrecite=false
                    }}
                Button{
                    iconSource: "../images/fileprint.png"
                    width:40
                    height: 40
                    onClicked: {
                        assureprint.open()
                        console.log("okay")

                    }
                }
            }
            Frame{
                id:printitem
                anchors.horizontalCenter: parent.horizontalCenter
                height:name.height+mid.height+title.height+body.height+bot.height+footer.height+mid.height+4
                width: parent.width-parent.width/1.2
                clip: true
                Text {
                    id: name
                    anchors.top: parent.top
                    font.pixelSize:7
                    anchors.left: parent.left
                    text:"
 -------------------------------
  Order Receit\n
  BRIGHT T kARATINA
  PO BOX 990 \n
  Tel:+1230979688\n
  Time "+Qt.formatTime(id_root.currentDate,"h:m:s ap")+"

OrdNo:"+orderNumber}
                    Text {
                        id: mid
                        anchors.top: name.bottom
                        anchors.left: parent.left
                        text:
"--------------------------------"
                    }
                    Text {
                        id:title
                        anchors.top: mid.bottom
                        anchors.left: parent.left
                        font.pixelSize:7
                        text:" name   cost   Qnt   Total
--------------------------------
"       }
                    Rectangle{
                        id:body
                        color: "transparent"
                        anchors.top: title.bottom
                        anchors.left: parent.left
                        anchors.right:parent.right
                        height:20*orderviews.count
                        ListView
                        {
                            id:orderviews
                            anchors.fill: parent
                            model:ordercat

                            delegate: Text {
                                padding:1
                                font.pixelSize:7
                                anchors.left: parent.left
                                text:model.name+"   "+model.cost+"  "+model.amount+"  "+model.total
                            }

                        }
                    }
                    Text {
                        id:bot
                        anchors.top: body.bottom
                        anchors.left: parent.left
                        text:
                            "---------------------------------"

                    }
                    Text {
                        id:footer
                        anchors.top: bot.bottom
                        anchors.left: parent.left
                        anchors.leftMargin: 2
                        font.pixelSize:7
                        text:"Total Items:"+orderviews.count +"\n\nTotal Cost:Sh " +Number(ordercat.ui_totalcost).toFixed(2)
                    }
                    Text {
                        anchors.top: footer.bottom
                        anchors.left: parent.left
                        text:"

---------------------------------"
                    }
                }
            }
        }

    }



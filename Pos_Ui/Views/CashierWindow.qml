import QtQuick 2.14
import QtQml 2.14
import QtQuick.Controls 2.14
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4

import pos 1.0
import "Clock"
import "../BasicFunctions.js" as Basicfn

Page
{
    id:cashierWindow
    Clock{
        id:id_root
    }
    SalesViewModel{
        id:salesviewmodel
    }
    ReturnViewModel{
        id:returnViewModel
    }
    SalesDetailsModel{
        id:salesDetailsModel
    }
    WaiterModelView{
        id:waiterModelView
    }
    property Sales savesales:masterController.ui_Category==="Bar"? masterController.ui_barSales:masterController.ui_restSales
    property Sales saleretruns:masterController.ui_Category==="Bar"? masterController.ui_barreturn:masterController.ui_restreturn
    property bool cashenterbtn:true
    property bool toolB: true
    property bool manageview: false
    property bool cashviewtype: false
    property bool crediteviewtype: false
    property bool mpesaviewtype: false
    property bool reportviewtype: false
    property bool gohomebtnproperty: false
    property string waiterid
    //the property for the sales details
    property double totalcost
    property double amount: salesviewmodel.ui_Totalcost
    property int returns: 50

    anchors.margins: 20
    header: ToolBar{

        id:toolbar
        visible: toolB
        spacing: 10
        background: Rectangle{

            Label{
                id:headertimedatelbl
                anchors.centerIn: parent
                text:Qt.formatTime(id_root.currentDate,"h:m:s ap")
                font.pixelSize:16;
            }
            Label{
                id:headerusernamelbl
                text:masterController.ui_username
                anchors.leftMargin: 100
                anchors.right: headertimedatelbl.left
                anchors.verticalCenter: parent.verticalCenter
                anchors.rightMargin: 100
                font.pixelSize: 16
                font.capitalization:Font.MixedCase
            }
            color: "gray"
            height:cashierWindow.height/8
            ToolButton{height: 30;width: 40;
                Image{anchors.fill: parent; source: "../images/home.png"}
                onClicked:{masterController.ui_navigationController.goCreateManagerView()}
                visible: masterController.ui_userRole==="bar cashier"|"hotel cashier"?false:true
            }
            ToolButton{
                visible:gohomebtnproperty
                onClicked:
                {
                    reportviewtype=false
                    gohome();}
                text: "\u25C0"

                contentItem: Text{
                    text: parent.text
                    font.pixelSize: cashierWindow.height>50?70:35
                    anchors.centerIn: parent
                    color: "red"
                }
            }

            RowLayout{
                anchors.right: parent.right
                anchors.verticalCenter: parent.verticalCenter
                spacing: 5
                anchors.margins: 100
                ComboBox {
                    id:waiterselecterbtn
                    visible: reportviewtype
                    currentIndex: 2
                    model:masterController.ui_waiterModelView
                    width: 200
                    delegate:cmbdelegate
                    onCurrentIndexChanged: console.debug(cbItems.get(currentIndex).text + ", " + cbItems.get(currentIndex).color)
                }
                Component{
                    id:cmbdelegate
                    Rectangle{
                        height:40
                        width:parent.width
                        Text{
                            text: model.name+" "+model.idNumber
                        }
                        MouseArea {
                            anchors.fill:parent
                            onClicked:{
                                waiterselecterbtn.popup.close()
                                masterController.onCashierviewsales(model.idNumber)

                            }
                        }

                    }
                }

                Button{
                    id:btnreport
                    text: "Sales"
                    height: waiterid.height
                    onClicked: {
                        gohomebtnproperty=true
                        reportviewtype=true
                        mainview.replace(report, StackView.Immediate)}
                    contentItem: Text{
                        anchors.centerIn: btnreport.Center
                        anchors.verticalCenter: btnreport.verticalCenter
                        text: btnreport.text
                        font.pixelSize:12
                        color: "green"
                    }
                    background: Rectangle{
                        radius: 10
                        height: parent.height
                        width: parent.width
                    }
                }
                Button{
                    id:btnreturns
                    text: "Returns"
                    height: waiterid.height
                    onClicked: {
                        gohomebtnproperty=true
                        reportviewtype=true
                        mainview.replace(returnreport, StackView.Immediate)
                    }
                    contentItem:Text{
                        anchors.centerIn: btnreturns.Center
                        anchors.verticalCenter: btnreturns.verticalCenter
                        text: btnreturns.text
                        font.pixelSize:12
                        color: "green"
                    }
                    background: Rectangle{
                        radius: 10
                        height: parent.height
                        width: parent.width
                    }
                }
            }
        }
    }
    StackView{
        id:mainview
        anchors.fill: parent
        initialItem:mainpage
    }
    Page{

        id:mainpage
        property string waitername
        property int saleitemindex
        property string saleitemid
        property var orderDetails
        property string waiterid
        property string tablename:masterController.ui_Category ==="Bar"?"bar_orders":"restaurant_orders"
        Frame{
            id:salesview
            clip: true
            anchors.left: parent.left
            anchors.topMargin: toolbar.height+100
            anchors.top: parent.top
            height: cashierWindow.height/2
            width: cashierWindow.width/2+cashierWindow.height/4
            background:Rectangle{
                anchors.fill: parent
                border.color: "green"
                border.width:1
            }
            Row{
                anchors.fill: parent
                Rectangle{
                    height: parent.height
                    width: parent.width
                    ListView{
                        anchors.fill: parent
                        spacing: 10
                        model:salesviewmodel
                        clip: true
                        delegate:salesviewdelegate
                    }
                }
            }
            Component{
                id:salesviewdelegate
                Rectangle{
                    color:"white"
                    height:40
                    width: parent.width

                    Column{
                        spacing: 10

                        Row{
                            Label{
                                text: "TABLE NUMBER: "
                            }

                            Text{
                                text:(salesviewmodel.TableNumber).toString()
                                font.pixelSize: 18
                            }
                        }
                        Row{
                            Label{
                                text: "Waiter NAME: "
                            }

                            Text{
                                text:(salesviewmodel.ui_WaiterName).toString()
                                font.pixelSize: 18
                            }

                        }
                        Row{
                            Label{
                                text: "AMOUNT: "
                            }

                            Text{
                                text:(salesviewmodel.ui_Amount).toString()
                                font.pixelSize: 18
                            }
                        }
                        Row{
                            Label{
                                text: "TOTAL:  "
                            }

                            Text{
                                text:(salesviewmodel.ui_Totalcost).toString()
                                font.pixelSize: 18
                                font.bold: true
                            }
                        }
                    }

                }
            }

        }
        Frame{
            id:orderview
            clip: true
            anchors.topMargin: toolbar.height+100
            anchors.left: salesview.right
            anchors.right: parent.right
            anchors.leftMargin: 100
            anchors.top: parent.top
            anchors.rightMargin: 20
            height:cashierWindow.height/2
            width: parent.width-salesview.width
            background:Rectangle{
                anchors.fill: parent
                border.color: "red"
                border.width:1
            }
            SalesCat{
                id:salescat
            }
            ListView{
                id:oderview
                clip: true
                spacing: 5
                anchors.fill:parent
                focus: true
                delegate: oderviewdelegate
                model:masterController.ui_salecat
                width:oderview.width
                height: cashierWindow.height-toolbar.height
                highlight: Rectangle{ width:parent.width;height:60;color: "Red"}
            }
            Component{
                id:cashdelegate
                Rectangle{
                    width: 100
                    height: 100
                    color: "green"
                }
            }
            Component{
                id:oderviewdelegate
                Rectangle{
                    id:oderdelegatebtn
                    height: 50
                    width:parent.width
                    color: "gray"
                    Text{
                        anchors.centerIn: parent
                        color: "white"
                        text:String(model.tablName)+" "+String(model.WaiterName)
                        font.pixelSize:12
                    }
                    MouseArea{
                        anchors.fill: parent
                        onClicked:{
                            salesviewmodel.populate(model.WaiterName,model.amount,model.totalCost,model.tablName,model.orderNumber)
                            mainpage.saleitemindex=model.index
                            mainpage.saleitemid=model.orderNumber
                            mainpage.waiterid=model.waiterId
                            mainpage.waitername=model.WaiterName
                            salesviewmodel.removeitems(mainpage.saleitemindex)
                            Basicfn.func(model.orderList)
                            mainpage.orderDetails=model.orderList

                        }
                    }
                }
            }
        }
        Frame{
            anchors.top: salesview.bottom
            anchors.right: parent.right
            anchors.topMargin: 10
            id:footer
            height:50
            width: cashierWindow.width
            background:Rectangle{
                anchors.fill: parent
                border.color: "white"
                border.width:1
                Row{
                    spacing: 10
                    anchors.leftMargin:salesview.width/4 ;
                    anchors.rightMargin:30;
                    anchors.fill: parent
                    Button{
                        text: "Cash"
                        onClicked: {
                            mainview.replace(cashpage, StackView.Immediate)
                            toolB=false
                            manageview=true
                            cashviewtype=true
                        }
                    }
                    Button{
                        text: "Mpesa"
                        onClicked: {
                            mpesapayemnetdialog.open()
                            toolB=true
                            manageview=false
                            mpesaviewtype=false
                        }
                        Dialog {
                            id:mpesapayemnetdialog

                            height:150
                            width:300
                            title:"Enter code"

                            Label{
                                id:dialogdatelbl
                                font.pixelSize: 12
                                text:" "+ Qt.formatTime(id_root.currentDate,"h:m ap")+"\t\t"+Qt.formatDate(id_root.currentDate,"dd/MM/yyyy")+"\n\n"

                                width: parent.width
                                anchors.horizontalCenter:parent.horizontalCenter
                                anchors.top: parent.top
                            }
                            TextField{
                                id:dialogeAmount
                                anchors.horizontalCenter:parent.horizontalCenter
                                anchors.top: dialogdatelbl.bottom
                                width: parent.width
                                placeholderText: "Enter Amount"
                            }

                            TextField{
                                id:dialogempesacode
                                anchors.horizontalCenter:parent.horizontalCenter
                                anchors.top: dialogeAmount.bottom
                                width: parent.width
                                placeholderText: "Enter code"
                            }
                            standardButtons: Dialog.Ok | Dialog.Discard

                            onAccepted:
                            {
                                savesales.ui_WaiterId.ui_value=mainpage.waiterid
                                savesales.ui_SoldBy.ui_value=mainpage.waitername
                                savesales.ui_ReceitNo.ui_value= mainpage.saleitemid
                                savesales.ui_PaymentType.ui_value="Mpesa"
                                savesales.ui_saleDate.ui_value=id_root.currentDate
                                savesales.ui_TotalCost.ui_value=amount
                                savesales.ui_MpesaCode.ui_value=dialogempesacode.text
                                savesales.ui_ordereditems.ui_value=mainpage.orderDetails
                                masterController.onSaleSaved()
                                salesviewmodel.removeitems()
                                dialogeAmount.clear()
                                dialogempesacode.clear()
                                deletefromdatabase()
                            }
                            onDiscard:{
                                console.log("Discard clicked")

                            }
                        }
                    }
                    Button{

                        id:creditbtn
                        text: "Return Order"
                        onClicked: {
                            savesales.ui_WaiterId.ui_value=mainpage.waiterid
                            savesales.ui_SoldBy.ui_value=mainpage.waitername
                            savesales.ui_ReceitNo.ui_value= mainpage.saleitemid
                            savesales.ui_PaymentType.ui_value="Return"
                            savesales.ui_saleDate.ui_value=id_root.currentDate
                            savesales.ui_TotalCost.ui_value=amount
                            savesales.ui_MpesaCode.ui_value=dialogempesacode.text
                            savesales.ui_ordereditems.ui_value=mainpage.orderDetails
                            saleretruns.ui_ordereditems.ui_value=mainpage.orderDetails
                            salesviewmodel.removeitems()
                            masterController.onReturnorder()
                            masterController.ui_salecat.remove(mainpage.saleitemindex)
                            salesviewmodel.removeitems(mainpage.saleitemindex)
                            deletefromdatabase()
                        }

                    }
                }
            }
        }
        Page{
            id:cashpage
            property string amountEntered



            /* the text is not visible*/
            Button{visible: true; height: 30;width: 40;Image {
                    id: name
                    source: "../images/home.png"
                }  onClicked:{gohome()} }
            Rectangle{
                id:maincashpageRectangle
                height: parent.height-100
                width: parent.width
                visible:cashviewtype
                Column{
                    spacing: 10
                    anchors.fill: parent
                    Rectangle{
                        id:upperButtons
                        width: parent.width
                        height:parent.height-100
                        anchors.topMargin: 10
                        Column{
                            id:calc
                            spacing:5
                            anchors.centerIn:parent
                            TextField{
                                id:amoutdisplaytxt
                                width:btntest.width*3+20
                                height: 50
                                text:cashpage.amountEntered
                                padding: 5
                                horizontalAlignment: Text.AlignRight
                                verticalAlignment:Text.AlignVCenter
                                background: Rectangle{
                                    color: "black"
                                }
                                font.pixelSize:19
                                color: "white"
                            }
                            Row{
                                spacing: 10
                                Button{text: "7" ;height:50 ;width:100;contentItem:Text{anchors.fill: parent; font.pixelSize:16; verticalAlignment:Text.AlignVCenter;
                                        horizontalAlignment: Text.AlignHCenter;text: parent.text }background: Rectangle{anchors.fill: parent;radius: 7;color: "gray";height: parent.height;width: parent.width}
                                    onClicked:cashpage.getAmount(7)}
                                Button{text: "8";height:50 ;width:100;contentItem:Text{anchors.fill: parent; font.pixelSize:16; verticalAlignment:Text.AlignVCenter;
                                        horizontalAlignment: Text.AlignHCenter;text: parent.text }background: Rectangle{anchors.fill: parent;radius: 7;color: "gray";height: parent.height;width: parent.width}
                                    onClicked: cashpage.getAmount(8)}
                                Button{text: "9";height:50 ;width:100;contentItem:Text{anchors.fill: parent; font.pixelSize:16; verticalAlignment:Text.AlignVCenter;
                                        horizontalAlignment: Text.AlignHCenter;text: parent.text }background: Rectangle{anchors.fill: parent;radius: 7;color: "gray";height: parent.height;width: parent.width}
                                    onClicked:cashpage.getAmount(9)}
                            }
                            Row{
                                spacing: 10
                                Button{text: "4";height:50 ;width:100;contentItem:Text{anchors.fill: parent; font.pixelSize:16; verticalAlignment:Text.AlignVCenter;
                                        horizontalAlignment: Text.AlignHCenter;text: parent.text }background: Rectangle{anchors.fill: parent;radius: 7;color: "gray";height: parent.height;width: parent.width}
                                    onClicked:cashpage.getAmount(4)}
                                Button{text: "5";height:50 ;width:100;contentItem:Text{anchors.fill: parent; font.pixelSize:16; verticalAlignment:Text.AlignVCenter;
                                        horizontalAlignment: Text.AlignHCenter;text: parent.text }background: Rectangle{anchors.fill: parent;radius: 7;color: "gray";height: parent.height;width: parent.width}
                                    onClicked:cashpage.getAmount(5)}
                                Button{text: "6";height:50 ;width:100;contentItem:Text{anchors.fill: parent; font.pixelSize:16; verticalAlignment:Text.AlignVCenter;
                                        horizontalAlignment: Text.AlignHCenter;text: parent.text }background: Rectangle{anchors.fill: parent;radius: 7;color: "gray";height: parent.height;width: parent.width}
                                    onClicked:cashpage.getAmount(6)}
                            }
                            Row{
                                spacing: 10
                                Button{text: "1";height:50 ;width:100;contentItem:Text{anchors.fill: parent; font.pixelSize:16; verticalAlignment:Text.AlignVCenter;
                                        horizontalAlignment: Text.AlignHCenter;text: parent.text }background: Rectangle{anchors.fill: parent;radius: 7;color: "gray";height: parent.height;width: parent.width}
                                    onClicked:cashpage.getAmount(1)}
                                Button{text: "2";height:50 ;width:100;contentItem:Text{anchors.fill: parent; font.pixelSize:16; verticalAlignment:Text.AlignVCenter;
                                        horizontalAlignment: Text.AlignHCenter;text: parent.text }background: Rectangle{anchors.fill: parent;radius: 7;color: "gray";height: parent.height;width: parent.width}
                                    onClicked:cashpage.getAmount(2)}
                                Button{text: "3";height:50 ;width:100;contentItem:Text{anchors.fill: parent; font.pixelSize:16; verticalAlignment:Text.AlignVCenter;
                                        horizontalAlignment: Text.AlignHCenter;text: parent.text }background: Rectangle{anchors.fill: parent;radius: 7;color: "gray";height: parent.height;width: parent.width}
                                    onClicked:cashpage.getAmount(3)}
                            }
                            Row{
                                spacing: 10
                                Button{id:btntest;text: ".";height:50 ;width:100;contentItem:Text{anchors.fill: parent; font.pixelSize:16; verticalAlignment:Text.AlignVCenter;
                                        horizontalAlignment: Text.AlignHCenter;text: parent.text }background: Rectangle{anchors.fill: parent;radius: 7;color: "gray";height: parent.height;width: parent.width}
                                    onClicked: cashpage.getAmount(".")}
                                Button{text: "0";height:50 ;width:100;contentItem:Text{anchors.fill: parent; font.pixelSize:16; verticalAlignment:Text.AlignVCenter;
                                        horizontalAlignment: Text.AlignHCenter;text: parent.text }background: Rectangle{anchors.fill: parent;radius: 7;color: "gray";height: parent.height;width: parent.width}
                                    onClicked:cashpage.getAmount(0)}
                                Button{text: "Clear";height:50 ;width:100;contentItem:Text{anchors.fill: parent; font.pixelSize:16; verticalAlignment:Text.AlignVCenter;
                                        horizontalAlignment: Text.AlignHCenter;text: parent.text }background: Rectangle{anchors.fill: parent;radius: 7;color: "gray";height: parent.height;width: parent.width}
                                    onClicked:cashpage.amountEntered="0.0"}
                            }
                            Row{
                                spacing: 10
                                Button{
                                    id:btnEnter
                                    text: "Enter"
                                    height: btntest.height
                                    width: btntest.width*3-90
                                    contentItem: Text{
                                        anchors.fill: parent
                                        text:btnEnter.text
                                        font.pixelSize: 16
                                        font.bold:true
                                        horizontalAlignment:Text.AlignHCenter
                                        verticalAlignment: Text.AlignVCenter
                                    }
                                    background: Rectangle{
                                        id:btnEnterRec
                                        anchors.fill: parent
                                        color: "gray"
                                        radius: 10
                                    }
                                    enabled:cashierWindow.cashenterbtn
                                    onClicked: {
                                        cashierWindow.cashenterbtn=false
                                        cashpage.amountEntered=balance(parseInt(amoutdisplaytxt.text,10),cashierWindow.amount)
                                        clearlist()
                                    }
                                }
                                Button{id:submitcashbtn ;text: "Ok";height:50 ;width:100;contentItem:Text{anchors.fill: parent; font.pixelSize:16; verticalAlignment:Text.AlignVCenter;
                                        horizontalAlignment: Text.AlignHCenter;text: parent.text }background: Rectangle{anchors.fill: parent;radius: 7;color: "gray";height: parent.height;width: parent.width}
                                    onClicked:{
                                        savesales.ui_WaiterId.ui_value=mainpage.waiterid
                                        savesales.ui_SoldBy.ui_value=mainpage.waitername
                                        savesales.ui_ReceitNo.ui_value= mainpage.saleitemid
                                        savesales.ui_PaymentType.ui_value="Cash"
                                        savesales.ui_saleDate.ui_value=id_root.currentDate
                                        savesales.ui_TotalCost.ui_value=amount
                                        savesales.ui_ordereditems.ui_value=mainpage.orderDetails
                                        cashierWindow.cashenterbtn=true
                                        clear()
                                        gohome()
                                        returnclean(amoutdisplaytxt.text)
                                        masterController.onSaleSaved()
                                        masterController.ui_salecat.remove(mainpage.saleitemindex)
                                        masterController.onDroprow(mainpage.tablename,mainpage.saleitemid,mainpage.saleitemindex)
                                        salesviewmodel.removeitems(mainpage.saleitemindex)
                                    }
                                }

                            }
                        }
                    }
                    Rectangle{
                        id:lowwerButtons
                        height: 100
                        width: parent.width

                        Row{
                            anchors.centerIn: parent
                            spacing: 10
                            Button{text: "1000";height:40 ;width:80;contentItem:Text{anchors.fill: parent; font.pixelSize:16; verticalAlignment:Text.AlignVCenter;
                                    horizontalAlignment: Text.AlignHCenter;text: parent.text }background: Rectangle{anchors.fill: parent;radius: 7;color: "gray";height: parent.height;width: parent.width}
                                onClicked:cashpage.getAmountInInteger(1000)}
                            Button{text: "500";height:40 ;width:80;contentItem:Text{anchors.fill: parent; font.pixelSize:16; verticalAlignment:Text.AlignVCenter;
                                    horizontalAlignment: Text.AlignHCenter;text: parent.text }background: Rectangle{anchors.fill: parent;radius: 7;color: "gray";height: parent.height;width: parent.width}
                                onClicked:cashpage.getAmountInInteger(500)}
                            Button{text: "200";height:40 ;width:80;contentItem:Text{anchors.fill: parent; font.pixelSize:16; verticalAlignment:Text.AlignVCenter;
                                    horizontalAlignment: Text.AlignHCenter;text: parent.text }background: Rectangle{anchors.fill: parent;radius: 7;color: "gray";height: parent.height;width: parent.width}
                                onClicked:cashpage.getAmountInInteger(200)}
                            Button{text: "100";height:40 ;width:80;contentItem:Text{anchors.fill: parent; font.pixelSize:16; verticalAlignment:Text.AlignVCenter;
                                    horizontalAlignment: Text.AlignHCenter;text: parent.text }background: Rectangle{anchors.fill: parent;radius: 7;color: "gray";height: parent.height;width: parent.width}
                                onClicked:cashpage.getAmountInInteger(100)}
                            Button{text: "50";height:40 ;width:80;contentItem:Text{anchors.fill: parent; font.pixelSize:16; verticalAlignment:Text.AlignVCenter;
                                    horizontalAlignment: Text.AlignHCenter;text: parent.text }background: Rectangle{anchors.fill: parent;radius: 7;color: "gray";height: parent.height;width: parent.width}
                                onClicked:cashpage.getAmountInInteger(50)}
                        }
                    }
                }
            }
            function getAmount(x){

                if(cashpage.amountEntered==="0.0"){
                    cashpage.amountEntered=0;
                }
                amountEntered+=x;
            }
            function getAmountInInteger(x){
                if(cashpage.amountEntered==="0.0"|cashpage.amountEntered=== ""){amountEntered=0}
                let AmountInInt=parseInt(amountEntered,10);
                AmountInInt+=x;
                amountEntered=AmountInInt;
            }


        }
        Page{
            id:mpesapage
            visible:mpesaviewtype
            Rectangle{
                id:mpesamainRect
                visible: manageview
                anchors.fill: parent
                color: "green"
                height: 200
                width: 200
                Row{
                    spacing: 10
                    Frame{
                        height: mpesamainRect.height
                        width: mpesamainRect.width/2
                        background:Rectangle{
                            border.color: "Transparent"
                            color: "white"
                        }
                        Item{
                            anchors{
                                horizontalCenter: parent.horizontalCenter
                                top: parent.top
                            }

                            Column{
                                Label{
                                    text: "Code"
                                }
                                TextField{
                                    color: "black"
                                    font.pixelSize: 16
                                }
                                Button{
                                    text: "Enter"
                                    ;height:40 ;width:100;contentItem:Text{anchors.fill: parent; font.pixelSize:16; verticalAlignment:Text.AlignVCenter;
                                        horizontalAlignment: Text.AlignHCenter;text: parent.text }background: Rectangle{anchors.fill: parent;radius: 7;color: "gray";height: parent.height;width: parent.width}

                                }
                            }
                        }

                    }
                    Frame{
                        height: mpesamainRect.height
                        width: mpesamainRect.width/2
                        background:Rectangle{
                            border.color: "Transparent"
                            color: "white"
                        }
                    }
                }
                Button{
                    text: "mpesapage"
                    anchors.centerIn: parent
                    onClicked: {
                        mainview.replace(mainpage, StackView.Immediate)
                        toolB=true
                        manageview=false
                    }
                }
            }
        }
        Page{
            id:returnspage
            visible:crediteviewtype
            Frame{
                anchors.fill:parent
                height:parent.height-parent.height/4
                width:parent.width/2
                clip: true
                Rectangle{
                    anchors.centerIn:parent
                    height:parent.height-50
                    width:parent.width-400
                    ListView{
                        anchors.fill: parent
                        model: returnViewModel
                        spacing: 5
                        delegate: returnViewdelegate
                    }
                }
                Button{
                    id:submitreturns
                    text: "Enter"
                    anchors.horizontalCenter: parent.horizontalCenter;
                    anchors.bottom: parent.bottom
                    onClicked: {
                        gohome()

                    }
                }
                Component{
                    id:returnViewdelegate
                    Row{
                        spacing:15

                        Row
                        {
                            spacing: 2
                            Label{clip:truncated ;text:model.name; topPadding:13;Text{anchors.centerIn: parent}}
                            Button{text:"-"
                                onClicked:{returnViewModel.decreseAmount(model.index,model.name,model.cost,model.amount,model.tax)
                                }
                            }
                            Rectangle{id:recamount;clip:true;height:40; width:30;Text{anchors.centerIn: parent; text:model.amount}}
                            Button{text:"+"
                                onClicked:{returnViewModel.increaseAmount(model.index,model.name,model.cost,model.amount,model.tax);
                                }
                                /* style: ButtonStyle {background: Rectangle {implicitWidth:45;implicitHeight:40; radius: 5;border.color: "#000"}
                                        Text {anchors.centerIn: parent;font.pixelSize:16;font.bold:true}}*/}
                        }
                        Button{text:"Del";
                            onClicked: returnViewModel.removefromCat(model.index)
                            /* style: ButtonStyle {background: Rectangle { implicitWidth:45; implicitHeight:40;radius: 5 ;border.color: "#000"
                                    }Text { anchors.centerIn: parent; font.pixelSize:16 ;font.bold:true}}*/}
                    }
                }
            }
        }
        Page{
            id:report
            y:toolbar.height+90
            Rectangle{
                id:returnroot
                height: parent.height-100
                width: parent.width-50
                anchors.horizontalCenter: parent.horizontalCenter
                Text {
                   anchors.bottom: salestable.top
                   anchors.horizontalCenter: parent.horizontalCenter
                    text: qsTr(masterController.ui_Category.toString()+"  Sales")
                    font.pixelSize: 16
                    font.italic: true;

                }

                TableView{
                    id:salestable
                    height:parent.height
                    width:parent.width
                    model:masterController.ui_CRestSaleReport
                    TableViewColumn{
                        role:'ReciteNo'
                        title: "Recite No"
                        width: 100
                    }
                    TableViewColumn{
                        role:'totalcost'
                        title: "Total cost"
                        width: 100
                    }
                    TableViewColumn{
                        role:'paytype'
                        title: "Payment type"
                        width: 100
                    }
                    TableViewColumn{
                        role:'salesdate'
                        title: "Date"
                        width: 100
                    }
                    TableViewColumn{
                        role:'soldby'
                        title: "Waiter name"
                        width: 100
                    }
                    TableViewColumn{
                        role:'Details'
                        title: "Details"
                        width: parent.width- 700
                    }
                }
            }

        }
        Page{
            id:returnreport
            y:toolbar.height+90
            Rectangle{
                id:salesroot
                height: parent.height-100
                width: parent.width-50
                anchors.horizontalCenter: parent.horizontalCenter
                Text {
                   anchors.bottom: returntables.top
                   anchors.horizontalCenter: parent.horizontalCenter
                    text: qsTr(masterController.ui_Category.toString()+"  Returns")
                    font.pixelSize: 16
                    font.italic: true;

                }

                TableView{
                    id:returntables
                    height: parent.height
                    width: parent.width
                    anchors.leftMargin: 25
                    model:masterController.ui_CRestReturnReport
                    TableViewColumn{
                        role:'ReciteNo'
                        title: "Recite No"
                        width: 100
                    }
                    TableViewColumn{
                        role:'totalcost'
                        title: "Total cost"
                        width: 100
                    }
                    TableViewColumn{
                        role:'paytype'
                        title: "Payment type"
                        width: 100
                    }

                    TableViewColumn{
                        role:'salesdate'
                        title: "Date"
                        width: 100
                    }
                    TableViewColumn{
                        role:'soldby'
                        title: "Waiter name"
                        width: 100
                    }
                    TableViewColumn{
                        role:'Details'
                        title: "Details"
                        width: parent.width- 700
                    }
                }

            }

        }
    }
    Binding{
        target: masterController.ui_Category==="Bar"? masterController.ui_barSales:masterController.ui_restSales
        property:"savesales"
        restoreMode: Binding.RestoreBindingOrValue
        value:amount
        when:mpesapayemnetdialog.ok||submitcashbtn.pressed||creditbtn.pressed
    }
    Binding{
        target: masterController.ui_Category==="Bar"? masterController.ui_barreturn:masterController.ui_restreturn
        property:"saleretruns"
        restoreMode: Binding.RestoreBindingOrValue
        value:cashierWindow.amount
        when:creditbtn.pressed
    }
    function gohome(){
        mainview.replace(mainpage,StackView.Immediate);
        gohomebtnproperty=false
        toolB=true
    }
    function retunfunction(x){
        returns+=x
    }
    function balance(x,y){
        cashpage.amountEntered=0;
        return(x-y).toString();
    }
    function clear(){
        cashpage.amountEntered=0;
        gohome();
    }
    function returnclean(x){
        x="";
        return(x);
    }
    function clearlist(){
        salesviewmodel.removeitems()
    }
    function deletefromdatabase(){
        salesviewmodel.removeitems(mainpage.saleitemindex)
        masterController.onDroprow(mainpage.tablename,mainpage.saleitemid,mainpage.saleitemindex)
    }

    Dialog{
        id:waiterselecter
        height:200
        width:80
        Frame{
            anchors.fill: parent
            GridView{
                anchors.fill: parent
                cellHeight:50
                cellWidth: 80
                model: waiterModelView
                delegate: waiterdelegatevi
            }
        }

    }
    Component.onCompleted: {
        masterController.onLoadCashierView()
    }
    Component{
        id:waiterdelegatevi
        Row{
            Button{
                text: model.name
                onClicked: {
                    cashierWindow.waiterid=model.idNumber
                    waiterselecter.close()
                }
            }
        }
    }

}


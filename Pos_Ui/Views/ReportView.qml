import QtQuick 2.14
import QtQuick.Controls 2.5
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4
import pos 1.0

Item {
    id: rootreport
    property BarReportModel mymodel;
//

    Button{height: 30;width: 40;iconSource:"../images/home.png"  ;onClicked:{masterController.ui_navigationController.goCreateManagerView()}}
        TabView{
            id:roottbr
            anchors.fill: parent
            anchors.margins: 30
            Tab{
                title: "Restaurant Sales "
                Frame{
                    id:rootframe
                    anchors.fill: parent
                    background: Rectangle{
                        border.color: "#000"
                        border.width: 2.5
                    }
                    Column{
                        spacing: 20
                        leftPadding :90
                        Row{
                            TextField{
                                id:datesearchtxt
                                width: 200
                                placeholderText: "search date"
                            }

                            Button{
                                text: "search"
                                onClicked: {

                                }
                            }
                        }
                        TableView{
                            id:salestable
                            height: rootframe.height-100
                            width: rootframe.width-200
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
                            model:masterController.ui_RestSaleReport
                        }
                    }
                }
            }
            Tab{
                title: "Bar Sales "
                Frame{
                    id:rootframe2
                    anchors.fill: parent
                    background: Rectangle{
                        border.color: "#000"
                        border.width: 2.5
                    }
                    Column{
                        spacing: 20
                        leftPadding :90
                        Row{
                            TextField{
                                id:datesearchtxt2
                                width: 200
                                placeholderText: "search date"
                            }

                            Button{
                                text: "search"
                                onClicked: {

                                }
                            }
                        }
                        TableView{
                            id:pubsalestable
                            height: rootframe2.height-100
                            width: rootframe2.width-200


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
                            model:masterController.ui_BarSaleReport
                        }
                    }
                }
            }
            Tab{
                title: "Restaurant Returns"
                Frame{
                    id:returnsframe
                    anchors.fill: parent
                    background: Rectangle{
                        border.color: "#000"
                        border.width: 2.5
                        Column{
                            spacing: 20
                            topPadding :20
                            leftPadding :80

                        Row{
                            TextField{
                                id:returnssearchtxt
                                width: 200
                                placeholderText: "Order No"
                            }

                            Button{
                                text: "search"
                                onClicked: {

                                }
                            }
                        }
                        TableView{
                            id:returnstable
                            height: returnsframe.height-100
                            width: returnsframe.width-200
                            model:masterController.ui_RestReturnReport
                            TableViewColumn{
                                role:'orderNo'
                                title: "Order No"
                                width: 100
                            }

                            TableViewColumn{
                                role:'amount'
                                title: "Amount "
                                width: 100
                            }
                            TableViewColumn{
                                role:'totalcost'
                                title: "Total Cost "
                                width: 100
                            }
                            TableViewColumn{
                                role:'date'
                                title: "Date"
                                width: 100
                            }
                            TableViewColumn{
                                role:'waitersName'
                                title: "Waiters Name"
                                width: 100
                            }
                            TableViewColumn{
                                role:'details'
                                title: "Details"
                                width: 100
                            }
                        }}
                    }

                }
                }
            Tab{
                title: "Bar Returns"
                Frame{
                    id:returnsframe2
                    anchors.fill: parent
                    background: Rectangle{
                        border.color: "#000"
                        border.width: 2.5
                        Column{
                            spacing: 20
                            topPadding :20
                            leftPadding :80

                        Row{
                            TextField{
                                id:returnssearchtxt2
                                width: 200
                                placeholderText:"Order No"
                            }

                            Button{
                                text: "search"
                                onClicked: {

                                }
                            }
                        }
                        TableView{
                            id:returnstable2
                            height: returnsframe2.height-100
                            width: returnsframe2.width-200
                            model: masterController.ui_BarReturnReport
                            TableViewColumn{
                                role:'orderNo'
                                title: "Order No"
                                width: 100
                            }

                            TableViewColumn{
                                role:'amount'
                                title: "Amount "
                                width: 100
                            }
                            TableViewColumn{
                                role:'totalcost'
                                title: "Total Cost "
                                width: 100
                            }
                            TableViewColumn{
                                role:'date'
                                title: "Date"
                                width: 100
                            }
                            TableViewColumn{
                                role:'waitersName'
                                title: "Waiters Name"
                                width: 100
                            }
                            TableViewColumn{
                                role:'details'
                                title: "Details"
                                width: 100
                            }
                        }}
                    }

                }
                }
        style: TabViewStyle {
            frameOverlap: 0
            tabsAlignment : Qt.AlignHCenter
            tabsMovable:true
            tab: Rectangle {
                color: styleData.selected ? "white" :"lightsteelblue"
                border.color:styleData.selected ? "#000":"white"
                border.width: 2.5
                implicitWidth: Math.max(text.width + 25, 80)
                implicitHeight: 30
                radius: 5
                Text {
                    id: text
                    anchors.centerIn: parent
                    text: styleData.title
                    font.pixelSize:16
                    color: styleData.selected ? "black" : "white"
                }

            }
            frame: Rectangle { color: "white" }
        }

        }
        Component.onCompleted: {
            masterController.onLoadingReport()
        }
  }


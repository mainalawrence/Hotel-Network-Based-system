import QtQuick 2.0
import QtQuick.Controls 2.5
import "Modeltocart.js" as Data
Item {
    property var newobj: {one:[ 'value','value2']}
    property var newobj1: {one:[ 'value','value2']}
    property var newobj2: {one:[ 'value','value2']}
    property var newobj3: {one:[ 'value','value2']}
    property var mainobj: {all:[ newobj,newobj1,newobj2,newobj3]}
    Rectangle{
        anchors.centerIn: parent
        height: 500
        width: 200
        border.color: "gray"
        Label{

            text:Data.testreplacer[1]+" "+Data.testreplacer[2]+" "+Data.testreplacer[3]+" "+Data.testreplacer[4];

        }
        Component.onCompleted: {
            console.log(JSON.toString( Data.testreplacer))

            var data = JSON.stringify(mainobj);
            console.log(data);
            var obj = JSON.parse(data).toString();
            console.log(obj.all); // > 'value'


        }











Item{
//        ListView{
//            spacing: 10
//            model:Data.testreplacer;
//            delegate: Text {
//                text:JSON.stringify(Data.testreplacer[2])
//            }
//        }
    }

    }


}

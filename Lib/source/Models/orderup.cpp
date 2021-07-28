#include "orderup.h"
using namespace Data;
namespace Models {

OrderUp::OrderUp(QObject *parent):
    Data::Entity(parent,"Orders")
{
    orderNumbers=static_cast<String_Data*>(addDataitem(new String_Data(this,"OrderNo","Null")));
    TotalCost=static_cast<Double_data*>(addDataitem(new Double_data(this,"totalCost",0)));
    saleDate=static_cast<String_Data*>(addDataitem(new String_Data(this,"saleDate","Sale Date")));
    SoldBy=static_cast<String_Data*>(addDataitem(new String_Data(this,"soldBy","Sale SoldBy")));
    TableNo=static_cast<String_Data*>(addDataitem(new String_Data(this,"tableNo","TableNo")));
    Sales=static_cast<JsonArray_data*>(addDataitem(new JsonArray_data(this,"details",{})));
    waiterid=static_cast<String_Data*>(addDataitem(new String_Data(this,"WaiterId","WaiterId")));

}

OrderUp::OrderUp(QObject *parent, QJsonObject &jsonobj):
    OrderUp(parent)
{
    update(jsonobj);
}





QString Models::OrderUp::orderDetails() const
{
    return  orderNumbers->value() +" "+ QString::number(TotalCost->value())+" "+
            " "+saleDate->value()+" "+SoldBy->value()+" "+ TableNo->value();

}
}






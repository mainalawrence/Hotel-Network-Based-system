#include "sales.h"

namespace Models{
using namespace Data;
Sales::Sales(QObject *parent):Data::Entity(parent,"Sales")
{
    ReceitNo=static_cast<Int_data*>(addDataitem(new Int_data(this,"OrderNo",0)));
    TotalCost=static_cast<Double_data*>(addDataitem(new Double_data(this,"totalCost",0)));
    PaymentType=static_cast<String_Data*>(addDataitem(new String_Data(this,"PaymentType","Payment Type")));
    saleDate=static_cast<String_Data*>(addDataitem(new String_Data(this,"saleDate","Sale Date")));
    SoldBy=static_cast<String_Data*>(addDataitem(new String_Data(this,"soldBy","Sale SoldBy")));
    ordereditems=static_cast<String_Data*>(addDataitem(new String_Data(this,"Details",{})));
    MpesaCode=static_cast<String_Data*>(addDataitem(new String_Data(this,"MpesaCode","")));
    WaiterId=static_cast<String_Data*>(addDataitem(new String_Data(this,"WaiterId","Null")));

}
Sales::Sales(QObject *parent, QJsonObject &jsonobj):
    Sales(parent)
{
    update(jsonobj);
}

QString Sales::salesDetails() const
{
    return QString::number(ReceitNo->value()) +" "+ QString::number(TotalCost->value())
            +" "+PaymentType->value()+" " +" "+saleDate->value()+" "+SoldBy->value();

}
}

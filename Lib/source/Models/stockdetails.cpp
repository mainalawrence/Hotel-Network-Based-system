#include "stockdetails.h"
#include<QVariant>
#include<QtDebug>
namespace Models{
using namespace Data;
StockDetails::StockDetails(QObject *parent)
    : Data::Entity(parent,"Stocks")
{
    stockid=static_cast<String_Data *>(addDataitem(new String_Data(this,"stockid","0")));
    stockname=static_cast<String_Data*>(addDataitem(new String_Data(this,"stockName","Stock Name")));
    stockcost=static_cast<Double_data*>(addDataitem(new Double_data(this,"stockCost",0.0)));
    stockitemgroup=static_cast<String_Data*>(addDataitem(new String_Data(this,"itemgroup","itemgroup")));
    stockcategory=static_cast<String_Data*>(addDataitem(new String_Data(this,"category","category")));
}

StockDetails::StockDetails(QObject *parent, QJsonObject &json)
    :StockDetails(parent)
{
    update(json);

}

Data::String_Data *StockDetails::getStockname() const
{

    return stockname;
}

void StockDetails::setStockname(Data::String_Data *value)
{

    stockname = value;
}

Data::String_Data *StockDetails::getStockid() const
{
    return stockid;
}

void StockDetails::setStockid(Data::String_Data *value)
{
    stockid = value;
}

QString StockDetails::stockDetails() const
{

   return stockitemgroup->value()+stockcategory->value()+ stockid->value() +" "+stockname->value()+" "+QString::number(stockcost->value());

}

QString StockDetails::Itemid() const
{
    return stockid->value();
}

}

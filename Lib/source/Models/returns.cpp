#include "returns.h"

namespace Models {
Models::Returns::Returns(QObject *parent):
    Data::Entity(parent,"Returns")
{
    ReciteNo=static_cast<Int_data*>(addDataitem(new Int_data(this,"Recite",0)));
    UserId=static_cast<Int_data*>(addDataitem(new Int_data(this,"UserId",0)));
    Amount=static_cast<Int_data*>(addDataitem(new Int_data(this,"Amount",0)));
    TotalCost=static_cast<Double_data*>(addDataitem(new Double_data(this,"TotalCost",0.0)));
    Time=static_cast<Date_Data*>(addDataitem(new Date_Data(this,"Time",QTime::currentTime())));

}

Models::Returns::Returns(QObject *parent, QJsonObject json):
    Returns(parent)
{
    update(json);
}

QString Returns::ReturnsDetails()
{
    return (QString::number(ReciteNo->value())+" "+QString::number(Amount->value())+" "+QString::number(TotalCost->value())
                +" " +" "+ Time->value().toString("ddd d MMM yyyy @ HH:mm:ss"));
}
}



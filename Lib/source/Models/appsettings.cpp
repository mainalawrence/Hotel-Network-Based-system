#include "appsettings.h"

namespace Models {
using namespace Data;
AppSettings::AppSettings(QObject *parent):
     Data::Entity(parent,"AppSettings")
{
   serverName=static_cast<String_Data*>(addDataitem(new String_Data(this,"ServerName","Servername")));
   serverport=static_cast<Int_data*>(addDataitem(new Int_data(this,"Serverport",2020)));
   appCategorly=static_cast<String_Data*>(addDataitem(new String_Data(this,"AppCategorly","appCategorly")));
   BusinessName=static_cast<String_Data*>(addDataitem(new String_Data(this,"BusinessName","BussinessName")));
   DatabaseName=static_cast<String_Data*>(addDataitem(new String_Data(this,"databaseName","databaseName")));
   DatabaseAddress=static_cast<String_Data*>(addDataitem(new String_Data(this,"DatabaseAddress","127.0.0.1")));
   Serveraddress=static_cast<String_Data*>(addDataitem(new String_Data(this,"Serveraddress","127.0.0.1")));
   DatabasePort=static_cast<Int_data*>(addDataitem(new Int_data(this,"DatabasePort",5432)));
   DatabaseUserName=static_cast<String_Data*>(addDataitem(new String_Data(this,"DatabaseUserName","DatabaseUserName")));
   Password=static_cast<String_Data*>(addDataitem(new String_Data(this,"Password","Password")));
   DatabaseDrivers=static_cast<String_Data*>(addDataitem(new String_Data(this,"DatabaseDrivers","DatabaseDrivers")));
}

AppSettings::AppSettings(QObject *parent, QJsonObject &json):
    AppSettings(parent)
{
    update(json);
}

Data::String_Data *AppSettings::getAppCategorly() const
{
    return appCategorly;
}

void AppSettings::setAppCategorly(Data::String_Data *value)
{
    appCategorly = value;
}

QString AppSettings::allSettings()const
{
    return (serverName->value()+" "+ QString::number(serverport->value())+ " "+appCategorly->value()+" "+ BusinessName->value() +" "+
            DatabaseName->value()+" "+DatabaseAddress->value() +" "+ Serveraddress->value()+" "+ QString::number(DatabasePort->value())
            +" "+DatabaseUserName->value()+" " +Password->value()+" "+DatabaseDrivers->value());

}

}

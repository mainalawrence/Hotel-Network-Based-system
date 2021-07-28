#include "myclocktime.h"

namespace Models {
using namespace Data;
MyClockTime::MyClockTime(QObject *parent):Entity(parent,"Clocks")
{
    clockin=static_cast<String_Data*>(addDataitem(new String_Data(this,"Clockin","null")));
    Clockout=static_cast<String_Data*>(addDataitem(new String_Data(this,"CLockOut","null")));
    Username=static_cast<String_Data*>(addDataitem(new String_Data(this,"Username","NULL")));
    userid=static_cast<String_Data*>(addDataitem(new String_Data(this,"Userid","NULL")));
    myDate=static_cast<String_Data*>(addDataitem(new String_Data(this,"Date:",QDate::currentDate().toString())));
}

MyClockTime::MyClockTime(QObject *parent, QJsonObject json):
    MyClockTime(parent)
{
    update(json);
}

QString MyClockTime::WorkingHours(Date_Data *cin, Date_Data *cPause)
{
    auto a=cin;
    auto b=cPause;

    return a->value().toString("hh:mm:ss")+b->value().toString("hh:mm:ss");
}

QString MyClockTime::GetUserid() const
{
    return userid->value()+QDate::currentDate().toString("MMMMdyyyy");
}

QString MyClockTime::Userdates()const
{
    return userid->value() +" "+Username->value()+" " + clockin->value()+" " +
            " "+Clockout->value();
}

}

#include "pos_users.h"

namespace Models {
using namespace Data;
Pos_Users::Pos_Users(QObject *parent)
    :Data::Entity(parent,"Users")
{
    Userid=static_cast<String_Data*>(addDataitem(new String_Data(this,"userid","0")));
    Firstname=static_cast<String_Data*>(addDataitem(new String_Data(this,"firstName","First Name")));
    lastname=static_cast<String_Data*>(addDataitem(new String_Data(this,"lastName","Last Name")));
    idnumber=static_cast<String_Data*>(addDataitem(new String_Data(this,"idNumber","Id Number")));
    passowrd=static_cast<String_Data*>(addDataitem(new String_Data(this,"password","Password")));
    role=static_cast<String_Data*>(addDataitem(new String_Data(this,"role","role")));
    gender=static_cast<String_Data*>(addDataitem(new String_Data(this,"gender","Gender")));
    email=static_cast<String_Data*>(addDataitem(new String_Data(this,"email","Email")));
    userName=static_cast<String_Data*>(addDataitem(new String_Data(this,"userName","User Name")));
    address=static_cast<String_Data*>(addDataitem(new String_Data(this,"address","Address")));
}

Pos_Users::Pos_Users(QObject *parent, QJsonObject &json)
    :Pos_Users(parent)
{
    update(json);
}

QString Pos_Users::userid()
{
    return idnumber->value();

}

QString Models::Pos_Users::AlluserDetails() const
{
    return Userid->value()+" "+ Firstname->value()+" "+lastname->value()+" "+idnumber->value()+" "+passowrd->value()+" "+
            role->value()+" "+gender->value()+" "+email->value();
}

}

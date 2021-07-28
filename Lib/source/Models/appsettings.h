#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <QObject>
#include<QString>
#include<Pos_Lib_global.h>
#include<Data/entity.h>
#include<Data/int_data.h>
#include<Data/string_data.h>

namespace Models {
class POS_LIB_EXPORT AppSettings : public Data::Entity
{
    Q_OBJECT
    Q_PROPERTY(Data::String_Data* ui_servername MEMBER serverName CONSTANT )
    Q_PROPERTY(Data::Int_data * ui_serverport MEMBER serverport CONSTANT )
    Q_PROPERTY(Data::String_Data* ui_appCategorly MEMBER appCategorly CONSTANT )
    Q_PROPERTY(Data::String_Data* ui_BusinessName MEMBER BusinessName CONSTANT )
    Q_PROPERTY(Data::String_Data* ui_Serveraddress MEMBER Serveraddress CONSTANT )
    Q_PROPERTY(Data::String_Data* ui_DatabaseAddress MEMBER DatabaseAddress CONSTANT )
    Q_PROPERTY(Data::Int_data* ui_DatabasePort MEMBER DatabasePort CONSTANT )
    Q_PROPERTY(Data::String_Data* ui_DatabaseName MEMBER DatabaseName CONSTANT)
    Q_PROPERTY(Data::String_Data* ui_DatabaseUserName MEMBER DatabaseUserName CONSTANT)
    Q_PROPERTY(Data::String_Data* ui_DatabaseDrivers MEMBER DatabaseDrivers CONSTANT)
    Q_PROPERTY(Data::String_Data* ui_Password MEMBER Password CONSTANT)
    Q_PROPERTY(QString   ui_AllDetails READ allSettings CONSTANT)
public:
    AppSettings(QObject *parent=nullptr);
    AppSettings(QObject *parent,QJsonObject &json);
    Data::String_Data* serverName;
    Data::String_Data* Serveraddress;
    Data::Int_data* serverport;
    Data::String_Data* BusinessName;
    Data::String_Data* appCategorly;
    Data::String_Data* DatabaseName;
    Data::String_Data* DatabaseAddress;
    Data::Int_data* DatabasePort;
    Data::String_Data* DatabaseUserName;
    Data::String_Data* DatabaseDrivers;
    Data::String_Data* Password;

    QString allSettings() const;
    Data::String_Data *getAppCategorly() const;
    void setAppCategorly(Data::String_Data *value);
};
}
#endif // APPSETTINGS_H

#ifndef MYCLOCKTIME_H
#define MYCLOCKTIME_H

#include <QObject>
#include<Data/entity.h>
#include<Data/date_data.h>
#include<Data/string_data.h>
#include<Data/int_data.h>
#include<QDate>

#include<QString>
#include<Pos_Lib_global.h>
#include<chrono>

namespace Models {
using namespace Data;
class POS_LIB_EXPORT MyClockTime : public Data::Entity
{
    Q_OBJECT
    Q_PROPERTY(String_Data* ui_Username MEMBER Username CONSTANT)
    Q_PROPERTY(String_Data* ui_userid MEMBER userid CONSTANT)
    Q_PROPERTY(String_Data* ui_clockin MEMBER clockin CONSTANT)
    Q_PROPERTY(String_Data* ui_Clockout MEMBER Clockout CONSTANT)
    Q_PROPERTY(String_Data* ui_Date MEMBER myDate CONSTANT)
public:
    explicit MyClockTime(QObject *parent=nullptr);
    MyClockTime(QObject *parent,QJsonObject json);

    String_Data* clockin{nullptr};
    String_Data* Clockout{nullptr};
    String_Data* Username{nullptr};
    String_Data* userid{nullptr};
    String_Data* myDate{nullptr};
    QString WorkingHours(Date_Data* ,Date_Data*);
    QString Userdates()const;
    QString GetUserid()const;
private:


};
}

#endif // MYCLOCKTIME_H

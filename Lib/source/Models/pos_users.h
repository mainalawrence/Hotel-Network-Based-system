#ifndef POS_USERS_H
#define POS_USERS_H

#include <QObject>
#include<Pos_Lib_global.h>
#include<Data/entity.h>
#include<Data/string_data.h>
#include<Data/int_data.h>


namespace Models{
class POS_LIB_EXPORT Pos_Users : public Data::Entity
{
    Q_OBJECT
    Q_PROPERTY(Data::String_Data* ui_firstname MEMBER Firstname CONSTANT)
    Q_PROPERTY(Data::String_Data* ui_lastname MEMBER lastname CONSTANT)
    Q_PROPERTY(Data::String_Data* ui_idnumber MEMBER idnumber CONSTANT)
    Q_PROPERTY(Data::String_Data* ui_password MEMBER passowrd CONSTANT)
    Q_PROPERTY(Data::String_Data* ui_gender MEMBER gender CONSTANT)
    Q_PROPERTY(Data::String_Data* ui_email MEMBER email CONSTANT)
    Q_PROPERTY(Data::String_Data* ui_role MEMBER role CONSTANT)
    Q_PROPERTY(Data::String_Data* ui_address MEMBER address CONSTANT)
    Q_PROPERTY(Data::String_Data* ui_userName MEMBER userName CONSTANT)
    Q_PROPERTY( Data::String_Data* ui_Userid MEMBER Userid CONSTANT)
    Q_PROPERTY(QString ui_AlluserDetails READ AlluserDetails CONSTANT)
public:
    explicit Pos_Users(QObject *parent=nullptr);
    Pos_Users(QObject *parent,QJsonObject &json);
    Data::String_Data *Userid{nullptr};
    Data::String_Data *Firstname{nullptr};
    Data::String_Data* lastname{nullptr};
    Data::String_Data* idnumber{nullptr};
    Data::String_Data* passowrd{nullptr};
    Data::String_Data* gender{nullptr};
    Data::String_Data* email{nullptr};
    Data::String_Data* role{nullptr};
    Data::String_Data* address{nullptr};
    Data::String_Data* userName{nullptr};
    QString userid();

    QString AlluserDetails() const;

};
}


#endif // POS_USERS_H

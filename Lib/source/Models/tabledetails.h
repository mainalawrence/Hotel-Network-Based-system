#ifndef TABLEDETAILS_H
#define TABLEDETAILS_H

#include <QObject>
#include<Data/entity.h>
#include<Data/string_data.h>


namespace Models {
class POS_LIB_EXPORT TableDetails : public Data::Entity
{
    Q_OBJECT
    Q_PROPERTY( Data::String_Data* ui_TableNo MEMBER TDetails  CONSTANT)
public:
    explicit TableDetails(QObject *parent=nullptr);
    TableDetails(QObject* parent ,QJsonObject &jsonobj);
    Data::String_Data* TDetails{nullptr};

};
}
#endif // TABLEDETAILS_H

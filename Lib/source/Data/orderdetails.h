#ifndef ORDERDETAILS_H
#define ORDERDETAILS_H

#include <QObject>
#include<Data/entity.h>
#include<Data/string_data.h>
#include<Data/int_data.h>
#include<Data/double_data.h>
#include<Pos_Lib_global.h>

namespace Data {
class POS_LIB_EXPORT OrderDetails : public Data::Entity
{
    Q_OBJECT
public:
     OrderDetails();
    Data::String_Data* Name{nullptr};
    Data::String_Data* Amount{nullptr};
    Data::String_Data* cost{nullptr};
    Data::String_Data* Total{nullptr};
    Data::String_Data* tax{nullptr};
};
}
#endif // ORDERDETAILS_H

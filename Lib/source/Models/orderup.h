#ifndef ORDERUP_H
#define ORDERUP_H

#include <QObject>
#include<Data/entity.h>
#include<Data/string_data.h>
#include<Data/int_data.h>
#include<Data/double_data.h>
#include<Data/orderdetails.h>
#include<Data/jsonarray_data.h>
#include<Pos_Lib_global.h>

namespace Models {
class POS_LIB_EXPORT OrderUp : public Data::Entity
{
    Q_OBJECT
    Q_PROPERTY( Data::String_Data* ui_orderNumbers MEMBER orderNumbers CONSTANT)
    Q_PROPERTY( Data::Double_data* ui_TotalCost MEMBER TotalCost CONSTANT)
    Q_PROPERTY( Data::String_Data* ui_TableNo MEMBER TableNo  CONSTANT)
    Q_PROPERTY( Data::String_Data* ui_saleDate MEMBER saleDate CONSTANT)
    Q_PROPERTY( Data::String_Data* ui_SoldBy MEMBER SoldBy CONSTANT)
    Q_PROPERTY(Data::JsonArray_data* ui_Sales MEMBER Sales CONSTANT )
    Q_PROPERTY(Data::String_Data* waiterid MEMBER waiterid CONSTANT)
public:
    explicit OrderUp(QObject *parent=nullptr);
    OrderUp(QObject* parent ,QJsonObject &jsonobj);
    Data::String_Data *orderNumbers{nullptr};
    Data::Double_data* TotalCost{nullptr};
    Data::String_Data* saleDate{nullptr};
    Data::String_Data* SoldBy{nullptr};
    Data::String_Data* WaiterId{nullptr};
    Data::String_Data* TableNo{nullptr};
    Data::JsonArray_data* Sales{nullptr};
    Data::String_Data* waiterid{nullptr};
    QString orderDetails() const;

private:
    const  QList<Data::OrderDetails>m_data;

Data::OrderDetails* type;


};
}
#endif // ORDERUP_H

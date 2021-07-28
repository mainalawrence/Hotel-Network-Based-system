#ifndef SALESS_H
#define SALESS_H
#include <QObject>
#include<Data/entity.h>
#include<Data/string_data.h>
#include<Data/int_data.h>
#include<Data/double_data.h>
#include<Data/jsonarray_data.h>
#include<Pos_Lib_global.h>

namespace Models {
class  POS_LIB_EXPORT Sales : public Data::Entity
{


    Q_OBJECT
    Q_PROPERTY( Data::String_Data* ui_WaiterId MEMBER WaiterId CONSTANT)
    Q_PROPERTY( Data::Int_data* ui_ReceitNo MEMBER ReceitNo CONSTANT)
    Q_PROPERTY( Data::Double_data* ui_TotalCost MEMBER TotalCost CONSTANT)
    Q_PROPERTY( Data::String_Data* ui_PaymentType MEMBER PaymentType  CONSTANT)
    Q_PROPERTY( Data::String_Data* ui_saleDate MEMBER saleDate CONSTANT)
    Q_PROPERTY( Data::String_Data* ui_SoldBy MEMBER SoldBy CONSTANT)
    Q_PROPERTY( Data::String_Data* ui_MpesaCode MEMBER MpesaCode CONSTANT)
    Q_PROPERTY( Data::String_Data* ui_ordereditems MEMBER ordereditems CONSTANT )
public:
    explicit Sales(QObject *parent=nullptr);
    Sales(QObject* parent ,QJsonObject &jsonobj);

    Data::Int_data *ReceitNo{nullptr};
    Data::Double_data* TotalCost{nullptr};
    Data::String_Data* PaymentType{nullptr};
    Data::String_Data* saleDate{nullptr};
    Data::String_Data* SoldBy{nullptr};
    Data::String_Data* ordereditems{nullptr};
    Data::String_Data* MpesaCode{nullptr};
    Data::String_Data* WaiterId{nullptr};
    QString salesDetails()const;
};

}
#endif // SALES_H

#ifndef RETURNS_H
#define RETURNS_H

#include <QObject>
#include<Data/entity.h>
#include<Data/double_data.h>
#include<Data/int_data.h>
#include<Data/date_data.h>
#include<Pos_Lib_global.h>
namespace Models {
using namespace Data;
class POS_LIB_EXPORT Returns : public Data::Entity
{
    Q_OBJECT
    Q_PROPERTY(Int_data *ui_ReciteNo MEMBER ReciteNo CONSTANT)
    Q_PROPERTY(Int_data *UserId MEMBER UserId CONSTANT)
    Q_PROPERTY( Double_data* ui_TotalCost MEMBER  TotalCost CONSTANT)
    Q_PROPERTY( Int_data* ui_Amount MEMBER Amount CONSTANT)
    Q_PROPERTY( Date_Data* ui_Time MEMBER Time CONSTANT)
public:
    explicit Returns(QObject *parent=nullptr);
    Returns(QObject*parent,QJsonObject json);
    Int_data *ReciteNo{nullptr};
    Int_data *UserId{nullptr};
    Double_data* TotalCost{nullptr};
    Int_data* Amount{nullptr};
    Date_Data* Time{nullptr};

    QString ReturnsDetails();
};
}


#endif // RETURNS_H

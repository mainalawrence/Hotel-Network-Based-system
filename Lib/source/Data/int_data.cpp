#include "int_data.h"
#include<QVariant>


namespace Data {

Int_data::Int_data(Data::Entity *parent, const QString &key, const int &values, const QString &label):
    DataDecorator(parent,key,label),
    values(values)
{

}

int Data::Int_data::value()
{
    return this->values;
}

Int_data &Int_data::setvalue(const int &value)
{
    if(value !=this->values){
        this->values=value;
        emit valuechanged();
    }
    return *this;
}

QJsonValue Int_data::jsonvalue() const
{
    return  QJsonValue::fromVariant(QVariant(this->values));
}

void Int_data::update(const QJsonObject jsonobject)
{
    if(jsonobject.contains(Key())){
        setvalue(jsonobject.value(Key()).toInt());
    }
    else {
        setvalue(0);
    }
}
}


#include "double_data.h"

namespace Data {
Data::Double_data::Double_data(Entity *parent, const QString &key, const double &values, const QString &label):
    DataDecorator(parent,key,label),
    values(values)
{

}

double Double_data::value()
{

    return this->values;
}

Double_data &Double_data::setvalue(const double &value)
{
    if(value !=this->values){
        this->values=value;
        emit valuechanged();
    }
    return *this;
}

QJsonValue Double_data::jsonvalue() const
{
    return QJsonValue::fromVariant(QVariant(this->values));
}

void Double_data::update(const QJsonObject jsonobject)
{
    if(jsonobject.contains(Key())){
        setvalue(jsonobject.value(Key()).toInt());
    }
    setvalue(0.0);

}
}



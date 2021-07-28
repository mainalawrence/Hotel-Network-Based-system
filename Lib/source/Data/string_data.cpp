#include "string_data.h"
#include<QVariant>

namespace Data {

Data::String_Data::String_Data(Data::Entity *parent, const QString &key, const QString &values, const QString &label):
    DataDecorator(parent,key,label),
    values(values)
{

}

QString String_Data::value()
{
    return this->values;
}

String_Data &String_Data::setvalue(const QString &value)
{
    if(value != this->values)
    {
        this->values=value;
        emit valuechanged();
    }
    return *this;
}

QJsonValue String_Data::jsonvalue() const
{
    return QJsonValue::fromVariant(QVariant(this->values));
}

void String_Data::update(const QJsonObject jsonobject)
{
    if(jsonobject.contains(Key())){
        setvalue(jsonobject.value(Key()).toString());
    }
    else {
        setvalue("");
    }
}

}


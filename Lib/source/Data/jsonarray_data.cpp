#include "jsonarray_data.h"
namespace Data {

Data::JsonArray_data::JsonArray_data(Data::Entity *parent, const QString &key, const QJsonArray &values, const QString &label)
    :DataDecorator(parent,key,label),
     values(values)
{

}
QJsonArray JsonArray_data::value()
{
    return this->values;

}

JsonArray_data &JsonArray_data::setvalue(const QJsonArray &value)
{
    if(value != this->values)
    {
        this->values=value;
        emit valuechanged();
    }
    return *this;
}

QJsonValue JsonArray_data::jsonvalue() const
{
    return this->values;
}

void JsonArray_data::update(const QJsonObject jsonobject)
{
    if(jsonobject.contains(Key())){
       // setvalue(jsonobject.value(Key()).toString());
    }
    else {
        //setvalue("");
    }
}
}

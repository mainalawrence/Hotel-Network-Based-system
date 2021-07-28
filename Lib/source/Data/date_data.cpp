#include "date_data.h"
#include<QVariant>

namespace Data{

Date_Data::Date_Data(Entity *parent, const QString &key, const QTime &values, const QString &label):
    DataDecorator(parent,key,label),
    values(values)
{

}
QTime Date_Data::value()
{
    return this->values;
}

Date_Data &Date_Data::setvalue(const QTime &value)
{
    if(value != this->values)
    {
        this->values=value;
        emit valuechanged();
    }
    return *this;

}

QString Date_Data::toIso8601String()
{
    if (this->values.isNull()) {
        return "";
    } else {
        return this->values.toString(Qt::ISODate);
    }
}

QString Date_Data::toPrettyDateString()
{
    if (this->values.isNull()) {
        return "";
    } else {
        return this->values.toString("d MMM yyyy");
    }
}

QString Date_Data::toPrettyTimeString()
{
    if (this->values.isNull()) {
        return "";
    } else {
        return this->values.toString("hh:mm ap");
    }
}

QString Date_Data::toPrettyString()
{
    if (this->values.isNull()) {
        return "";
    } else {
        return this->values.toString("ddd d MMM yyyy @ HH:mm:ss");
    }
}

QJsonValue Date_Data::jsonvalue() const
{
    return  QJsonValue::fromVariant(QVariant(this->values));
}

void Date_Data::update(const QJsonObject jsonobject)
{


if(jsonobject.contains(Key())){
   setvalue(jsonobject.value( Key()).toVariant().toTime());
}
else {
    setvalue(QTime());
}
}
}

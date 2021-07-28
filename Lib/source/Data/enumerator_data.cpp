#include "enumerator_data.h"
#include<QVariant>

namespace Data {

Enumerator_Data::Enumerator_Data(Entity *parent, const QString &key, const int &values, const QString &label, const std::map<int, QString> decriptionMapper)
    :DataDecorator(parent,key,label)
    ,values(values)
    ,decriptionMapper(decriptionMapper)
{

}

int Enumerator_Data::value() const
{
 return this->values;
}

Enumerator_Data &Enumerator_Data::setvalue(const int &value)
{
    if(value !=this->values){
       this->values=value;
    }
    return *this;
}

QString Enumerator_Data::valueDescription() const
{
    if(decriptionMapper.find(this->values)!= decriptionMapper.end())
    {
        return this->valueDescription().at(this->values);
    }
    else {
        return {};
    }
}

QJsonValue Enumerator_Data::jsonvalue() const
{
    return QJsonValue::fromVariant(QVariant(this->value()));

}

void Enumerator_Data::update(const QJsonObject jsonobject)
{
    if(jsonobject.contains(Key())){
        setvalue(jsonobject.value(Key()).toInt());
    }
    else {
        setvalue(0);
    }
}


}


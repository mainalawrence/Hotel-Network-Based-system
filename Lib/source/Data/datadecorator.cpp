#include "datadecorator.h"

namespace Data {

DataDecorator::DataDecorator(Entity *entity, const QString &key, const QString &label)
    : key(key),label(label),entity(entity)
{

}

DataDecorator::~DataDecorator()
{

}

const QString Data::DataDecorator::Key()
{
    return  key;
}

const QString Data::DataDecorator::Label()
{
    return label;
}

Entity *Data::DataDecorator::ParentEntity()
{
    return entity;
}
}

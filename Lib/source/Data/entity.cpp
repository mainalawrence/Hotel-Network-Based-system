#include "entity.h"


namespace Data {

Data::Entity::Entity(QObject *parent, const QString& key)
    :QObject(parent)
    ,key(key)
{

}

Entity::~Entity()
{

}

Entity::Entity(QObject *parent, QString key, QJsonObject &jsonObject)
    :QObject(parent)
    ,jsonObject(jsonObject)
    ,key(key)

{

}

const QString Entity::Key()
{
    return this->key;

}

void Entity::update(const QJsonObject &jsonObject)
{
    for(std::pair<QString,DataDecorator*>dataDecoratorpair:this->dataDecorators)
    {
        dataDecoratorpair.second->update(jsonObject);
    }
    for(std::pair<QString,Entity*>childentitypair:this->childEntities){
        childentitypair.second->update(jsonObject.value(childentitypair.first).toObject());
    }

    for(std::pair<QString,EntityCollectionBase*>childcollectionpair:this->childCollections){
        childcollectionpair.second->update(jsonObject.value(childcollectionpair.first).toArray());
    }
}

QJsonObject Entity::toJson()const
{
    QJsonObject returnValue;
    for(std::pair<QString,DataDecorator*>dataDecoratorpair:this->dataDecorators){
        returnValue.insert(dataDecoratorpair.first,dataDecoratorpair.second->jsonvalue());
    }
    for(std::pair<QString,Entity*>childEntityPair:this->childEntities){
        returnValue.insert(childEntityPair.first,childEntityPair.second->toJson());
    }

    for(std::pair<QString,EntityCollectionBase*>childcollectionpairs:this->childCollections)
    {
        QJsonArray jsonarray;
        for(Entity *entity:childcollectionpairs.second->baseEntities()){
            jsonarray.append(entity->toJson());
            returnValue.insert(childcollectionpairs.first,jsonarray);
        }
    }
    return returnValue;

}

Entity *Entity::addChild(Entity *entity, const QString& key)
{
    if(this->childEntities.find(key)==std::end(this->childEntities)){
        this->childEntities[key]=entity;
        emit childEntitiesChanged();
    }
    return entity;

}

DataDecorator *Entity::addDataitem(DataDecorator *dataDecorator)
{
    if(this->dataDecorators.find(dataDecorator->Key())==std::end(this->dataDecorators))
    {
        this->dataDecorators[dataDecorator->Key()]=dataDecorator;
        emit dataDecoratorsChanged();
    }
    return dataDecorator;

}

EntityCollectionBase *Entity::addChildCollection(EntityCollectionBase *entityCollection)
{
    if(this->childCollections.find(entityCollection->getKey())==std::end(this->childCollections))
    {
        this->childCollections[entityCollection->getKey()]=entityCollection;
        emit childCollectionsChanged(entityCollection->getKey());
    }
    return entityCollection;

}
}

















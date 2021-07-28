#ifndef ENTITY_H
#define ENTITY_H

#include <QObject>
#include<map>
#include<QJsonArray>
#include<Pos_Lib_global.h>
#include<Data/datadecorator.h>
#include<Data/Data_collection.h>


namespace Data {
class POS_LIB_EXPORT Entity : public QObject
{
    Q_OBJECT
public:
    explicit Entity(QObject *parent = nullptr,const QString& key="");
    ~Entity();
    Entity(QObject *parent,QString key,QJsonObject &jsonObject);
    const QString Key();
    void update(const QJsonObject &jsonObject);
    QJsonObject toJson() const;

signals:
    void childEntitiesChanged();
    void dataDecoratorsChanged();
    void childCollectionsChanged(const QString& collectionKey);

protected:
    Entity *addChild(Entity* entity,const QString& key);
    DataDecorator* addDataitem(DataDecorator *dataDecorator);
    QJsonObject jsonObject;
    EntityCollectionBase* addChildCollection(EntityCollectionBase* entityCollection);
private:
    Entity* entity{nullptr};
    QString key;
    QString Id;
    std::map<QString, Entity*> childEntities;
    std::map<QString, DataDecorator*> dataDecorators;
    std::map<QString, EntityCollectionBase*> childCollections;


};
}


#endif // ENTITY_H

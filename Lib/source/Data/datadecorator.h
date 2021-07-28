#ifndef DATADECORATOR_H
#define DATADECORATOR_H

#include <QObject>
#include<QJsonObject>
#include<QJsonValue>
#include<QJsonDocument>
#include<Pos_Lib_global.h>


namespace Data {
class Entity;
class  POS_LIB_EXPORT DataDecorator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString ui_Label READ Label CONSTANT)
public:
    explicit DataDecorator(Entity *entity=nullptr, const QString &key="key",const QString &label="key");
    virtual ~DataDecorator();
    const QString Key();
    const QString Label();
    Entity *ParentEntity();

    virtual QJsonValue jsonvalue()const =0;
    virtual void update(const QJsonObject jsonobject)=0;

signals:

private:
    QString key;
    QString label;
    Entity *entity{nullptr};

};
}
#endif // DATADECORATOR_H

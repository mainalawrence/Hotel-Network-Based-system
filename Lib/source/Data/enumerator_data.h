#ifndef ENUMERATOR_DATA_H
#define ENUMERATOR_DATA_H

#include <QObject>
#include<map>
#include<QJsonObject>
#include<QJsonValue>
#include<QJsonDocument>
#include<QString>
#include<Pos_Lib_global.h>
#include<Data/datadecorator.h>


namespace Data {
class POS_LIB_EXPORT Enumerator_Data : public DataDecorator
{
    Q_OBJECT
    Q_PROPERTY( int ui_value READ value WRITE setvalue NOTIFY valuechanged )
    Q_PROPERTY( QString ui_valueDescription READ valueDescription NOTIFY valuechanged )
public:
    Enumerator_Data(Entity *parent=nullptr,const QString &key="",const int &values=0,const QString &label="",
            const std::map<int,QString>decriptionMapper=std::map<int,QString>());

    int value() const;
    Enumerator_Data& setvalue(const int &value);
    QString valueDescription() const;

    QJsonValue jsonvalue()const override;
    void update(const QJsonObject jsonobject) override;

signals:
    void valuechanged();
private:
    QString key;
    int values;
    QString label;
    DataDecorator *decorator{nullptr};
    std::map<int,QString>decriptionMapper;

};
}


#endif // ENUMERATOR_DATA_H

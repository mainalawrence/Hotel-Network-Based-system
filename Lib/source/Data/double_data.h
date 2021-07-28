#ifndef DOUBLE_DATA_H
#define DOUBLE_DATA_H
#include <QObject>
#include<QJsonObject>
#include<QJsonValue>
#include<QJsonDocument>
#include<QVariant>
#include<Pos_Lib_global.h>
#include<Data/datadecorator.h>

namespace Data {

class POS_LIB_EXPORT Double_data : public DataDecorator
{
    Q_OBJECT
     Q_PROPERTY(double ui_value READ value WRITE setvalue NOTIFY valuechanged)
public:
    explicit Double_data(Entity *parent=nullptr,const QString &key="",const double &values=0.0,const QString &label="something");
    double value();
    Double_data &setvalue(const double &value);
    QJsonValue jsonvalue()const override;
    void update(const QJsonObject jsonobject) override;
signals:
    void valuechanged();
private:
    QString key;
    double values;
    QString label;
};
}
#endif // DOUBLE_DATA_H

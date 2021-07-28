#ifndef INT_DATA_H
#define INT_DATA_H

#include <QObject>
#include<QJsonObject>
#include<QJsonValue>
#include<QJsonDocument>
#include<Pos_Lib_global.h>
#include<Data/datadecorator.h>

namespace Data {
class POS_LIB_EXPORT Int_data : public DataDecorator
{
    Q_OBJECT
    Q_PROPERTY(int ui_value READ value WRITE setvalue NOTIFY valuechanged)

public:

   Int_data(Entity *parent=nullptr,const QString &key="",const int &values=0,const QString &label="");
   int value();
   Int_data &setvalue(const int &value);
   QJsonValue jsonvalue()const override;
   void update(const QJsonObject jsonobject) override;

signals:
    void valuechanged();
private:
    QString key;
    int values;
    QString label;

    DataDecorator *decorator{nullptr};

};
}


#endif // INT_DATA_H

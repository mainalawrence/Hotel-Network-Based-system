#ifndef STRING_DATA_H
#define STRING_DATA_H


#include <QObject>
#include<QJsonObject>
#include<QJsonValue>
#include<QJsonDocument>
#include<QString>
#include<Pos_Lib_global.h>
#include<Data/datadecorator.h>


namespace Data {
class POS_LIB_EXPORT String_Data : public DataDecorator
{
    Q_OBJECT
    Q_PROPERTY(QString ui_value READ value WRITE setvalue NOTIFY valuechanged)
public:
    String_Data(Entity *parent=nullptr,const QString &key="key",const QString &values="somevalue",const QString &label="label");

   QString value();
   String_Data &setvalue(const QString &value);
   QJsonValue jsonvalue()const override;
   void update(const QJsonObject jsonobject) override;


signals:
    void valuechanged();
private:
    QString key;
    QString values;
    QString label;
    DataDecorator *decorator{nullptr};

};
}
#endif // STRING_DATA_H

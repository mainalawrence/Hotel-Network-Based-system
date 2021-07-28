#ifndef DATE_DATA_H
#define DATE_DATA_H

#include <QObject>
#include<QJsonObject>
#include<QJsonValue>
#include<QJsonDocument>
#include<QTime>
#include<QDate>
#include<QVariant>
#include<Pos_Lib_global.h>
#include<Data/datadecorator.h>

namespace Data {
class POS_LIB_EXPORT Date_Data : public DataDecorator
{
    Q_OBJECT
    Q_PROPERTY(QTime ui_value READ value WRITE setvalue NOTIFY valuechanged)
    Q_PROPERTY( QString ui_iso8601String READ toIso8601String NOTIFY valuechanged )
    Q_PROPERTY( QString ui_prettyDateString READ toPrettyDateString NOTIFY valuechanged )
    Q_PROPERTY( QString ui_prettyTimeString READ toPrettyTimeString NOTIFY valuechanged )
    Q_PROPERTY( QString ui_prettyString READ toPrettyString NOTIFY valuechanged)

public:
    Date_Data(Entity *parent=nullptr,const QString &key="key",const QTime &values=QTime::currentTime(),const QString &label="label");
    QTime value();
    Date_Data &setvalue(const QTime &value);
    QString toIso8601String();
    QString toPrettyDateString();
    QString toPrettyTimeString();
    QString toPrettyString();
    QJsonValue jsonvalue()const override;
    void update(const QJsonObject jsonobject) override;

signals:
    void valuechanged();
private:
    QString key;
    QTime values;
    QString label;
    DataDecorator *decorator{nullptr};
};
}


#endif // DATE_DATA_H

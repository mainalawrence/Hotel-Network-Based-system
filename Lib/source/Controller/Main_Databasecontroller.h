#ifndef MAIN_DATABASECONTROLLER_H
#define MAIN_DATABASECONTROLLER_H
#include<Pos_Lib_global.h>
#include <QJsonArray>
#include <QJsonObject>
#include <QList>
#include <QObject>
#include <QString>
#include<QJsonDocument>

namespace Controller {
class POS_LIB_EXPORT Main_DatabaseController: public QObject
{
    Q_OBJECT
public:
    Main_DatabaseController(QObject* parent=nullptr):QObject(parent)
    {};
    virtual  bool CreateRow(const QString &Tablename,const QString UID,const QJsonObject &jsonObject)const =0;
    virtual bool DeleteRow(const QString &Tablename,const QString &UID)const=0;
    virtual bool updateRow(const QString &tablename,const QString &UID,const QJsonObject &jsonobject)const =0;
    virtual QJsonObject readRow(const QString &Tablename, QString &id)const=0;
    virtual QJsonArray Find(const QString &Tablename, const QString &searchText)const=0;
    virtual bool CreatejsonTable(QString tableName) const =0;
    virtual QHash<QString,QVariant> readTable(const QString &Tablename)const=0;
    virtual QJsonDocument readTable_Date(const QString &Tablename,const QString Date)const=0;
    virtual QJsonDocument readTable_Id(const QString &Tablename,const QString id)const=0;

};
}
#endif // MAIN_DATABASECONTROLLER_H

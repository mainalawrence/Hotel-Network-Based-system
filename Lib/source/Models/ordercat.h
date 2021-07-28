#ifndef ORDERCAT_H
#define ORDERCAT_H

#include <QAbstractListModel>
#include<QList>
#include<QString>
#include<QVariant>
#include<QJsonArray>
#include<QJsonObject>
#include<QJsonValue>
#include<QJsonDocument>
#include <QQmlListProperty>
#include<QHash>
#include<QDataStream>
#include<Pos_Lib_global.h>

struct Orders{
    QString Name;
    int Amount;
    double cost;
    double Total;
    double SumTotal;
};

namespace Models {
class POS_LIB_EXPORT OrderCat : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(double ui_totalcost READ getTotalcost NOTIFY totalcostChanged)
    Q_PROPERTY(QJsonArray ui_orderdata MEMBER orderdata CONSTANT)

public:
    enum{
        Name=0,
        Cost,
        Amount,
        Total,
        SumTotal,
        Tax,
        Totaltax
    };
    explicit OrderCat(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    // Add data:
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    // Remove data:
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    QHash<int,QByteArray>roleNames()const override;
    Q_INVOKABLE void clearCat();
    Q_INVOKABLE void addonCat(QString name,double cost,int amount,double total);
    Q_INVOKABLE bool removefromCat(int index);
    Q_INVOKABLE bool increaseAmount(int index,QString name,double cost,int amount);
    Q_INVOKABLE bool decreseAmount(int index,QString name,double cost,int amount);
     QJsonArray orderdata;
    double getTotalcost();
   Q_INVOKABLE bool settotalcost();
signals:
    void totalcostChanged();

private:
    QList<Orders> m_orders{};
     double m_totalcost=0.0;
     double m_tax=0.0;

};
}
Q_DECLARE_METATYPE(Orders)
#endif // ORDERCAT_H

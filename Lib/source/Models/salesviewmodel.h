#ifndef SALESVIEWMODEL_H
#define SALESVIEWMODEL_H

#include <QAbstractListModel>
#include<QVariant>
#include<QJsonArray>
#include<Pos_Lib_global.h>
#include<QString>



namespace Models {
struct Orders{
    QString Name;
    QString Amount;
    double Total;
    QString TableName;
    QString orderid;

};
class POS_LIB_EXPORT SalesViewModel : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(double ui_Totalcost READ Totalcost WRITE setTotalcost NOTIFY TotalcostChanged)
    Q_PROPERTY(QString ui_Amount READ Amounts WRITE setAmount NOTIFY AmountChanged)
    Q_PROPERTY(QString ui_WaiterName READ WaiterName WRITE setWaiterName NOTIFY WaiterNameChanged)
    Q_PROPERTY(QString TableNumber READ TableNumber WRITE setTableNumber NOTIFY TableNumberChanged)
     Q_PROPERTY(QString ui_orderid READ orderid WRITE setOrderid NOTIFY orderidChanged)

public:
    explicit SalesViewModel(QObject *parent = nullptr);
    ~SalesViewModel();
    enum{
        Name=0,
        Amount,
        Total,
        Tnumber,
        Orderid,

    };
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QHash<int,QByteArray>roleNames()const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    Q_INVOKABLE void populate(QString Name,QString Amount,double Total,QString TName,QString id);
     Q_INVOKABLE  void removeitems();
    bool setData(const QModelIndex &index, const QVariant &value,int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;


    double Totalcost() const;
    void setTotalcost(double Totalcost);
    QString WaiterName() const;
    void setWaiterName(const QString &WaiterName);

    QString TableNumber() const;
    void setTableNumber(const QString &TableNumber);

    QString Amounts() const;
    void setAmount(const QString &Amount);

    QString orderid() const;
    void setOrderid(const QString &orderid);

signals:
    void TotalcostChanged();
    void AmountChanged();
    void TableNumberChanged();
    void WaiterNameChanged();
    void orderidChanged();
    void arrayChanged();
private:
    QList<Orders> m_orders;
    double m_Totalcost;
    QString m_WaiterName;
    QString m_TableNumber;
    QString m_Amount;
    QString m_orderid;


};
}
#endif

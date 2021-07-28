#ifndef SALESCAT_H
#define SALESCAT_H

#include <QAbstractListModel>
#include<QJsonDocument>
#include<QByteArray>
#include<Pos_Lib_global.h>
#include<vector>
#include<Models/salesdetailsmodel.h>


struct SalesC{
    QString TableName;
    double  TotalCost;
    QString WaiterName;
    QString Amount;
    QByteArray OrderList;
    QString WaiterId;
    QString OrderNumber;
};
namespace Models{
class POS_LIB_EXPORT SalesCat : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit SalesCat(QObject *parent = nullptr);
    enum{
        TablName=0,
        Totalcost,
        WaiterId,
        Amount,
        OrderList,
        WaiterName,
        OrderNumber,
    };
    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;
    QHash<int ,QByteArray>roleNames()const override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    Q_INVOKABLE bool populate(  QList<SalesC>& data);
    Q_INVOKABLE bool remove(int index);
    Q_INVOKABLE bool clear();


    int counter() const;

private:
    QList<SalesC> m_Ordersale;
    int m_counter=m_Ordersale.count();
};
}
#endif // SALESCAT_H

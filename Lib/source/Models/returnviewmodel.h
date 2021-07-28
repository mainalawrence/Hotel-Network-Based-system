#ifndef RETURNVIEWMODEL_H
#define RETURNVIEWMODEL_H

#include <QAbstractListModel>
#include<Pos_Lib_global.h>

namespace Models {
struct ReturtnOrders{
    QString Name;
    int Amount;
    double cost;
    double Total;
    double SumTotal;
};
class POS_LIB_EXPORT ReturnViewModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum{
        Name=0,
        Cost,
        Amount,
        Total,
        SumTotal,

    };
    explicit ReturnViewModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;
     QHash<int,QByteArray>roleNames()const override;

    Q_INVOKABLE void populate(QString name,double cost,int amount,double total);
    Q_INVOKABLE bool increaseAmount(int index,QString name,double cost,int amount);
    Q_INVOKABLE bool decreseAmount(int index,QString name,double cost,int amount);
      Q_INVOKABLE bool removefromCat(int index);

private:
     QList<ReturtnOrders> m_orders{};
};
}
#endif // RETURNVIEWMODEL_H

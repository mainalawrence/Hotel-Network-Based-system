#ifndef SALESDETAILSMODEL_H
#define SALESDETAILSMODEL_H

#include <QAbstractListModel>
#include<QJsonArray>
#include<QDebug>
#include<Pos_Lib_global.h>
#include<QList>


struct SalesModel{
    QString name;
    QString cost;
    QString Amount;
    QString Total;
};

namespace Models {
class POS_LIB_EXPORT SalesDetailsModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum{
        name=0,
        cost,
        amount,
        total,
    };
    explicit SalesDetailsModel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;
   Q_INVOKABLE void populate(QJsonArray &data);
    QHash<int,QByteArray> roleNames() const override;

private:
    QList<SalesModel>m_data;
};
}
#endif // SALESDETAILSMODEL_H

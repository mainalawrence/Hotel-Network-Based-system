#ifndef TODOMODEL_H
#define TODOMODEL_H

#include <QAbstractListModel>
#include<Pos_Lib_global.h>
#include<QVariant>
#include<vector>

struct Saless{
    QString Rno;
    QString totalcost;
    QString payment;
    QString Date;
    QString Servedby;
    QString Description;
};
namespace Models {

class POS_LIB_EXPORT BarReportModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit BarReportModel(QObject *parent = nullptr);
    enum RoleName{
        ReceitNumber=0,
        Totalcost,
        PaymentType,
        SaleDate,
        UserName,
        Details

    };
    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    Q_INVOKABLE virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    virtual QHash<int,QByteArray> roleNames() const override;

      void setSales(QList<Saless> &data);

private:
    QList<Saless> mysale;


};
}


#endif // TODOMODEL_H

#ifndef RETURNSMODEL_H
#define RETURNSMODEL_H

#include <QAbstractTableModel>
#include<QString>
#include<QHash>
#include<QByteArray>
#include<Pos_Lib_global.h>

struct Returns{
   QString OrderNo;
   QString Amount;
   QString Date;
   QString WaitersName;
   QString Totalcost;
   QString  Details;

};


namespace Models {
class ReturnsModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit ReturnsModel(QObject *parent = nullptr);
    enum{
        orderNo=0,
        amount,
        date,
        waitersName,
        totalcost,
        details
    };
    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int,QByteArray>roleNames()const override;

    void populate(QList<Returns>&data);

private:
    QList<Returns>m_Returns;
};
}


#endif // RETURNSMODEL_H

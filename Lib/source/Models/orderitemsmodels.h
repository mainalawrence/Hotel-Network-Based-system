#ifndef ORDERITEMSMODELS_H
#define ORDERITEMSMODELS_H

#include <QAbstractListModel>
#include<Pos_Lib_global.h>
#include<QList>
#include<QHash>

struct Orderdisp{
    QString Name;
    float Cost;
    QString itemId;
};
namespace Models {
class POS_LIB_EXPORT OrderItemsModels : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit OrderItemsModels(QObject *parent = nullptr);
    enum{
       Name=0,
        Cost,
        itemid,
    };
    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QHash<int,QByteArray> roleNames()const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    int columnCount(const QModelIndex&parent=QModelIndex())const override;

   Q_INVOKABLE void populate( QList<Orderdisp>& data);
   Q_INVOKABLE void depopulate();

private:
    QList<Orderdisp>m_items;
};
}
#endif // ORDERITEMSMODELS_H

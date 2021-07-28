#ifndef ITEMVIEWMODELS_H
#define ITEMVIEWMODELS_H

#include <QAbstractTableModel>
#include<Pos_Lib_global.h>
#include<QList>
#include<QVariant>
#include<QDebug>
struct itemView{
    QString id;
    QString Name;
    QString category;
    QString itemgroup;
    QString cost;
};

namespace Models {
class POS_LIB_EXPORT ItemViewModels : public QAbstractTableModel
{
    Q_OBJECT

public:
    enum{
      id,
      Name,
      category,
      itemgroup,
      cost,
    };
    explicit ItemViewModels(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;
    QHash<int ,QByteArray>roleNames()const override;
    Q_INVOKABLE void deleteItem(int index);
    void populate(QList<itemView>& m_items);
private:
    QList<itemView> m_items;
};
}
#endif // ITEMVIEWMODELS_H

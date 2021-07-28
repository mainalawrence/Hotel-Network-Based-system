#ifndef ORDERTABLEMODEL_H
#define ORDERTABLEMODEL_H

#include <QAbstractListModel>
#include<Pos_Lib_global.h>
#include<QList>

struct Tables{
  QString  tables;
};

namespace Models{
class POS_LIB_EXPORT OrderTablemodel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit OrderTablemodel(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    void populate( QList<Tables> &data);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int ,QByteArray>roleNames()const override;

private:
    QList<Tables> m_Tablename;
};
}
#endif // ORDERTABLEMODEL_H

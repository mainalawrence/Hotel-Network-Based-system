#ifndef WAITERMODELVIEW_H
#define WAITERMODELVIEW_H

#include <QAbstractListModel>
#include<Pos_Lib_global.h>

struct waiterDerails{
    QString Name;
    QString IdNumber;
};
namespace Models {


class POS_LIB_EXPORT WaiterModelView : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit WaiterModelView(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int,QByteArray>roleNames()const override;
    void populate(QList<waiterDerails>& data);

private:
    QList<waiterDerails>m_details;
};
}
#endif // WAITERMODELVIEW_H

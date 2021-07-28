#ifndef WORKINGHOURSVIEWSMODLE_H
#define WORKINGHOURSVIEWSMODLE_H

#include <QAbstractTableModel>
#include<Pos_Lib_global.h>
#include<QVector>


namespace Models {

struct WorkingHours
{
    QString Id;
    QString Name;
    QString Login;
    QString LogOut;
    QString AveHours;
};

class POS_LIB_EXPORT WorkingHoursViewsModle : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit WorkingHoursViewsModle(QObject *parent = nullptr);

    enum{
        Id,
        Name,
        Login,
        LogOut,
        WorkingHours,
    };
    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;
    QHash<int,QByteArray>roleNames()const override;
    void populate(QList<Models::WorkingHours>& data);

    private:
        QList<Models::WorkingHours> m_Data;
};
}
#endif // WORKINGHOURSVIEWSMODLE_H

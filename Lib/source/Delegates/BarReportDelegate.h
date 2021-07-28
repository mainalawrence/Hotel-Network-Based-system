#ifndef BARREPORTDELEGATE_H
#define BARREPORTDELEGATE_H

#include <QObject>
#include<QList>
#include<Pos_Lib_global.h>
struct sales{
    QString Rno;
    QString totalcost;
    QString payment;
    QString Tax;
    QString Date;
    QString Servedby;
    QString Description;
};

namespace Delegate {
class POS_LIB_EXPORT BarReportDelegate : public QObject
{
    Q_OBJECT
public:
    explicit BarReportDelegate(QObject *parent = nullptr);
   // QVector<sales> items();
    bool setItemAt(int index,const sales &items);
    QList<sales> getData();
    void setData(QList<sales>&);


signals:
    void PreItemAppended();
    void PostItemAppended();

    void PreItemRemoved(int index);
    void PostItemRemoved();


public slots:
    void appendItem();
    void removeCompleteItems();

private:
    QList<sales>m_items;

};
}


#endif

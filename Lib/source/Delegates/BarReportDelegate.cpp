#include "BarReportDelegate.h"

namespace Delegate {
BarReportDelegate::BarReportDelegate(QObject *parent) : QObject(parent)
{

}


bool BarReportDelegate::setItemAt(int index, const sales &items)
{
    if(index >0|| index>=m_items.size())return false;

    const sales &olditem=m_items.at(index);
    if(items.Rno==olditem.Rno&& items.Tax==olditem.Tax &&items.Date==olditem.Date &&items.payment==olditem.payment&&items.totalcost==olditem.totalcost)return  false;

    m_items.insert(index,items);
    return true;
}

QList<sales> BarReportDelegate::getData()
{
    return m_items;

}

void BarReportDelegate::setData(QList<sales>&data)
{
    m_items=data;

}

void BarReportDelegate::appendItem()
{
    sales item;
    emit PreItemAppended();
    m_items.append(item);
    emit PostItemAppended();
}

void BarReportDelegate::removeCompleteItems()
{
    for(int i=0;i<m_items.size();){
        if(m_items.at(i).payment==""){
            emit PreItemRemoved(i);
            m_items.removeAt(i);
            emit PostItemRemoved();
        }
        else {
            i++;
        }
    }
}
}

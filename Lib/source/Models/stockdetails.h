#ifndef STOCKDETAILS_H
#define STOCKDETAILS_H

#include <QObject>
#include<Data/entity.h>
#include<Data/int_data.h>
#include<Data/double_data.h>
#include<Data/string_data.h>
#include<Pos_Lib_global.h>


namespace Models {
class POS_LIB_EXPORT StockDetails : public Data::Entity
{
    Q_OBJECT
    Q_PROPERTY(Data::String_Data* ui_itemgroup MEMBER stockitemgroup CONSTANT )
    Q_PROPERTY(Data::String_Data* ui_category MEMBER stockcategory CONSTANT )
    Q_PROPERTY(Data::String_Data* ui_stockid READ getStockid  WRITE setStockid)
    Q_PROPERTY(Data::String_Data* ui_stockname READ getStockname  WRITE setStockname)
    Q_PROPERTY(Data::Double_data* ui_stockcost MEMBER stockcost CONSTANT)
    Q_PROPERTY(QString ui_allStockdetails READ stockDetails)
public:
   explicit StockDetails(QObject *parent=nullptr);
   StockDetails (QObject *parent,QJsonObject &json);

   Data::String_Data* stockid{nullptr};
   Data::String_Data* stockname{nullptr};
   Data::Double_data* stockcost{nullptr};
   Data::String_Data* stockitemgroup{nullptr};
   Data::String_Data* stockcategory{nullptr};
   QString stockDetails()const;
   QString Itemid()const;
   Data::String_Data *getStockid() const;
   void setStockid(Data::String_Data *value);
  Data::String_Data* getStockname() const;
   void setStockname(Data::String_Data *value);
};
}


#endif // STOCKDETAILS_H

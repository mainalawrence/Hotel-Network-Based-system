#include "tabledetails.h"

namespace Models {
using namespace Data;
TableDetails::TableDetails(QObject *parent): Data::Entity(parent,"Tables")
{
  TDetails=static_cast<String_Data*>(addDataitem(new String_Data(this,"Table","Tables")));
}

TableDetails::TableDetails(QObject *parent, QJsonObject &jsonobj):TableDetails(parent)
{
    update(jsonobj);
}

}

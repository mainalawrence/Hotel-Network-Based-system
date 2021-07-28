#include "orderdetails.h"

namespace Data {
Data::OrderDetails::OrderDetails()

{
    Name=static_cast<String_Data*>(addDataitem(new String_Data(this,"name","name")));
    Amount=static_cast<String_Data*>(addDataitem(new String_Data(this,"amount","amount")));
    cost=static_cast<String_Data*>(addDataitem(new String_Data(this,"cost","cost")));
    Total=static_cast<String_Data*>(addDataitem(new String_Data(this,"total","total")));
    tax=static_cast<String_Data*>(addDataitem(new String_Data(this,"tax","tax")));
}
}

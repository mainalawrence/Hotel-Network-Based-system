QT -= gui
QT  +=sql network qml
QT += printsupport

TEMPLATE = lib
DEFINES += POS_LIB_LIBRARY

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
TARGET =Pos_Lib
SOURCES += \
    Source/Controller/database_controller.cpp \
    Source/Controller/mastercontroller.cpp \
    Source/Data/datadecorator.cpp \
    Source/Data/date_data.cpp \
    Source/Data/double_data.cpp \
    Source/Data/entity.cpp \
    Source/Data/enumerator_data.cpp \
    Source/Data/int_data.cpp \
    Source/Data/jsonarray_data.cpp \
    Source/Data/orderdetails.cpp \
    Source/Data/sales_datatype.cpp \
    Source/Data/string_data.cpp \
    Source/Database/reporttabledetailsdb.cpp \
    Source/Database/stockdetailsdb.cpp \
    Source/Database/userclockdb.cpp \
    Source/Database/userentry.cpp \
    Source/Delegates/BarReportDelegate.cpp \
    Source/Delegates/reporttabledelegate.cpp \
    Source/Models/ReportModel.cpp \
    Source/Models/appsettings.cpp \
    Source/Models/itemviewmodels.cpp \
    Source/Models/listorderdetails.cpp \
    Source/Models/myclocktime.cpp \
    Source/Models/ordercat.cpp \
    Source/Models/orderitemsmodels.cpp \
    Source/Models/ordertablemodel.cpp \
    Source/Models/orderup.cpp \
    Source/Models/pos_lib.cpp \
    Source/Models/pos_users.cpp \
    Source/Models/reporttablemodel.cpp \
    Source/Models/restaurantsalesreportmodel.cpp \
    Source/Models/returns.cpp \
    Source/Models/returnsmodel.cpp \
    Source/Models/returnviewmodel.cpp \
    Source/Models/sales.cpp \
    Source/Models/salescat.cpp \
    Source/Models/salesdetailsmodel.cpp \
    Source/Models/salesviewmodel.cpp \
    Source/Models/stockdetails.cpp \
    Source/Models/tabledetails.cpp \
    Source/Models/userviewmodel.cpp \
    Source/Models/waitermodelview.cpp \
    Source/Models/workinghoursviewsmodle.cpp \
    Source/Networking/Server/myclient.cpp \
    Source/Networking/Server/myserver.cpp \
    Source/Networking/Server/servertasks.cpp \
    Source/Networking/Server/sevrcontoller.cpp \
    Source/Networking/Socket/mysocket.cpp \
    Source/Networking/Socket/socketcontroller.cpp \
    Source/Printer/printecontrol.cpp


HEADERS += \
    Source/Controller/Main_Databasecontroller.h \
    Source/Controller/database_controller.h \
    Source/Controller/mastercontroller.h \
    Source/Controller/navigation-controller.h \
    Source/Data/Data_collection.h \
    Source/Data/datadecorator.h \
    Source/Data/date_data.h \
    Source/Data/double_data.h \
    Source/Data/entity.h \
    Source/Data/enumerator_data.h \
    Source/Data/int_data.h \
    Source/Data/jsonarray_data.h \
    Source/Data/orderdetails.h \
    Source/Data/sales_datatype.h \
    Source/Data/string_data.h \
    Source/Database/reporttabledetailsdb.h \
    Source/Database/stockdetailsdb.h \
    Source/Database/userclockdb.h \
    Source/Database/userentry.h \
    Source/Delegates/BarReportDelegate.h \
    Source/Delegates/reporttabledelegate.h \
    Source/Models/ReportModel.h \
    Source/Models/appsettings.h \
    Source/Models/itemviewmodels.h \
    Source/Models/listorderdetails.h \
    Source/Models/myclocktime.h \
    Source/Models/ordercat.h \
    Source/Models/orderitemsmodels.h \
    Source/Models/ordertablemodel.h \
    Source/Models/orderup.h \
    Source/Models/pos_lib.h \
    Source/Models/pos_users.h \
    Source/Models/reporttablemodel.h \
    Source/Models/restaurantsalesreportmodel.h \
    Source/Models/returns.h \
    Source/Models/returnsmodel.h \
    Source/Models/returnviewmodel.h \
    Source/Models/sales.h \
    Source/Models/salescat.h \
    Source/Models/salesdetailsmodel.h \
    Source/Models/salesviewmodel.h \
    Source/Models/stockdetails.h \
    Source/Models/tabledetails.h \
    Source/Models/userviewmodel.h \
    Source/Models/waitermodelview.h \
    Source/Models/workinghoursviewsmodle.h \
    Source/Networking/Server/myclient.h \
    Source/Networking/Server/myserver.h \
    Source/Networking/Server/servertasks.h \
    Source/Networking/Server/sevrcontoller.h \
    Source/Networking/Socket/mysocket.h \
    Source/Networking/Socket/socketcontroller.h \
    Source/Pos_Lib_global.h \
    Source/Printer/printecontrol.h \
    salesdetailsmodel.h


INCLUDEPATH +=Source
# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

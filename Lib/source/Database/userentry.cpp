#include "userentry.h"
using namespace Controller;
using namespace DataBase;

UserEntry::UserEntry(QObject *parent, Main_DatabaseController *databasecontroller, Pos_Users *users):
    QObject(parent),databasecontroller(databasecontroller),posUsers(users)
{

}
void UserEntry::userssaved()
{
 //auto data=this->posUsers->AlluserDetails();
    //qDebug()<<"saved well"<<data;
}

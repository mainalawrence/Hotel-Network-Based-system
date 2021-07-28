#ifndef USERS_H
#define USERS_H

#include <QObject>
#include<JsonData/Data/userdetailsentry.h>
#include<Pos_Lib_global.h>

namespace JsonData {
namespace Models {
class POS_LIB_EXPORT Users : public QObject
{
    Q_OBJECT
public:
    explicit Users(QObject *parent = nullptr);
    typedef  QList<UserDetailsEntry*>UserList;
    UserDetailsEntry*createUser();
    bool Delete(UserDetailsEntry*);

    UserList getUserlist() const;

signals:
    void userAdded(UserDetailsEntry*);
    void userremoved(UserDetailsEntry*);
private:
    UserList userlist;

};
}}
#endif // USERS_H

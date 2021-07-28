#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include<Pos_Lib_global.h>
#include<QTcpServer>
#include<QTcpSocket>
#include<QAbstractSocket>
#include"myclient.h"


namespace Network {
namespace Server {
class  POS_LIB_EXPORT Myserver : public QTcpServer
{
    Q_OBJECT
public:
    Myserver(QObject *parent=nullptr);
    void startServer();
protected:
    void incomingConnection(qintptr handle) override;

private:
    QList<Myclient*>clients;
};
}}


#endif // MYSERVER_H

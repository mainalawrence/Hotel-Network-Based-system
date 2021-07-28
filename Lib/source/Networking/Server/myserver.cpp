#include "myserver.h"


namespace Network {
namespace Server {

Myserver::Myserver(QObject *parent):QTcpServer(parent)
{

}

void Myserver::startServer()
{
    if(listen(QHostAddress::Any,2020)){
        qDebug()<<"started";

    }
    else {
        qDebug()<<"Failed";
    }

}

void Myserver::incomingConnection(qintptr handle)
{

    Myclient *myclient=new Myclient(this);
    myclient->setSocket(handle);
}

}}


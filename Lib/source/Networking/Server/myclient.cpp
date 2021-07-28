#include "myclient.h"

namespace Network {
namespace Server {
Myclient::Myclient(QObject *parent) : QObject(parent)
{
    QThreadPool::globalInstance()->setMaxThreadCount(20);
    socket=new QTcpSocket(this);
    connect(socket,SIGNAL(read4yRead()),this,SLOT(readyRead()));
}

void Myclient::setSocket(int Descriptior)
{
    socket->setSocketDescriptor(Descriptior);
    if(socket->ConnectedState !=QAbstractSocket::ConnectedState)
    {
        qDebug()<<"disconnected";
    }
}
void Myclient::readyRead()
{
    ServerTasks *servertask=new ServerTasks();
    servertask->setAutoDelete(true);
    QThreadPool::globalInstance()->start(servertask);
    connect(this,SIGNAL(Request(QJsonDocument)),servertask,SLOT(Request(QJsonDocument)));
    connect(servertask,SIGNAL(Responds(QJsonDocument)),this,SLOT(Responds(QJsonDocument)));
    QJsonDocument doc=QJsonDocument::fromBinaryData(socket->readAll());
    emit Request(doc);
    socket->disconnect();
}

void Myclient::Responds(QJsonDocument doc)
{
    socket->write(doc.toBinaryData());
}

}
}

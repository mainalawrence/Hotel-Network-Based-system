#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QObject>
#include<Pos_Lib_global.h>
#include<QThreadPool>
#include<QTcpSocket>
#include"servertasks.h"
#include<QJsonArray>
#include<QJsonObject>
#include<QJsonDocument>
#include<QJsonValue>

namespace Network {
namespace Server {
class POS_LIB_EXPORT Myclient : public QObject
{
    Q_OBJECT
public:
     Myclient(QObject *parent = nullptr);
    void setSocket(int Descriptior);


public slots:
    void readyRead();
    void Responds(QJsonDocument doc);
signals:
    void sendpass(QByteArray);
    void Request(QJsonDocument doc);
private:
    QTcpSocket *socket;
    QStringList ipaddesses;
    QString datawriten;
    QByteArray json;
    QList<QTcpSocket*>_conSockets;
};
}}
#endif // MYCLIENT_H

#include <Controller/database_controller.h>
#include<QtDebug>
#include<QSqlError>
namespace Controller {

Database_controller::Database_controller(QObject *parent) : Main_DatabaseController(parent)
{
    Readfile();
    m_databaseconnected=false;
    if(databaseinitialization()){
        if(createTable()){
            qDebug() << "Database tables created";
            emit dbconnected(true);
        }
        else {
            qDebug() << "ERROR: Unable to create database tables";
        }
    }
    else {
        qDebug() << "ERROR: Unable to open database";
    }
}

bool Database_controller::CreatetableRow(QString data) const
{
    QSqlQuery query(db);

    QString sqlstatement="INSERT INTO tables (Noid) VALUES(:data)";
    if(!query.prepare(sqlstatement)) return  false;
    query.bindValue(":data",QVariant(data));
    if(!query.exec()) return  false;
    return  query.numRowsAffected()>0;
}
bool Database_controller::CreateRow(const QString &Tablename, const QString UID, const QJsonObject &jsonObject)const
{
    QSqlQuery query(db);
    if(Tablename.isEmpty()|| UID.isEmpty()) return false;

    QString sqlstatement="INSERT INTO "+  Tablename +" (UID,json) VALUES(:UID,:json)";
    if(!query.prepare(sqlstatement)) return  false;
    query.bindValue(":UID",QVariant(UID));
    query.bindValue(":json",QVariant(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact)).toString());
    if(!query.exec()) return  false;
    return  query.numRowsAffected()>0;
}

bool Database_controller::DeleteRow(const QString &Tablename, const QString &UID)const
{
    QSqlQuery query(db);
    QString sqlstatement;
    if(Tablename.isEmpty()||UID.isEmpty()) return false;
    if(Tablename=="users"){
        sqlstatement  ="DELETE  FROM "+Tablename +" WHERE uid=:id";
    }
    else {
        sqlstatement  ="DELETE FROM "+Tablename +" WHERE uid=:id";
    }

    if(!query.prepare(sqlstatement)) return  false;
    query.bindValue(":id",UID);
    if(!query.exec()) return  false;
    return  query.numRowsAffected()>0;

}

bool Database_controller::DeleteRowS(const QString &Tablename, const QString &id) const
{
    QSqlQuery query(db);
    QString sqlstatement;
    sqlstatement  ="DELETE  FROM "+Tablename +" WHERE id=:id";
    if(!query.prepare(sqlstatement)) return  false;
    query.bindValue(":id",id);
    if(!query.exec()) return  false;
    return  query.numRowsAffected()>0;
}

bool Database_controller::updateRow(const QString &tablename, const QString &UID, const QJsonObject &jsonobject)const
{
    QSqlQuery query(db);
    if(tablename.isEmpty()||UID.isEmpty()||jsonobject.isEmpty()) return false;
    QString sqlstatement="UPDATE"+tablename+"SET json=:json WHERE id=:id";
    if(!query.prepare(sqlstatement)) return false;
    query.bindValue(":id",QVariant(UID));
    query.bindValue(":json",QVariant(QJsonDocument(jsonobject).toJson(QJsonDocument::Compact)).toString());
    if(!query.exec())return false;
    return query.numRowsAffected()>0;

}

QJsonObject Database_controller::readRow(const QString &Tablename, QString &UID)const
{
    QSqlQuery query(db);
    if(Tablename.isEmpty()||UID.isEmpty()) return {};
    QString sqlStatement="SELECT json FROM "+Tablename+"WHERE id=:id";
    if(!query.prepare(sqlStatement)) return {};
    query.bindValue(":id",QVariant(UID));
    if(!query.exec()) return  {};
    if(!query.first())return {};
    auto json=query.value(0).toByteArray();
    auto jsonDocument=QJsonDocument::fromJson(json);
    if(jsonDocument.isEmpty())return {};
    return  jsonDocument.object();

}

QJsonArray Database_controller::Find(const QString &Tablename, const QString &searchText)const
{
    QSqlQuery query(db);
    if(Tablename.isEmpty()||searchText.isEmpty()) return {};
    QString sqlStatement="SELECT json FROM " + Tablename + "WHERE lower(json) like :searchText";
    if(!query.prepare(sqlStatement)) return {};
    query.bindValue(":searchText",QVariant("% "+searchText.toLower()+"%"));
    if(!query.exec()) return {};
    QJsonArray returnvalue;

    while (query.next()) {
        auto json = query.value(0).toByteArray();
        auto jsonDocument = QJsonDocument::fromJson(json);
        if (jsonDocument.isObject()) {
            returnvalue.append(jsonDocument.object());
        }
    }
    return returnvalue;
}

bool Database_controller::databaseinitialization()
{
    db = QSqlDatabase::addDatabase("QODBC3");
    db.setDatabaseName("DRIVER={PostgreSQL ANSI};SERVER="+ServerName+";DATABASE="+DatabaseName);
    db.setUserName(DataBaseUserName); // Set Login Username
    db.setPassword(Databasepassword);
    db.setPort(databaseport);
    return db.open();
}

void Database_controller::Readfile()
{
    QJsonDocument data;
    QFile file("settings.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    while (!file.atEnd()) {
        data =QJsonDocument::fromJson(file.readAll());
    }
    ServerName=data["DatabaseAddress"].toString();
    DatabaseName=data["databaseName"].toString();
    DataBaseUserName=data["DatabaseUserName"].toString();
    databaseport=data["DatabasePort"].toInt();
    Databasepassword=data["Password"].toString();

}

bool Database_controller::getDatabaseconnected() const
{
    return m_databaseconnected;
}
int Database_controller::getDatabaseport() const
{
    return databaseport;
}

void Database_controller::setDatabaseport(int value)
{
    databaseport = value;
}

QString Database_controller::getDatabasepassword() const
{
    return Databasepassword;
}

void Database_controller::setDatabasepassword(const QString &value)
{
    Databasepassword = value;
}

QString Database_controller::getDataBaseUserName() const
{
    return DataBaseUserName;
}

void Database_controller::setDataBaseUserName(const QString &value)
{
    DataBaseUserName = value;
}

QString Database_controller::getServerName() const
{
    return ServerName;
}

void Database_controller::setServerName(const QString &value)
{
    ServerName = value;
}

QString Database_controller::getDatabaseName() const
{
    return DatabaseName;
}

void Database_controller::setDatabaseName(const QString &value)
{
    if(value.isEmpty()){
        DatabaseName="LocalHost";
    }
    DatabaseName = value;
}

bool Database_controller::createTable()
{
    return (CreatejsonTable("Users"),
            CreatejsonTable("Stocks")
            ,CreateOderTable("Restaurant_Orders")
            ,CreateOderTable("Bar_Orders")
            ,CreateOderTable("Bar_sales")
            ,CreateOderTable("Restaurant_sales")
            ,CreateOderTable("Bar_Returns")
            ,CreateOderTable("Restaurant_Returns")
            ,CreatejsonTable("Users_clock")
            ,creatabletable()
            );
}

bool Database_controller::creatabletable()
{
    QSqlQuery queryt(db);
    QString qstatementt="CREATE TABLE IF NOT EXISTS tables(id BIGSERIAL NOT NULL,Noid text NOT NULL PRIMARY KEY)";
    if(!queryt.prepare(qstatementt)) return false;
    return queryt.exec();
}

QList<SalesC> Database_controller::readtableorders(const QString tablename)
{

    QList<SalesC>data;
    data.clear();
    QString statement;
    QString sdetails;//Tname,ttcost,waitername,amount,ordelist,waiterid,ordernumber
    statement="SELECT json->'tableNo',json->'totalCost',json->'tax',json->'soldBy', json->'amountorderd',json->'details',json->'WaiterId',id FROM  "+ tablename;
    QSqlQuery query(db);
    QSqlQuery qDetails(db);
    if(!query.prepare(statement)) return {};
    if(!query.exec()) return  {};
    while (query.next()) {
        data.append({query.value(0).toString(),//tname
                     query.value(1).toDouble(),//totalcost
                     query.value(3).toString(),//waitername
                     query.value(4).toString(),//amount
                     (query.value(5).toByteArray()),//ordelist
                     query.value(6).toString(),//waiterid
                     query.value(7).toString(),
                    });

    }

    return data;
}

QList<Saless> Database_controller::readTablebar_sales(const QString tablename,const QString id,const QString name)
{
    QList<Saless>data;
    data.clear();
    QString statement;
    if(!id.isEmpty()) {
        statement="SELECT id ,json->>'recite',json->>'totalcost', json->>'tax' ,json->>'paymenttype' ,json->>'date'  ,json->>'name', json->>'description' From "+ tablename+ " WHERE json->>'WaiterId'=':id'";
    }
    if(!name.isEmpty()) {
        statement="SELECT id ,json->>'recite',json->>'totalcost', json->>'tax' ,json->>'paymenttype' ,json->>'date'  ,json->>'name', json->>'description' From "+ tablename+ " WHERE json->>'name'=':name'";
    }
    else {
        statement="SELECT id ,json->>'recite',json->>'totalCost', json->>'tax' ,json->>'PaymentType' ,json->>'saleDate'  ,json->>'soldBy', json->>'Details' From "+tablename;

    }
    QSqlQuery query(db);
    query.bindValue(":id",id);
    query.bindValue(":name",name);
    if(!query.prepare(statement)) return {};
    if(!query.exec()) return  {};
    while (query.next()) {
        data.append({query.value(0).toString(),
                     query.value(2).toString(),
                     query.value(4).toString(),
                     query.value(5).toString(),
                     query.value(6).toString(),
                     query.value(7).toString()});
    }
    return data;

}

QList<Returns> Database_controller::readTable_returns(const QString tablename, const QString id,const QString name)
{
    QList<Returns>data;
    data.clear();
    QString statement;
    if(!id.isEmpty()) {
        statement="SELECT id ,json->>'recite',json->>'totalCost', json->>'tax' ,json->>'PaymentType' ,json->>'saleDate'  ,json->>'soldBy', json->>'Details' From "+tablename+"WHERE json->'WaiterId'="+id;

    }
    if(!name.isEmpty()) {
        statement="SELECT id ,json->>'recite',json->>'amount', json->>'date' ,json->>'name' ,json->>'totalcost'  ,json->>'details' From "+tablename+ " WHERE json->>'name'=:id";

    }
    else {
        statement="SELECT id ,json->>'recite',json->>'totalCost', json->>'tax' ,json->>'PaymentType' ,json->>'saleDate'  ,json->>'soldBy', json->>'Details' From "+tablename;

    }
    QSqlQuery query(db);
    data.clear();
    query.bindValue(":id",id);
    query.bindValue(":name",name);
    if(!query.prepare(statement)) return {};
    if(!query.exec()) return  {};
    while (query.next()) {
        data.append({query.value(0).toString(),
                     query.value(2).toString(),
                     query.value(4).toString(),
                     query.value(5).toString(),
                     query.value(6).toString(),
                     query.value(7).toString()});
    }
    return data;
}

QList<Users> Database_controller::readTable_Users(const QString tablename, const QString id, const QString name)
{
    QList<Users>data;
    data.clear();
    QString statement;
    if(!id.isEmpty()) {
        statement="SELECT json->>'firstName','json->>lastName'  , json->>'idnumber',json->>'passowrd',json->>'userName ',json->>' role' ,json->>'gender', json->>' email'  ,json->>' address' From "+tablename+ " WHERE id=:id";

    }
    if(!name.isEmpty()) {
        statement="SELECT json->>'firstName','json->>lastName'  , json->>'idnumber',json->>'passowrd', json->>'userName',json->>'role' ,json->>'gender', json->>' email'  ,json->>' address' From "+tablename+ " WHERE json->>'name'=:id";
    }
    else {
        statement="SELECT json->>'firstName',json->>'lastName',json->>'idNumber' ,json->>'password' ,json->>'userName'  ,json->>'role' ,json->>'gender', json->>'email',json->>'address' From  "+tablename;
    }
    QSqlQuery query(db);
    query.bindValue(":id",id);
    query.bindValue(":name",name);
    if(!query.prepare(statement)) return {};
    if(!query.exec()) return  {};
    while (query.next()) {
        data.append({query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toString(),query.value(7).toString(),query.value(8).toString()});
    }
    return data;

}

QList<Models::WorkingHours> Database_controller::readTable_usersclock(const QString id)
{
    QList<Models::WorkingHours>data;
    data.clear();
    QString statement="SELECT uid,'json->>'name', json->>'login',json->>'logout' ,json->>'ave' FROM users_clock where uid=:id ";
    if(id.isEmpty()) {};
    QSqlQuery query(db);
    query.bindValue(":id",id);
    if(!query.prepare(statement)) return {};
    if(!query.exec()) return  {};
    while (query.next()) {
        data.append({query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString()});
    }
    return data;

}

QList<itemView> Database_controller::readTable_stock(const QString id)
{
    QList<itemView>data;
    data.clear();
    QString statement;
    if(id.isEmpty()) {
        statement="SELECT uid, json->>'stockName',json->>'category',json->>'itemgroup', json->>'stockTax', json->>'stockCost' from stocks ";
    }
    else {
        statement="SELECT  json->>'stockName',json->>'category',json->>'itemgroup', json->>'stockTax', json->>'stockCost',uid from stocks where uid="+id;
    }
    QSqlQuery query(db);
    if(!query.prepare(statement)) return {};
    if(!query.exec()) return  {};
    while (query.next()) {
        data.append({query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(4).toString(),query.value(5).toString()});
    }
    return data;

}

QList<Orderdisp> Database_controller::readTable_orders(const QString tableName, const QString category, const QString group)
{
    Q_UNUSED(tableName);
    QList<Orderdisp>data;
    data.empty();
    QString statement;
    if(category=="Restaurant"){
        statement="SELECT  json->>'stockName',json->>'category',json->>'itemgroup', json->>'stockTax', json->>'stockCost' ,uid from stocks WHERE  json->>'category'='Restaurant'";
    }
    else if(category.toLower()=="bar"){
        statement="SELECT  json->>'stockName',json->>'category',json->>'itemgroup', json->>'stockTax', json->>'stockCost' ,uid from stocks WHERE  json->>'category'='Bar'";
    }
    else if(group.toLower()=="drinks"){
        statement="SELECT  json->>'stockName',json->>'category',json->>'itemgroup', json->>'stockTax', json->>'stockCost' ,uid from stocks WHERE  json->>'itemgroup'='Drinks'";
    }
    else if(group.toLower()=="breakfast"){
        statement="SELECT  json->>'stockName',json->>'category',json->>'itemgroup', json->>'stockTax', json->>'stockCost' ,uid from stocks WHERE  json->>'itemgroup'='Breakfast'";
    }
    else if(group.toLower()=="snacks"){
        statement="SELECT  json->>'stockName',json->>'category',json->>'itemgroup', json->>'stockTax', json->>'stockCost' ,uid from stocks WHERE  json->>'itemgroup'='Snacks'";
    }
    else if(group.toLower()=="heavy meal"){
        statement="SELECT  json->>'stockName',json->>'category',json->>'itemgroup', json->>'stockTax', json->>'stockCost' ,uid from stocks WHERE  json->>'itemgroup'='Heavy meal'";
    }
    QSqlQuery query(db);
    if(!query.prepare(statement)) return {};
    if(!query.exec()) return  {};
    while (query.next()) {
        data.append({query.value(0).toString(),query.value(4).toFloat(),query.value(5).toString()});
    }
    return data;
}

QList<waiterDerails> Database_controller::readWaiter()
{
    QList<waiterDerails>data;
    data.clear();
    QSqlQuery query(db);
    QString qstatement="SELECT json->'firstName',uid FROM users WHERE json->>'role'='Waiter'";
    if(!query.prepare(qstatement)) return {};
    if(!query.exec()) return {};
    while (query.next()) {
        data.append({query.value(0).toString(),query.value(1).toString()});
    }
    return  data;
}

QList<Tables> Database_controller::readtables()
{
    QList<Tables> data;
    data.clear();
    QSqlQuery query;
    query.exec("SELECT * tables");
    while (query.next()) {
        data.append({query.value(1).toString()});
    }
    return  data;
}

QList<Saless> Database_controller::readrestaurantsale_id(QString t_name, QString u_id)
{
    QList<Saless>data;
    data.clear();
    QString q_statement="SELECT id ,json->>'recite',json->>'totalcost', json->>'tax' ,json->>'paymenttype' ,json->>'date'  ,json->>'name', json->>'description' From "+ t_name+ " WHERE json->>'WaiterId'="+u_id;
    QSqlQuery query;
    if(t_name.isEmpty())return {};
    if(!query.prepare(q_statement))return {};
    if(!query.exec()) return {};
    while (query.next()) {
        data.append({query.value(0).toString(),
                     query.value(2).toString(),
                     query.value(4).toString(),
                     query.value(5).toString(),
                     query.value(6).toString(),
                     query.value(7).toString()});
    }
    return data;
}

QList<Saless> Database_controller::readbarsales_id(QString t_name, QString u_id)
{
    QList<Saless>data;
    data.clear();
    QString q_statement="SELECT id ,json->>'recite',json->>'totalcost', json->>'tax' ,json->>'paymenttype' ,json->>'date'  ,json->>'name', json->>'description' From "+ t_name+ " WHERE json->>'WaiterId'="+u_id;
    QSqlQuery query;
    if(t_name.isEmpty())return {};
    if(!query.prepare(q_statement))return {};
    if(!query.exec()) return {};
    while (query.next()) {
        data.append({query.value(0).toString(),
                     query.value(2).toString(),
                     query.value(4).toString(),
                     query.value(5).toString(),
                     query.value(6).toString(),
                     query.value(7).toString()});
    }
    return data;
}

QList<Returns> Database_controller::readrestaurantreturns_id(QString t_name, QString u_id)
{
    QList<Returns>data;
    data.clear();
    QString q_statement="SELECT id ,json->>'recite',json->>'totalCost', json->>'tax' ,json->>'PaymentType' ,json->>'saleDate'  ,json->>'soldBy', json->>'Details' From "+t_name+"WHERE json->'WaiterId'="+u_id;
    QSqlQuery query;
    if(t_name.isEmpty())return {};
    if(!query.prepare(q_statement))return {};
    if(!query.exec()) return {};
    while (query.next()) {
        data.append({query.value(0).toString(),
                     query.value(2).toString(),
                     query.value(4).toString(),
                     query.value(5).toString(),
                     query.value(6).toString(),
                     query.value(7).toString()});
    }
    return data;
}

QList<Returns> Database_controller::readbarreturns_id(QString t_name, QString u_id)
{
    QList<Returns>data;
    data.clear();
    QString q_statement="SELECT id ,json->>'recite',json->>'totalCost', json->>'tax' ,json->>'PaymentType' ,json->>'saleDate'  ,json->>'soldBy', json->>'Details' From "+t_name+"WHERE json->'WaiterId'="+u_id;
    QSqlQuery query;
    if(t_name.isEmpty())return {};
    if(!query.prepare(q_statement))return {};
    if(!query.exec()) return {};
    while (query.next()) {
        data.append({query.value(0).toString(),
                     query.value(2).toString(),
                     query.value(4).toString(),
                     query.value(5).toString(),
                     query.value(6).toString(),
                     query.value(7).toString()});
    }
    return data;
}
QStringList Database_controller::logincheck(QString userN, QString passW)
{
    res.clear();
    QSqlQuery query(db);
    QString qstatement="SELECT  uid ,json->>'password',json->>'userName' ,json->>'role',json->>'firstName' , json->>'idnumber' "
                       "FROM users where  json->>'password'=:passW and  json->>'userName'=:userN";
    query.prepare(qstatement);
    query.bindValue(":passW",passW);
    query.bindValue(":userN",userN);
    if(!query.exec()) {qDebug()<<query.lastError();}
    else {
        while (query.next()) {
            auto uid=query.value(0).toString();
            auto password=query.value(1).toString();
            auto username=query.value(2).toString();
            auto Role=query.value(3).toJsonValue().toString();
            auto FirstName=query.value(4).toJsonValue().toString();
            auto userid=query.value(5).toString();
            if(userN==username&&passW==password){
                res.append(uid);
                res.append(FirstName);
                res.append(Role);
                res.append(userid);
                return res;
                break;
            }
        }
        if(query.next()==false) {
            qDebug()<<"wrong"<<endl;

        }
    }

    return res;
}
bool Database_controller::CreatejsonTable(QString tableName)const
{
    QSqlQuery query(db);
    QString qstatement="CREATE TABLE IF NOT EXISTS "+tableName+"(id BIGSERIAL NOT NULL,UID text NOT NULL PRIMARY KEY,json JSONB NOT NULL)";
    if(!query.prepare(qstatement)) return false;
    return query.exec();

}


bool Database_controller::CreateOderTable(QString tableName) const
{
    QSqlQuery query(db);
    QString qstatement="CREATE TABLE IF NOT EXISTS "+tableName+"(id BIGSERIAL NOT NULL PRIMARY KEY,json JSONB NOT NULL)";
    if(!query.prepare(qstatement)) return false;
    return query.exec();
}

bool Database_controller::CreateorderRow(const QString &Tablename, const QJsonObject &jsonObject) const
{
    QSqlQuery query(db);
    if(Tablename.isEmpty()) return false;
    QString sqlstatement="INSERT INTO "+  Tablename +" (json) VALUES(:json)";
    if(!query.prepare(sqlstatement)) return  false;
    query.bindValue(":json",QVariant(QJsonDocument(jsonObject).toJson(QJsonDocument::Compact)).toString());
    if(!query.exec()) return  false;
    return  query.numRowsAffected()>0;
}

bool Database_controller::updateclockRow(const QString id,const QJsonObject &jsonobject)
{
    QSqlQuery query(db);
    QString sqlstatement="UPDATE users_clock SET json=:json WHERE uid=:id";
    if(!query.prepare(sqlstatement)) return false;
    query.bindValue(":id",id);
    query.bindValue(":json",QVariant(QJsonDocument(jsonobject).toJson(QJsonDocument::Compact)).toString());
    if(!query.exec())return false;
    return query.numRowsAffected()>0;
}
QString Database_controller::getorderNumber(QString Tnumber)
{   QSqlQuery query(db);
    QString statement="SELECT id from "+Tnumber;
    query.prepare(statement);
    query.exec();
    query.last();
    auto size=query.value(0).toInt();
    QString sizestrinf=query.last()==false?QString::number(0): QString::number(size+1);
    return sizestrinf;
}

QHash<QString,QVariant> Database_controller::readTable(const QString &Tablename) const
{
    QHash<QString,QVariant> hash;
    hash.clear();
    QByteArray doc;
    if(Tablename.isEmpty()) return {};
    QSqlQuery query(db);
    QString qstatement="SELECT id , json From "+Tablename;
    if(!query.prepare(qstatement)) return {};
    if(!query.exec()) return  {};
    if(!query.first())return {};
    while (query.next()) {
        hash.insert(query.value(0).toString(),query.value(1));
    }
    return hash;
}
QJsonDocument Database_controller::readTable_Date(const QString &Tablename, const QString Date)const
{
    QJsonDocument doc;
    if(Tablename.isEmpty()) return {};
    QSqlQuery query(db);
    QString qstatement="SELECT id ,json From "+Tablename+"  WHERE json->>'date'=':date'";
    query.bindValue(":date",Date);
    if(!query.prepare(qstatement)) return {};
    if(!query.exec()) return  {};
    if(!query.first())return {};
    while (query.next()) {
        auto jsonkey=query.value(0).toString();
        auto json= query.value(1).toByteArray();
        doc=QJsonDocument::fromJson(json);
        if(doc.isEmpty())return {};
        qDebug()<<json;
    }
    return doc;
}

QJsonDocument Database_controller::readTable_Id(const QString &Tablename, const QString id)const
{
    QJsonDocument doc;
    if(Tablename.isEmpty()) return {};
    QSqlQuery query(db);
    QString qstatement="SELECT id ,json From "+Tablename +" WHERE json->>'UID'=':id'";
    query.bindValue(":id",id);
    if(!query.prepare(qstatement)) return {};
    if(!query.exec()) return  {};
    if(!query.first())return {};
    while (query.next()) {
        auto jsonkey=query.value(0).toString();
        auto json= query.value(1).toByteArray();
        //QJsonObject w(jsonkey,json);
        doc=QJsonDocument::fromJson(json);
        if(doc.isEmpty())return {};
        qDebug()<<json;
    }
    return doc;
}

QString Database_controller::readclock(QString id)
{
    QString data;
    data.clear();
    QSqlQuery query(db);
    QString qstatement="SELECT json->'Clockin' FROM users_clock WHERE uid='"+id+"'";
    query.bindValue(":id",id);
    if(!query.prepare(qstatement)) return {};
    if(!query.exec())  return  {};
    while(query.next()) {
        data=query.value(0).toString();
    }
    return data;
}

QString Database_controller::getServer() const
{
    return ServerName;
}

void Database_controller::setServer(const QString &value)
{

    ServerName = value;
}
}

#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>

#include "dbmanager.h"

DbManager::DbManager(QObject *parent) : QObject(parent) {

}

void DbManager::init(const QString &path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database failed";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

void DbManager::insertData(const QString &boxName, const qint64 &startTime, const qint64 &endTime)
{
    qDebug() << "inserting data for: "<<boxName;
    QSqlQuery query;
    query.prepare("INSERT INTO AMBRC_Reports (boxname, startTime, endTime) VALUES (:boxName, :startTime, :endTime)");
    query.bindValue(":boxName", boxName);
    query.bindValue(":startTime", startTime);
    query.bindValue(":endTime", endTime);

    if(query.exec()) {
        qDebug()<<"update success for: "<<boxName;
    } else {
        qDebug()<<"update failed for: "<<boxName;
    }
}

qint64 DbManager::getCummulativeDuration(const QString &boxName)
{
    qDebug()<<__FUNCTION__<<boxName;
    qint64 cummulativeDuration = 0;

    QSqlQuery query;
    query.prepare("SELECT startTime, endTime from AMBRC_Reports WHERE boxName IN (:boxName)");

    query.bindValue(":boxName", boxName);

    if(query.exec()) {
        qDebug()<<"query executed";
    } else {
        qDebug()<<"query not able to execute";
    }

    QSqlRecord rec = query.record();

    qDebug()<<"columns count: "<<rec.count();
    qDebug()<<"rows count: "<<query.size();
    int nameColStartTime = rec.indexOf("startTime");
    int nameColEndTime = rec.indexOf("endTime");

    while(query.next()) {
        qint64 startTime = query.value(nameColStartTime).toInt();
        qint64 endTime = query.value(nameColEndTime).toInt();
        qDebug()<<"row data startTime: "<<startTime<<" endTime: "<<endTime;
        qint64 duration = endTime - startTime;
        qDebug()<<"row duration: "<<duration;
        cummulativeDuration += duration;
    }

    return cummulativeDuration;
}

void DbManager::getDbData(QList<HistoryMenuItems> &historyList)
{
    QSqlQuery query("SELECT * from AMBRC_Reports");
    QSqlRecord rec = query.record();

    qDebug()<<"columns count: "<<rec.count();
    int nameColboxName = rec.indexOf("boxName");
    int nameColStartTime = rec.indexOf("startTime");
    int nameColEndTime = rec.indexOf("endTime");
    while(query.next()) {
        QString boxName = query.value(nameColboxName).toString();
        qint64 startTime = query.value(nameColStartTime).toInt();
        qint64 endTime = query.value(nameColEndTime).toInt();
        qDebug()<<"row data boxName:"<<boxName<<" startTime: "<<startTime<<" endTime: "<<endTime;

        HistoryMenuItems menuItem;
        menuItem.boxName = boxName;
        menuItem.startTime = startTime;
        menuItem.endTime = endTime;

        historyList.append(menuItem);
    }
}

#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QObject>
#include <QString>
#include <QSqlDatabase>

#include "historylistmodel.h"

class DbManager : public QObject
{
    Q_OBJECT
public:
    explicit DbManager(QObject *parent = nullptr);

    void init(const QString& path="");

    void insertData(const QString &boxName, const qint64 &startTime, const qint64 &endTime);

    qint64 getCummulativeDuration(const QString &boxName);

    void getDbData(QList<HistoryMenuItems> &historyList);


private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_H

#include <QDateTime>
#include <QtDebug>

#include <QSqlDatabase>

#include "abmrcappdata.h"


ABMRCAppData::ABMRCAppData(QObject *parent) : QObject(parent) {

}

void ABMRCAppData::init(const QString &databasePath)
{
    m_dbManager.init(databasePath);
    m_historyListModel = new HistoryListModel(this, &m_dbManager);
}

HistoryListModel *ABMRCAppData::historylistmodel()
{
    return m_historyListModel;
}

qint64 ABMRCAppData::currentDuration()
{
//    qDebug() <<__FUNCTION__<<m_currentDuration;
    return m_currentDuration;
}

qint64 ABMRCAppData::cummuilativeDuration()
{
    return m_cummilativeDuration;
}

void ABMRCAppData::buttonPressStart(QString buttonName)
{
    resetFields();
    m_boxName = buttonName;
    m_startTimeEpoc = QDateTime::currentSecsSinceEpoch();
    qDebug()<<buttonName<<" start Time: "<<m_startTimeEpoc;
}

void ABMRCAppData::updateDb(QString buttonName)
{
    qint64 endTimeEpoc = QDateTime::currentSecsSinceEpoch();
    m_currentDuration = endTimeEpoc - m_startTimeEpoc;
    qDebug()<<buttonName<<" duration Time: "<<m_currentDuration;

    m_dbManager.insertData(buttonName, m_startTimeEpoc, endTimeEpoc);

    m_cummilativeDuration = m_dbManager.getCummulativeDuration(buttonName);

    m_historyListModel->dbUpdated();

    emit currrentDurationChanged();
    emit cummuilativeDurationChanged();

}

void ABMRCAppData::resetFields()
{
       m_boxName = "";
       m_currentDuration = 0;
       m_cummilativeDuration = 0;
       m_startTimeEpoc = 0;
}

#include "historylistmodel.h"
#include "dbmanager.h"

HistoryListModel::HistoryListModel(QObject *parent, DbManager *dbManager) : QAbstractListModel(parent),
    m_dbManagerObj(dbManager)
{
    m_dbManagerObj->getDbData(m_historyData);
    m_cummDurInfoMap = new QMap<QString, qint64>();
}

QHash<int, QByteArray> HistoryListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
        roles[boxRole] = "boxName";
        roles[startTimeRole] = "startTime";
        roles[endTimeRole] = "endTime";
        roles[currentDurationRole] = "currentDuration";
        roles[cummuDurationRole] = "cummulativeDuration";
        return roles;
}

int HistoryListModel::rowCount(const QModelIndex &parent) const
{
   return m_historyData.count();
}

QVariant HistoryListModel::data(const QModelIndex &index, int role) const
{
    if(!hasIndex(index.row(), index.column(), index.parent())) { return {}; }

    QVariant data;

    if(role == boxRole) {
        data = m_historyData.at(index.row()).boxName;
    } else if (role == startTimeRole) {
        data = m_historyData.at(index.row()).startTime;
    } else if (role == endTimeRole) {
        data = m_historyData.at(index.row()).endTime;
    } else if (role == currentDurationRole) {
        data = m_historyData.at(index.row()).endTime - m_historyData.at(index.row()).startTime;
    } else if (role == cummuDurationRole) {
        QString boxName = m_historyData.at(index.row()).boxName;
        qint64 duration = m_historyData.at(index.row()).endTime - m_historyData.at(index.row()).startTime;
        qint64 cummulativeDuration = duration + m_cummDurInfoMap->value(boxName);

        m_cummDurInfoMap->insert(boxName, cummulativeDuration);
        data = cummulativeDuration;
    }

    return data;
}

void HistoryListModel::dbUpdated()
{
    beginResetModel();
    if(m_historyData.size() > 0) {
        m_historyData.clear();
    }
    m_cummDurInfoMap->clear();
    m_dbManagerObj->getDbData(m_historyData);
    endResetModel();
}

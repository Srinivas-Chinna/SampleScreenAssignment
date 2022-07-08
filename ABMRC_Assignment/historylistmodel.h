#ifndef HISTORYLISTMODEL_H
#define HISTORYLISTMODEL_H

#include <QAbstractListModel>
#include <QMap>

//#include "dbmanager.h"

class DbManager;

struct HistoryMenuItems {
    QString boxName = "";
    qint64 startTime = 0;
    qint64 endTime = 0;

//    qint64 currentDuration;
//    qint64 cummuDuration;
};

class HistoryListModel  : public QAbstractListModel
{
    Q_OBJECT

    Q_ENUMS(HistoryRoles)
public:
    explicit HistoryListModel(QObject *parent=nullptr, DbManager *dbManager=nullptr);


    enum HistoryRoles {
            boxRole = Qt::UserRole + 1,
            startTimeRole,
            endTimeRole,
            currentDurationRole,
            cummuDurationRole,
        };

    QHash<int, QByteArray> roleNames() const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    void dbUpdated();

signals:

private:
    QList<HistoryMenuItems> m_historyData;
    QMap<QString, qint64> *m_cummDurInfoMap; //it will store the prevously evaluated cummulatvive info for boxName wise
    DbManager *m_dbManagerObj;
};

#endif // HISTORYLISTMODEL_H

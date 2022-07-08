#ifndef ABMRCAPPDATA_H
#define ABMRCAPPDATA_H

#include <QObject>

#include "dbmanager.h"
#include "historylistmodel.h"

class ABMRCAppData : public QObject
{
    Q_OBJECT
public:
    explicit ABMRCAppData(QObject *parent = nullptr);

    void init(const QString &databasePath);

    Q_PROPERTY(qint64 currentDuration READ currentDuration NOTIFY currrentDurationChanged);
    Q_PROPERTY(qint64 cummuilativeDuration READ cummuilativeDuration NOTIFY cummuilativeDurationChanged);

    Q_PROPERTY(HistoryListModel *historylistmodel READ historylistmodel);

    HistoryListModel *historylistmodel();

    qint64 currentDuration();
    qint64 cummuilativeDuration();

public slots:
    void buttonPressStart(QString buttonName);
    void updateDb(QString buttonName);

signals:
    void currrentDurationChanged();
    void cummuilativeDurationChanged();

private:
    void resetFields();

    DbManager m_dbManager;
    HistoryListModel *m_historyListModel;

    QString m_boxName;
    qint64 m_startTimeEpoc;
    qint64 m_currentDuration;
    qint64 m_cummilativeDuration;

};

#endif // ABMRCAPPDATA_H

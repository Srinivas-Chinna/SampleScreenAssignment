#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuick>
#include <QTimer>
#include <QDebug>

#include "abmrcappdata.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);


    QQuickView view;
    view.rootContext()->setContextProperty("currentDateTime", QDateTime::currentDateTime());

    qDebug()<<"argc: "<<argc;

    QString dbPath = "/home/srinivas/workspace/qt/sqliteDb/AMBRC_Reports.db";
    if(argc > 1) {
        dbPath = argv[1];
    }

    ABMRCAppData appData;
    appData.init(dbPath);
    view.rootContext()->setContextProperty("appData", &appData);

    view.setSource(QUrl("qrc:/main.qml"));
    view.show();

    return app.exec();
}

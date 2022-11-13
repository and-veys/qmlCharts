#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "mychart.h"
#include "linefunction.h"



int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    MyChart ch;
    engine.rootContext()->setContextProperty("chart", &ch);
    LineFunction lf;
    engine.rootContext()->setContextProperty("line", &lf);

    engine.load(url);

    return app.exec();
}

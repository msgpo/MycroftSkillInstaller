#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtWidgets/QApplication>
#include <QQuickStyle>
#include <QIcon>
#include <QStringList>
#include "scriptlauncher.h"
#include "filereader.h"

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon("qrc:mycroft-plasma-appicon.png"));
    QQuickStyle::setStyle("Material");
    qmlRegisterType<ScriptLauncher>("MycroftLauncher", 1, 0, "ScriptLauncher");
    qmlRegisterType<FileReader>("FileReader", 1, 0, "FileReader");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:main.qml")));
    app.processEvents();
    return app.exec();
}

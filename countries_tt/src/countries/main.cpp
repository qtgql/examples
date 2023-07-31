#include <QtGui>
#include <QtQuick>
#include "filesystem"

namespace fs = std::filesystem;

int main(int argc, char *argv[]){
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QUrl url((fs::path(__FILE__).parent_path().parent_path() / "qml" / "main.qml").c_str());
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
                if (!obj && url == objUrl)
                    QCoreApplication::exit(-1);
            }, Qt::QueuedConnection);
    engine.load(url);

    return QGuiApplication::exec();
}
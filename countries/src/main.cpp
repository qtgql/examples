#include "qtgql/bases/detail/environment.hpp"
#include "qtgql/bases/detail/networklayer.hpp"
#include "qtgql/gqloverhttp/detail/gqloverhttp.hpp"
#include <QtGui>
#include <QtQuick>
#include <filesystem>
#include <memory>
#include <qtgql/bases/bases.hpp>
#include <qtgql/gqloverhttp/gqloverhttp.hpp>


namespace fs = std::filesystem;

int main(int argc, char *argv[]){
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    auto env = std::shared_ptr<qtgql::bases::Environment>(
        new qtgql::bases::Environment("Countries", 
    
        std::unique_ptr<qtgql::bases::NetworkLayerABC>(new qtgql::gqloverhttp::GraphQLOverHttp({"https://countries.trevorblades.com/"})))
    );
    qtgql::bases::Environment::set_gql_env(env);



    QUrl url((fs::path(__FILE__).parent_path() / "qml" / "main.qml").c_str());
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
                if (!obj && url == objUrl)
                    QCoreApplication::exit(-1);
            }, Qt::QueuedConnection);
    engine.load(url);
    return QGuiApplication::exec();
}
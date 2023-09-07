#include <QtGui>
#include <QtQuick>
#include <filesystem>
#include <memory>
#include <qtgql/bases/bases.hpp>
#include <qtgql/gqloverhttp/gqloverhttp.hpp>

#include "graphql/__generated__/ContinentQuery.hpp"

namespace fs = std::filesystem;

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);
  QQmlApplicationEngine engine;
  auto env =
      std::shared_ptr<qtgql::bases::Environment>(new qtgql::bases::Environment(
          "Countries",

          std::unique_ptr<qtgql::bases::NetworkLayerABC>(
              new qtgql::gqloverhttp::GraphQLOverHttp(
                  {"https://countries.trevorblades.com/"}))));
  qtgql::bases::Environment::set_gql_env(env);
  auto cont_query = Countries::continentquery::ContinentQuery::shared();
  cont_query->set_variables(
      Countries::continentquery::ContinentQueryVariables{.code = "EU"});
  cont_query->fetch();
  engine.rootContext()->setContextProperty("query", cont_query.get());
  QUrl url((fs::path(__FILE__).parent_path() / "qml" / "main.qml").c_str());
  engine.load(url);
  return QGuiApplication::exec();
}

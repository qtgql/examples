#include "app.hpp"
#include "utils/qml_hot_reload.hpp"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtLocation/QGeoServiceProvider>

int main(int argc, char *argv[]) {
  QGuiApplication q_application(argc, argv);
  QQmlApplicationEngine engine;
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreationFailed, &q_application,
      []() { QCoreApplication::exit(-1); }, Qt::QueuedConnection);
  auto m_app = App(&engine);
  qmlRegisterSingletonInstance("App", 1, 0, "App", &m_app);

  auto qml_dir = fs::path(__FILE__).parent_path() / "qml";
  auto main_qml = QUrl::fromLocalFile((qml_dir / "playground.qml").c_str());
  qDebug() << main_qml;
  Q_ASSERT(qml_dir.is_absolute());
  engine.load(main_qml);
  init_hot_reload(&engine, qml_dir);
  return q_application.exec();
}

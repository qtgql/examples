#pragma once
#include "filesystem"
#include <QDirIterator>
#include <QFileSystemWatcher>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QQuickWindow>
#include <QTimer>
#include <QUrl>

namespace fs = std::filesystem;

void init_hot_reload(QQmlApplicationEngine *engine, const fs::path &path) {
  QFileSystemWatcher *w = new QFileSystemWatcher(engine);
  QDirIterator it(path, QDirIterator::Subdirectories);
  while (it.hasNext()) {
    it.next();
    auto i = it.fileInfo();
    if (i.isFile())
      w->addPath(i.absoluteFilePath());
  }

  QUrl mainPath = QUrl::fromLocalFile((path / "/playground.qml").c_str());

  QObject::connect(
      w, &QFileSystemWatcher::fileChanged, [=](const QString &file) {
        engine->clearComponentCache();

        auto window =
            qobject_cast<QQuickWindow *>(engine->rootObjects().first());
        auto loader = window->findChild<QQuickItem *>("debug_loader");
        QEventLoop().processEvents(QEventLoop::ProcessEventsFlag::AllEvents,
                                   1000);
        auto prev = loader->property("source");
        loader->setProperty("source", "");
        loader->setProperty("source", prev);
      });
};

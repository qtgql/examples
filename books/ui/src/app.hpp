#pragma once
#include "QtQmlIntegration/qqmlintegration.h"
#include "graphql/__generated__/AllBooks.hpp"
#include "graphql/__generated__/CreateBook.hpp"
#include <QObject>

#include <QtPositioning>

using namespace Books;

class App : public QObject {
  Q_OBJECT
  QML_UNCREATABLE("foo")
  Q_PROPERTY(locations_query::LocationsQuery *locationsQuery READ
                 get_locationsquery CONSTANT)

public:
  explicit App(QObject *parent = nullptr);
  allbooks::AllBooks *get_allbooks_query();
  createbook::CreateBook *get_createbook_mutation();
public slots:
  const createbook::CreateBook *create_book(const QString &title,
                                            const QString &content,
                                            const QString &author);

protected:
  std::shared_ptr<locations_query::LocationsQuery> m_locations_query;
  std::shared_ptr<close_trackimo_event::CloseTrackimoEvent>
      m_close_trackimo_event_mut;
};

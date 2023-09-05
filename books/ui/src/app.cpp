#include "app.hpp"
#include <qtgql/gqloverhttp/gqloverhttp.hpp>

App::App(QObject *parent) : QObject{parent} {
  auto client = std::unique_ptr<qtgql::gqloverhttp::GraphQLOverHttp>(
      new qtgql::gqloverhttp::GraphQLOverHttp(
          {"http://127.0.0.1:8000/graphql"}));
  auto env = std::shared_ptr<qtgql::bases::Environment>(
      new qtgql::bases::Environment{"GisPoc", std::move(client)});
  qtgql::bases::Environment::set_gql_env(env);
  m_close_trackimo_event_mut =
      close_trackimo_event::CloseTrackimoEvent::shared();
  m_locations_query = locations_query::LocationsQuery::shared();
  m_locations_query->fetch();
  m_events_query = events_query::EventsQuery::shared();
  m_events_query->fetch();
  auto refetch_timer = new QTimer();
  refetch_timer->setInterval(5000);
  connect(refetch_timer, &QTimer::timeout, [this] {
    m_locations_query->refetch();
    m_events_query->refetch();
  });
  refetch_timer->start();
}

locations_query::LocationsQuery *App::get_locationsquery() {
  return m_locations_query.get();
}

events_query::EventsQuery *App::get_eventsquery() {
  return m_events_query.get();
}

const close_trackimo_event::CloseTrackimoEvent *
App::close_trackimo_event(const QString &event_id) {
  m_close_trackimo_event_mut->set_variables({{event_id}});
  m_close_trackimo_event_mut->completed()
      ? m_close_trackimo_event_mut->refetch()
      : m_close_trackimo_event_mut->fetch();
  return m_close_trackimo_event_mut.get();
}

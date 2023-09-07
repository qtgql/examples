#include "app.hpp"
#include <QJSEngine>
#include <qtgql/gqloverhttp/gqloverhttp.hpp>

App::App(QObject *parent) : QObject{parent} {
  auto client = std::unique_ptr<qtgql::gqloverhttp::GraphQLOverHttp>(
      new qtgql::gqloverhttp::GraphQLOverHttp(
          {"http://127.0.0.1:8000/graphql"}));
  auto env = std::shared_ptr<qtgql::bases::Environment>(
      new qtgql::bases::Environment{"Books", std::move(client)});
  m_delete_book_mut = deletebook::DeleteBook::shared();
  connect(m_delete_book_mut.get(), &deletebook::DeleteBook::completed,
          [this] { this->m_all_books_query->refetch(); });
  qtgql::bases::Environment::set_gql_env(env);
  m_create_book_mut = createbook::CreateBook::shared();
  m_all_books_query = allbooks::AllBooks::shared();
  QJSEngine::setObjectOwnership(m_delete_book_mut.get(),
                                QJSEngine::CppOwnership);
  m_all_books_query->fetch();
  auto refetch_timer = new QTimer(this);
  refetch_timer->setInterval(500);
  connect(refetch_timer, &QTimer::timeout, [this] {
    if (m_all_books_query->completed())
      m_all_books_query->refetch();
  });
  refetch_timer->start();
}

const createbook::CreateBook *App::create_book(const QString &title,
                                               const QString &content,
                                               const QString &author) {
  m_create_book_mut->set_variables(
      {Books::CreateBookInput::create(title, author, content)});
  m_create_book_mut->completed() ? m_create_book_mut->refetch()
                                 : m_create_book_mut->fetch();
  return m_create_book_mut.get();
}

allbooks::AllBooks *App::get_allbooks_query() {
  return m_all_books_query.get();
}

const deletebook::DeleteBook *App::delete_book(const QString &book_id) {
  m_delete_book_mut->set_variables({book_id});
  m_delete_book_mut->completed() ? m_delete_book_mut->refetch()
                                 : m_delete_book_mut->fetch();
  return m_delete_book_mut.get();
}

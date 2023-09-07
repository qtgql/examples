#pragma once
#include "QtQmlIntegration/qqmlintegration.h"
#include "graphql/__generated__/AllBooks.hpp"
#include "graphql/__generated__/CreateBook.hpp"
#include "graphql/__generated__/DeleteBook.hpp"

#include <QObject>

using namespace Books;

class App : public QObject {
  Q_OBJECT
  QML_UNCREATABLE("foo")
  Q_PROPERTY(allbooks::AllBooks *allBooksQuery READ get_allbooks_query CONSTANT)

public:
  explicit App(QObject *parent = nullptr);
  allbooks::AllBooks *get_allbooks_query();
public slots:
  [[maybe_unused]] const createbook::CreateBook *
  create_book(const QString &title, const QString &content,
              const QString &author);
  [[maybe_unused]] const deletebook::DeleteBook *
  delete_book(const QString &book_id);

protected:
  std::shared_ptr<allbooks::AllBooks> m_all_books_query;
  std::shared_ptr<createbook::CreateBook> m_create_book_mut;
  std::shared_ptr<deletebook::DeleteBook> m_delete_book_mut;
};

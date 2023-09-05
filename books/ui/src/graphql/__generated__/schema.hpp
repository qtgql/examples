#pragma once
#include <QObject>
#include <QJsonObject>
#include <QJsonArray>
#include <memory>

#include <qtgql/bases/bases.hpp>
#include <qtgql/customscalars/customscalars.hpp>


namespace Books{


// ---------- INPUT OBJECTS ----------
/*
 * None
 */
struct CreateBookInput{

public:
QString title;
QString author;
QString content;
[[nodiscard]] QJsonObject to_json() const{
    auto __ret = QJsonObject();
    
__ret.insert("title",  title
);


    
__ret.insert("author",  author
);


    
__ret.insert("content",  content
);


    return __ret;
}

template<typename... Args>
static std::shared_ptr<CreateBookInput> create(Args... args){
    return std::make_shared<CreateBookInput>(args...);
}


};


// Forward references
class Book;
class BookCreatePayload;
class EntityAlreadyExistsError;
class Mutation;
class Query;


// ---------- Interfaces ----------
class Node  :  public qtgql::bases::NodeInterfaceABC {
Q_OBJECT

public:
std::shared_ptr<qtgql::bases::scalars::Id>
 m_id = nullptr;

signals:
void idChanged();


public:

[[nodiscard]] const std::shared_ptr<qtgql::bases::scalars::Id> &get_id()const{
return m_id;
}
void set_id(const std::shared_ptr<qtgql::bases::scalars::Id> & v)
{
m_id = v;
emit idChanged();
};




static auto & ENV_CACHE() {
        static auto cache = qtgql::bases::Environment::get_env_strict("Books")->get_cache();
        return cache;
}

};
class Error  :  public qtgql::bases::ObjectTypeABC {
Q_OBJECT

public:
std::shared_ptr<QString>
 m_message = nullptr;

signals:
void messageChanged();


public:

[[nodiscard]] const std::shared_ptr<QString> &get_message()const{
return m_message;
}
void set_message(const std::shared_ptr<QString> & v)
{
m_message = v;
emit messageChanged();
};





};


// ---------- Object Types ----------

class Book :  public Node {
Q_OBJECT
public:
std::shared_ptr<QString>
 m_title = nullptr;
std::shared_ptr<QString>
 m_author = nullptr;
std::shared_ptr<QString>
 m_content = nullptr;

signals:
void titleChanged();
void authorChanged();
void contentChanged();


public:

[[nodiscard]] const std::shared_ptr<QString> &get_title()const{
return m_title;
}
void set_title(const std::shared_ptr<QString> & v)
{
m_title = v;
emit titleChanged();
};

[[nodiscard]] const std::shared_ptr<QString> &get_author()const{
return m_author;
}
void set_author(const std::shared_ptr<QString> & v)
{
m_author = v;
emit authorChanged();
};

[[nodiscard]] const std::shared_ptr<QString> &get_content()const{
return m_content;
}
void set_content(const std::shared_ptr<QString> & v)
{
m_content = v;
emit contentChanged();
};

public:
static std::optional<std::shared_ptr<Book>> get_node(const QString & id){
    auto node = ENV_CACHE()->get_node(id);
    if (node.has_value()){
        return std::static_pointer_cast<Book>(node.value());
    }
    return {};
}


public:

QTGQL_STATIC_MAKE_SHARED(Book)


Book()= default;

public:
inline const QString & __typename() const final{
static const QString ret = "Book";
return ret;
};
};
class BookCreatePayload :  public qtgql::bases::ObjectTypeABC {
Q_OBJECT
public:
std::shared_ptr<Book>
 m_result = nullptr;
std::shared_ptr<qtgql::bases::ObjectTypeABC>
 m_error = nullptr;

signals:
void resultChanged();
void errorChanged();


public:

[[nodiscard]] const std::shared_ptr<Book> &get_result()const{
return m_result;
}
void set_result(const std::shared_ptr<Book> & v)
{
m_result = v;
emit resultChanged();
};

[[nodiscard]] const std::shared_ptr<qtgql::bases::ObjectTypeABC> &get_error()const{
return m_error;
}
void set_error(const std::shared_ptr<qtgql::bases::ObjectTypeABC> & v)
{
m_error = v;
emit errorChanged();
};



public:

QTGQL_STATIC_MAKE_SHARED(BookCreatePayload)


BookCreatePayload()= default;

public:
inline const QString & __typename() const final{
static const QString ret = "BookCreatePayload";
return ret;
};
};
class EntityAlreadyExistsError :  public Error {
Q_OBJECT
public:

signals:


public:



public:

QTGQL_STATIC_MAKE_SHARED(EntityAlreadyExistsError)


EntityAlreadyExistsError()= default;

public:
inline const QString & __typename() const final{
static const QString ret = "EntityAlreadyExistsError";
return ret;
};
};
class Mutation :  public qtgql::bases::ObjectTypeABC {
Q_OBJECT
public:
std::unordered_map<QJsonObject, std::shared_ptr<BookCreatePayload>, qtgql::bases::tools::QJsonValueHasher>
 m_createBook = {};

signals:
void createBookChanged();


public:

[[nodiscard]] const std::shared_ptr<BookCreatePayload> &get_createBook(const QJsonObject & args )const{
return m_createBook.at(args);
}
void set_createBook(const std::shared_ptr<BookCreatePayload> & v, const QJsonObject & args )
{
m_createBook[args] = v;
emit createBookChanged();
};



public:
 
[[nodiscard]] static std::shared_ptr<Mutation> instance(){
    static std::weak_ptr<Mutation> observer_inst;
    if (observer_inst.expired()){
        auto ret = std::make_shared<Mutation>();
        observer_inst = ret;
        return ret;
    }
    return observer_inst.lock();
}


Mutation()= default;

public:
inline const QString & __typename() const final{
static const QString ret = "Mutation";
return ret;
};
};
class Query :  public qtgql::bases::ObjectTypeABC {
Q_OBJECT
public:
std::unordered_map<QJsonObject, std::shared_ptr<Book>, qtgql::bases::tools::QJsonValueHasher>
 m_bookById = {};
std::vector<std::shared_ptr<Book>>
 m_allBooks = {};

signals:
void bookByIdChanged();
void allBooksChanged();


public:

[[nodiscard]] const std::shared_ptr<Book> &get_bookById(const QJsonObject & args )const{
return m_bookById.at(args);
}
void set_bookById(const std::shared_ptr<Book> & v, const QJsonObject & args )
{
m_bookById[args] = v;
emit bookByIdChanged();
};

[[nodiscard]] const std::vector<std::shared_ptr<Book>> &get_allBooks()const{
return m_allBooks;
}
void set_allBooks(const std::vector<std::shared_ptr<Book>> & v)
{
m_allBooks = v;
emit allBooksChanged();
};



public:
 
[[nodiscard]] static std::shared_ptr<Query> instance(){
    static std::weak_ptr<Query> observer_inst;
    if (observer_inst.expired()){
        auto ret = std::make_shared<Query>();
        observer_inst = ret;
        return ret;
    }
    return observer_inst.lock();
}


Query()= default;

public:
inline const QString & __typename() const final{
static const QString ret = "Query";
return ret;
};
};


}
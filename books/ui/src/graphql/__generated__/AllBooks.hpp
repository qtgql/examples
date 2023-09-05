#pragma once
#include "./schema.hpp"
#include <qtgql/bases/bases.hpp>
#include <QObject>
#include <QtQml/qqmlregistration.h>

namespace Books::allbooks{
class AllBooks;

namespace deserializers{
std::shared_ptr<Book> des_Book__allBooks(const QJsonObject& data, const AllBooks * operation);
};

namespace updaters{
void update_Book__allBooks(const std::shared_ptr<Book> & inst, const QJsonObject &data, const AllBooks * operation);
void update_Query__(const std::shared_ptr<Query> & inst, const QJsonObject &data, const AllBooks * operation);
};

// ------------ Forward declarations ------------
class Book__allBooks;


// ------------ Narrowed Interfaces ------------

// ------------ Narrowed Object types ------------

class Book__allBooks: public qtgql::bases::ObjectTypeABC{

AllBooks* m_operation;

Q_OBJECT
QML_ELEMENT
QML_UNCREATABLE("QtGql does not supports instantiation via qml")
Q_PROPERTY(QString  __typeName READ __typename CONSTANT)

Q_PROPERTY(const qtgql::bases::scalars::Id & id READ get_id NOTIFY idChanged);
Q_PROPERTY(const QString & title READ get_title NOTIFY titleChanged);
Q_PROPERTY(const QString & author READ get_author NOTIFY authorChanged);
Q_PROPERTY(const QString & content READ get_content NOTIFY contentChanged);

signals:
void idChanged();
void titleChanged();
void authorChanged();
void contentChanged();

protected:
std::shared_ptr<Books::Book> m_inst;


public:
// args builders


Book__allBooks(AllBooks * operation, const std::shared_ptr<Book> &inst);
void qtgql_replace_concrete(const std::shared_ptr<Book> & new_inst);

protected:
    void _qtgql_connect_signals();
public:
[[nodiscard]] const qtgql::bases::scalars::Id &  get_id() const;
[[nodiscard]] const QString &  get_title() const;
[[nodiscard]] const QString &  get_author() const;
[[nodiscard]] const QString &  get_content() const;
public:
[[nodiscard]] const QString & __typename() const final{
    return m_inst->__typename();
}
};

class Query__: public qtgql::bases::ObjectTypeABC{

AllBooks* m_operation;

Q_OBJECT
QML_ELEMENT
QML_UNCREATABLE("QtGql does not supports instantiation via qml")
Q_PROPERTY(QString  __typeName READ __typename CONSTANT)

Q_PROPERTY(const qtgql::bases::ListModelABC<Book__allBooks *> * allBooks READ get_allBooks NOTIFY allBooksChanged);

signals:
void allBooksChanged();

protected:
std::shared_ptr<Books::Query> m_inst;
qtgql::bases::ListModelABC<Book__allBooks *> * m_allBooks;


public:
// args builders


Query__(AllBooks * operation, const std::shared_ptr<Query> &inst);

protected:
    void _qtgql_connect_signals();
public:
[[nodiscard]] const qtgql::bases::ListModelABC<Book__allBooks *> *  get_allBooks() const;
public:
[[nodiscard]] const QString & __typename() const final{
    return m_inst->__typename();
}
};


struct AllBooksVariables{
QJsonObject to_json() const{
    QJsonObject __ret;
    return __ret;
    }

};

class AllBooks: public qtgql::bases::OperationHandlerABC{
    Q_OBJECT
    Q_PROPERTY(const Query__ * data READ data NOTIFY dataChanged);
    QML_ELEMENT
    QML_UNCREATABLE("Must be instantiated as shared pointer.")

std::optional<Query__ *> m_data = std::nullopt;



inline const std::string &ENV_NAME() final{
    static const std::string ret = "Books";
    return ret;
    }
signals:
    void dataChanged();

public:
AllBooksVariables vars_inst;

AllBooks(): qtgql::bases::OperationHandlerABC(qtgql::bases::GraphQLMessage("query AllBooks {""  allBooks {""    id""    title""    author""    content""  }""}")){};


QTGQL_STATIC_MAKE_SHARED(AllBooks)




void on_next(const QJsonObject &data_) override{
    auto root_instance = Query::instance();
    if (!m_data){
        updaters::update_Query__(root_instance, data_, this);
        m_data = new Query__(this, root_instance);
        emit dataChanged();
    }
    else{
        updaters::update_Query__(root_instance, data_, this);
    }
}

inline const Query__ * data() const{
    if (m_data){
        return m_data.value();
    }
    return nullptr;
}



};

class UseAllBooks: public QObject{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(const Query__ * data READ data NOTIFY dataChanged);
    Q_PROPERTY(bool completed READ completed NOTIFY completedChanged)
    Q_PROPERTY(bool operationOnFlight READ operation_on_flight NOTIFY operationOnFlightChanged)

public:
std::shared_ptr<AllBooks> m_operation;

UseAllBooks(QObject *parent = nullptr): QObject(parent){
    m_operation = AllBooks::shared();
    auto op_ptr = m_operation.get();
    connect(op_ptr, &AllBooks::dataChanged, this, [&]{emit dataChanged();});
    connect(op_ptr, &AllBooks::completedChanged, this, [&]{emit completedChanged();});
    connect(op_ptr, &AllBooks::operationOnFlightChanged, this, [&]{emit operationOnFlightChanged();});
};

inline const Query__ * data() const{
    return m_operation->data();
}
inline bool completed() const{
    return m_operation->completed();
}
inline bool operation_on_flight() const{
    return m_operation->operation_on_flight();
}

public slots:
void fetch(){
    m_operation->fetch();
};
void refetch(){
    m_operation->refetch();
};

signals:
void dataChanged();
void completedChanged();
void operationOnFlightChanged();
};
};
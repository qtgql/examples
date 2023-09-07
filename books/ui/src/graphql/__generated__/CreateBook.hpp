#pragma once
#include "./schema.hpp"
#include <qtgql/bases/bases.hpp>
#include <QObject>
#include <QtQml/qqmlregistration.h>

namespace Books::createbook{
class CreateBook;

namespace deserializers{
std::shared_ptr<Book> des_Book__createBookresult(const QJsonObject& data, const CreateBook * operation);
std::shared_ptr<BookCreatePayload> des_BookCreatePayload__createBook(const QJsonObject& data, const CreateBook * operation);
};

namespace updaters{
void update_Book__createBookresult(const std::shared_ptr<Book> & inst, const QJsonObject &data, const CreateBook * operation);
void update_BookCreatePayload__createBook(const std::shared_ptr<BookCreatePayload> & inst, const QJsonObject &data, const CreateBook * operation);
void update_Mutation__(const std::shared_ptr<Mutation> & inst, const QJsonObject &data, const CreateBook * operation);
};

// ------------ Forward declarations ------------
class Book__createBookresult;
class BookCreatePayload__createBook;


// ------------ Narrowed Interfaces ------------

// ------------ Narrowed Object types ------------

class Book__createBookresult: public qtgql::bases::ObjectTypeABC{

CreateBook* m_operation;

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


Book__createBookresult(CreateBook * operation, const std::shared_ptr<Book> &inst);
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

class BookCreatePayload__createBook: public qtgql::bases::ObjectTypeABC{

CreateBook* m_operation;

Q_OBJECT
QML_ELEMENT
QML_UNCREATABLE("QtGql does not supports instantiation via qml")
Q_PROPERTY(QString  __typeName READ __typename CONSTANT)

Q_PROPERTY(const Book__createBookresult * result READ get_result NOTIFY resultChanged);

signals:
void resultChanged();

protected:
std::shared_ptr<Books::BookCreatePayload> m_inst;
Book__createBookresult * m_result = {};


public:
// args builders


BookCreatePayload__createBook(CreateBook * operation, const std::shared_ptr<BookCreatePayload> &inst);
void qtgql_replace_concrete(const std::shared_ptr<BookCreatePayload> & new_inst);

protected:
    void _qtgql_connect_signals();
public:
[[nodiscard]] const Book__createBookresult *  get_result() const;
public:
[[nodiscard]] const QString & __typename() const final{
    return m_inst->__typename();
}
};

class Mutation__: public qtgql::bases::ObjectTypeABC{

CreateBook* m_operation;

Q_OBJECT
QML_ELEMENT
QML_UNCREATABLE("QtGql does not supports instantiation via qml")
Q_PROPERTY(QString  __typeName READ __typename CONSTANT)

Q_PROPERTY(const BookCreatePayload__createBook * createBook READ get_createBook NOTIFY createBookChanged);

signals:
void createBookChanged();

protected:
std::shared_ptr<Books::Mutation> m_inst;
BookCreatePayload__createBook * m_createBook = {};


public:
// args builders
static QJsonObject  build_args_for_createBook(const CreateBook* operation);


Mutation__(CreateBook * operation, const std::shared_ptr<Mutation> &inst);

protected:
    void _qtgql_connect_signals();
public:
[[nodiscard]] const BookCreatePayload__createBook *  get_createBook() const;
public:
[[nodiscard]] const QString & __typename() const final{
    return m_inst->__typename();
}
};


struct CreateBookVariables{
std::shared_ptr<CreateBookInput> input;
QJsonObject to_json() const{
    QJsonObject __ret;
    
__ret.insert("input",  input
->to_json());


    return __ret;
    }

};

class CreateBook: public qtgql::bases::OperationHandlerABC{
    Q_OBJECT
    Q_PROPERTY(const Mutation__ * data READ data NOTIFY dataChanged);
    QML_ELEMENT
    QML_UNCREATABLE("Must be instantiated as shared pointer.")

std::optional<Mutation__ *> m_data = std::nullopt;



inline const std::string &ENV_NAME() final{
    static const std::string ret = "Books";
    return ret;
    }
signals:
    void dataChanged();

public:
CreateBookVariables vars_inst;

CreateBook(): qtgql::bases::OperationHandlerABC(qtgql::bases::GraphQLMessage("mutation CreateBook($input: CreateBookInput!) {""  createBook(input: $input) {""    result {""      id""      title""      author""      content""    }""  }""}")){};


QTGQL_STATIC_MAKE_SHARED(CreateBook)




void on_next(const QJsonObject &data_) override{
    auto root_instance = Mutation::instance();
    if (!m_data){
        updaters::update_Mutation__(root_instance, data_, this);
        m_data = new Mutation__(this, root_instance);
        emit dataChanged();
    }
    else{
        updaters::update_Mutation__(root_instance, data_, this);
    }
}

inline const Mutation__ * data() const{
    if (m_data){
        return m_data.value();
    }
    return nullptr;
}


void set_variables(CreateBookVariables vars){
    
    vars_inst.input.swap(vars.input);
    qtgql::bases::OperationHandlerABC::set_vars(vars_inst.to_json());
}


};

class UseCreateBook: public QObject{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(const Mutation__ * data READ data NOTIFY dataChanged);
    Q_PROPERTY(bool completed READ completed NOTIFY completedChanged)
    Q_PROPERTY(bool operationOnFlight READ operation_on_flight NOTIFY operationOnFlightChanged)

public:
std::shared_ptr<CreateBook> m_operation;

UseCreateBook(QObject *parent = nullptr): QObject(parent){
    m_operation = CreateBook::shared();
    auto op_ptr = m_operation.get();
    connect(op_ptr, &CreateBook::dataChanged, this, [&]{emit dataChanged();});
    connect(op_ptr, &CreateBook::completedChanged, this, [&]{emit completedChanged();});
    connect(op_ptr, &CreateBook::operationOnFlightChanged, this, [&]{emit operationOnFlightChanged();});
};

inline const Mutation__ * data() const{
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
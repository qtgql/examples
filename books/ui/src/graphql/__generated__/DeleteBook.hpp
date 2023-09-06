#pragma once
#include "./schema.hpp"
#include <qtgql/bases/bases.hpp>
#include <QObject>
#include <QtQml/qqmlregistration.h>

namespace Books::deletebook{
class DeleteBook;

namespace deserializers{
};

namespace updaters{
void update_Mutation__(const std::shared_ptr<Mutation> & inst, const QJsonObject &data, const DeleteBook * operation);
};

// ------------ Forward declarations ------------


// ------------ Narrowed Interfaces ------------

// ------------ Narrowed Object types ------------

class Mutation__: public qtgql::bases::ObjectTypeABC{

DeleteBook* m_operation;

Q_OBJECT
QML_ELEMENT
QML_UNCREATABLE("QtGql does not supports instantiation via qml")
Q_PROPERTY(QString  __typeName READ __typename CONSTANT)

Q_PROPERTY(const bool & deleteBook READ get_deleteBook NOTIFY deleteBookChanged);

signals:
void deleteBookChanged();

protected:
std::shared_ptr<Books::Mutation> m_inst;


public:
// args builders
static QJsonObject  build_args_for_deleteBook(const DeleteBook* operation);


Mutation__(DeleteBook * operation, const std::shared_ptr<Mutation> &inst);

protected:
    void _qtgql_connect_signals();
public:
[[nodiscard]] const bool &  get_deleteBook() const;
public:
[[nodiscard]] const QString & __typename() const final{
    return m_inst->__typename();
}
};


struct DeleteBookVariables{
qtgql::bases::scalars::Id bookID;
QJsonObject to_json() const{
    QJsonObject __ret;
    
__ret.insert("bookID",  bookID
);


    return __ret;
    }

};

class DeleteBook: public qtgql::bases::OperationHandlerABC{
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
DeleteBookVariables vars_inst;

DeleteBook(): qtgql::bases::OperationHandlerABC(qtgql::bases::GraphQLMessage("mutation DeleteBook($bookID: ID!) {""  deleteBook(bookId: $bookID)""}")){};


QTGQL_STATIC_MAKE_SHARED(DeleteBook)




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


void set_variables(DeleteBookVariables vars){
    
    vars_inst.bookID = vars.bookID;
    qtgql::bases::OperationHandlerABC::set_vars(vars_inst.to_json());
}


};

class UseDeleteBook: public QObject{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(const Mutation__ * data READ data NOTIFY dataChanged);
    Q_PROPERTY(bool completed READ completed NOTIFY completedChanged)
    Q_PROPERTY(bool operationOnFlight READ operation_on_flight NOTIFY operationOnFlightChanged)

public:
std::shared_ptr<DeleteBook> m_operation;

UseDeleteBook(QObject *parent = nullptr): QObject(parent){
    m_operation = DeleteBook::shared();
    auto op_ptr = m_operation.get();
    connect(op_ptr, &DeleteBook::dataChanged, this, [&]{emit dataChanged();});
    connect(op_ptr, &DeleteBook::completedChanged, this, [&]{emit completedChanged();});
    connect(op_ptr, &DeleteBook::operationOnFlightChanged, this, [&]{emit operationOnFlightChanged();});
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
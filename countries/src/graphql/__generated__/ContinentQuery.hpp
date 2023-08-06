#pragma once
#include "./schema.hpp"
#include <qtgql/bases/bases.hpp>
#include <QObject>
#include <QtQml/qqmlregistration.h>

namespace Countries::continentquery{
class ContinentQuery;

namespace deserializers{
std::shared_ptr<Country> des_Country__continentcountries(const QJsonObject& data, const ContinentQuery * operation);
std::shared_ptr<Continent> des_Continent__continent(const QJsonObject& data, const ContinentQuery * operation);
};

namespace updaters{
void update_Country__continentcountries(const std::shared_ptr<Country> & inst, const QJsonObject &data, const ContinentQuery * operation);
void update_Continent__continent(const std::shared_ptr<Continent> & inst, const QJsonObject &data, const ContinentQuery * operation);
void update_Query__(Query * inst, const QJsonObject &data, const ContinentQuery * operation);
};

// ------------ Narrowed Interfaces ------------

// ------------ Narrowed Object types ------------

class Country__continentcountries: public qtgql::bases::ObjectTypeABC{

ContinentQuery* m_operation;

Q_OBJECT
QML_ELEMENT
QML_UNCREATABLE("QtGql does not supports instantiation via qml")
Q_PROPERTY(QString  __typeName READ __typename CONSTANT)

Q_PROPERTY(const QString capital READ get_capital NOTIFY capitalChanged);
Q_PROPERTY(const QString emoji READ get_emoji NOTIFY emojiChanged);

signals:
void capitalChanged();
void emojiChanged();

protected:
std::shared_ptr<Countries::Country> m_inst;


public:
Country__continentcountries(ContinentQuery * operation, const std::shared_ptr<Country> &inst);

void qtgql_replace_concrete(const std::shared_ptr<Country> & new_inst);

protected:
    void _qtgql_connect_signals();
public:
[[nodiscard]] const QString  get_capital() const;
[[nodiscard]] const QString  get_emoji() const;
public:
[[nodiscard]] const QString & __typename() const final{
    return m_inst->__typename();
}
};

class Continent__continent: public qtgql::bases::ObjectTypeABC{

ContinentQuery* m_operation;

Q_OBJECT
QML_ELEMENT
QML_UNCREATABLE("QtGql does not supports instantiation via qml")
Q_PROPERTY(QString  __typeName READ __typename CONSTANT)

Q_PROPERTY(const qtgql::bases::ListModelABC<Country__continentcountries *> * countries READ get_countries NOTIFY countriesChanged);

signals:
void countriesChanged();

protected:
std::shared_ptr<Countries::Continent> m_inst;
qtgql::bases::ListModelABC<Country__continentcountries *> * m_countries;


public:
Continent__continent(ContinentQuery * operation, const std::shared_ptr<Continent> &inst);

void qtgql_replace_concrete(const std::shared_ptr<Continent> & new_inst);

protected:
    void _qtgql_connect_signals();
public:
[[nodiscard]] const qtgql::bases::ListModelABC<Country__continentcountries *> *  get_countries() const;
public:
[[nodiscard]] const QString & __typename() const final{
    return m_inst->__typename();
}
};

class Query__: public qtgql::bases::ObjectTypeABC{

ContinentQuery* m_operation;

Q_OBJECT
QML_ELEMENT
QML_UNCREATABLE("QtGql does not supports instantiation via qml")
Q_PROPERTY(QString  __typeName READ __typename CONSTANT)

Q_PROPERTY(const Continent__continent * continent READ get_continent NOTIFY continentChanged);

signals:
void continentChanged();

protected:
Countries::Query * m_inst;
Continent__continent * m_continent = {};


public:
Query__(ContinentQuery * operation);


protected:
    void _qtgql_connect_signals();
public:
[[nodiscard]] const Continent__continent *  get_continent() const;
public:
[[nodiscard]] const QString & __typename() const final{
    return m_inst->__typename();
}
};


struct ContinentQueryVariables{
std::optional<qtgql::bases::scalars::Id> code = {};
QJsonObject to_json() const{
    QJsonObject __ret;
    if (code.has_value()){
__ret.insert("code",  code.value());
}

    return __ret;
    }
};

class ContinentQuery: public qtgql::bases::OperationHandlerABC{
    Q_OBJECT
    Q_PROPERTY(const Query__ * data READ data NOTIFY dataChanged);
    QML_ELEMENT
    QML_UNCREATABLE("Must be instantiated as shared pointer.")

std::optional<Query__ *> m_data = {};



inline const QString &ENV_NAME() final{
    static const auto ret = QString("Countries");
    return ret;
    }
signals:
    void dataChanged();

public:
ContinentQueryVariables vars_inst;

ContinentQuery(): qtgql::bases::OperationHandlerABC(qtgql::bases::GraphQLMessage("query ContinentQuery($code: ID!) {""  continent(code: $code) {""    countries {""      capital""      emoji""    }""  }""}")){};


QTGQL_STATIC_MAKE_SHARED(ContinentQuery)




void on_next(const QJsonObject &data_) override{
    if (!m_data){
        updaters::update_Query__(Query::instance(), data_, this);
        m_data = new Query__(this);
        emit dataChanged();
    }
    else{
        updaters::update_Query__(Query::instance(), data_, this);
    }
}

inline const Query__ * data() const{
    if (m_data){
        return m_data.value();
    }
    return nullptr;
}


void set_variables(const ContinentQueryVariables & vars){
vars_inst = vars;
qtgql::bases::OperationHandlerABC::set_vars(vars_inst.to_json());
}


};

class UseContinentQuery: public QObject{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(const Query__ * data READ data NOTIFY dataChanged);
    Q_PROPERTY(bool completed READ completed NOTIFY completedChanged)
    Q_PROPERTY(bool operationOnFlight READ operation_on_flight NOTIFY operationOnFlightChanged)

public:
std::shared_ptr<ContinentQuery> m_operation;

UseContinentQuery(QObject *parent = nullptr): QObject(parent){
    m_operation = ContinentQuery::shared();
    auto op_ptr = m_operation.get();
    connect(op_ptr, &ContinentQuery::dataChanged, this, [&]{emit dataChanged();});
    connect(op_ptr, &ContinentQuery::completedChanged, this, [&]{emit completedChanged();});
    connect(op_ptr, &ContinentQuery::operationOnFlightChanged, this, [&]{emit operationOnFlightChanged();});
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
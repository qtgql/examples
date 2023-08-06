#pragma once
#include <QObject>
#include <QJsonObject>
#include <QJsonArray>
#include <memory>

#include <qtgql/bases/bases.hpp>
#include <qtgql/customscalars/customscalars.hpp>


namespace Countries{


// ---------- INPUT OBJECTS ----------
/*
 * None
 */
struct StringQueryOperatorInput{

public:

bool operator<(const StringQueryOperatorInput& other) const {
    if(eq < other.eq){
        return true;
    }
    if(in < other.in){
        return true;
    }
    if(ne < other.ne){
        return true;
    }
    if(nin < other.nin){
        return true;
    }
    if(regex < other.regex){
        return true;
    }
    return false;
}
std::optional<QString> eq = {};
std::optional<std::list<QString>> in = {};
std::optional<QString> ne = {};
std::optional<std::list<QString>> nin = {};
std::optional<QString> regex = {};

[[nodiscard]] QJsonObject to_json() const{
    auto __ret = QJsonObject();
    if (eq.has_value()){
__ret.insert("eq",  eq.value());
}

    if (in.has_value()){
QJsonArray in_json;
for (const auto& node: in.value()){
in_json.append(node);
}
__ret.insert("in",  in_json);
}

    if (ne.has_value()){
__ret.insert("ne",  ne.value());
}

    if (nin.has_value()){
QJsonArray nin_json;
for (const auto& node: nin.value()){
nin_json.append(node);
}
__ret.insert("nin",  nin_json);
}

    if (regex.has_value()){
__ret.insert("regex",  regex.value());
}

    return __ret;
}
};
/*
 * None
 */
struct ContinentFilterInput{

public:

bool operator<(const ContinentFilterInput& other) const {
    if(code < other.code){
        return true;
    }
    return false;
}
std::optional<StringQueryOperatorInput> code = {};

[[nodiscard]] QJsonObject to_json() const{
    auto __ret = QJsonObject();
    if (code.has_value()){
__ret.insert("code",  code.value().to_json());
}

    return __ret;
}
};


// ---------- Interfaces ----------


// ---------- Object Types ----------
class Continent;
class Country;
class Language;
class Query;
class State;
class Subdivision;


class Continent :  public qtgql::bases::ObjectTypeABC {
Q_OBJECT
public:
qtgql::bases::scalars::Id
 m_code = qtgql::bases::DEFAULTS::ID;
std::vector<std::shared_ptr<Country>>
 m_countries = {};
QString
 m_name = qtgql::bases::DEFAULTS::STRING;

signals:
void codeChanged();
void countriesChanged();
void nameChanged();


public:

[[nodiscard]] const qtgql::bases::scalars::Id &get_code()const{
return m_code;
}
void set_code(const qtgql::bases::scalars::Id & v)
{
m_code = v;
emit codeChanged();
};

[[nodiscard]] const std::vector<std::shared_ptr<Country>> &get_countries()const{
return m_countries;
}
void set_countries(const std::vector<std::shared_ptr<Country>> & v)
{
m_countries = v;
emit countriesChanged();
};

[[nodiscard]] const QString &get_name()const{
return m_name;
}
void set_name(const QString & v)
{
m_name = v;
emit nameChanged();
};



public:

QTGQL_STATIC_MAKE_SHARED(Continent)


Continent()= default;

public:
inline const QString & __typename() const final{
static const QString ret = "Continent";
return ret;
};
};
class Country :  public qtgql::bases::ObjectTypeABC {
Q_OBJECT
public:
QString
 m_awsRegion = qtgql::bases::DEFAULTS::STRING;
QString
 m_capital = qtgql::bases::DEFAULTS::STRING;
qtgql::bases::scalars::Id
 m_code = qtgql::bases::DEFAULTS::ID;
std::shared_ptr<Continent>
 m_continent = {};
std::shared_ptr<qtgql::bases::ListModelABC<QString>>
 m_currencies = {};
QString
 m_currency = qtgql::bases::DEFAULTS::STRING;
QString
 m_emoji = qtgql::bases::DEFAULTS::STRING;
QString
 m_emojiU = qtgql::bases::DEFAULTS::STRING;
std::vector<std::shared_ptr<Language>>
 m_languages = {};
std::map<std::tuple<QString>, QString>
 m_name = {};
QString
 m_native = qtgql::bases::DEFAULTS::STRING;
QString
 m_phone = qtgql::bases::DEFAULTS::STRING;
std::shared_ptr<qtgql::bases::ListModelABC<QString>>
 m_phones = {};
std::vector<std::shared_ptr<State>>
 m_states = {};
std::vector<std::shared_ptr<Subdivision>>
 m_subdivisions = {};

signals:
void awsRegionChanged();
void capitalChanged();
void codeChanged();
void continentChanged();
void currenciesChanged();
void currencyChanged();
void emojiChanged();
void emojiUChanged();
void languagesChanged();
void nameChanged();
void nativeChanged();
void phoneChanged();
void phonesChanged();
void statesChanged();
void subdivisionsChanged();


public:

[[nodiscard]] const QString &get_awsRegion()const{
return m_awsRegion;
}
void set_awsRegion(const QString & v)
{
m_awsRegion = v;
emit awsRegionChanged();
};

[[nodiscard]] const QString &get_capital()const{
return m_capital;
}
void set_capital(const QString & v)
{
m_capital = v;
emit capitalChanged();
};

[[nodiscard]] const qtgql::bases::scalars::Id &get_code()const{
return m_code;
}
void set_code(const qtgql::bases::scalars::Id & v)
{
m_code = v;
emit codeChanged();
};

[[nodiscard]] const std::shared_ptr<Continent> &get_continent()const{
return m_continent;
}
void set_continent(const std::shared_ptr<Continent> & v)
{
m_continent = v;
emit continentChanged();
};

[[nodiscard]] const std::shared_ptr<qtgql::bases::ListModelABC<QString>> &get_currencies()const{
return m_currencies;
}
void set_currencies(const std::shared_ptr<qtgql::bases::ListModelABC<QString>> & v)
{
m_currencies = v;
emit currenciesChanged();
};

[[nodiscard]] const QString &get_currency()const{
return m_currency;
}
void set_currency(const QString & v)
{
m_currency = v;
emit currencyChanged();
};

[[nodiscard]] const QString &get_emoji()const{
return m_emoji;
}
void set_emoji(const QString & v)
{
m_emoji = v;
emit emojiChanged();
};

[[nodiscard]] const QString &get_emojiU()const{
return m_emojiU;
}
void set_emojiU(const QString & v)
{
m_emojiU = v;
emit emojiUChanged();
};

[[nodiscard]] const std::vector<std::shared_ptr<Language>> &get_languages()const{
return m_languages;
}
void set_languages(const std::vector<std::shared_ptr<Language>> & v)
{
m_languages = v;
emit languagesChanged();
};

[[nodiscard]] const QString &get_name(std::tuple<QString> args )const{
return m_name.at(args);
}
void set_name(const QString & v, std::tuple<QString> args )
{
m_name[args] = v;
emit nameChanged();
};

[[nodiscard]] const QString &get_native()const{
return m_native;
}
void set_native(const QString & v)
{
m_native = v;
emit nativeChanged();
};

[[nodiscard]] const QString &get_phone()const{
return m_phone;
}
void set_phone(const QString & v)
{
m_phone = v;
emit phoneChanged();
};

[[nodiscard]] const std::shared_ptr<qtgql::bases::ListModelABC<QString>> &get_phones()const{
return m_phones;
}
void set_phones(const std::shared_ptr<qtgql::bases::ListModelABC<QString>> & v)
{
m_phones = v;
emit phonesChanged();
};

[[nodiscard]] const std::vector<std::shared_ptr<State>> &get_states()const{
return m_states;
}
void set_states(const std::vector<std::shared_ptr<State>> & v)
{
m_states = v;
emit statesChanged();
};

[[nodiscard]] const std::vector<std::shared_ptr<Subdivision>> &get_subdivisions()const{
return m_subdivisions;
}
void set_subdivisions(const std::vector<std::shared_ptr<Subdivision>> & v)
{
m_subdivisions = v;
emit subdivisionsChanged();
};



public:

QTGQL_STATIC_MAKE_SHARED(Country)


Country()= default;

public:
inline const QString & __typename() const final{
static const QString ret = "Country";
return ret;
};
};
class Language :  public qtgql::bases::ObjectTypeABC {
Q_OBJECT
public:
qtgql::bases::scalars::Id
 m_code = qtgql::bases::DEFAULTS::ID;
QString
 m_name = qtgql::bases::DEFAULTS::STRING;
QString
 m_native = qtgql::bases::DEFAULTS::STRING;
bool
 m_rtl = qtgql::bases::DEFAULTS::BOOL;

signals:
void codeChanged();
void nameChanged();
void nativeChanged();
void rtlChanged();


public:

[[nodiscard]] const qtgql::bases::scalars::Id &get_code()const{
return m_code;
}
void set_code(const qtgql::bases::scalars::Id & v)
{
m_code = v;
emit codeChanged();
};

[[nodiscard]] const QString &get_name()const{
return m_name;
}
void set_name(const QString & v)
{
m_name = v;
emit nameChanged();
};

[[nodiscard]] const QString &get_native()const{
return m_native;
}
void set_native(const QString & v)
{
m_native = v;
emit nativeChanged();
};

[[nodiscard]] const bool &get_rtl()const{
return m_rtl;
}
void set_rtl(const bool & v)
{
m_rtl = v;
emit rtlChanged();
};



public:

QTGQL_STATIC_MAKE_SHARED(Language)


Language()= default;

public:
inline const QString & __typename() const final{
static const QString ret = "Language";
return ret;
};
};
class Query :  public qtgql::bases::ObjectTypeABC {
Q_OBJECT
public:
std::map<std::tuple<qtgql::bases::scalars::Id>, std::shared_ptr<Continent>>
 m_continent = {};
std::map<std::tuple<ContinentFilterInput>, std::vector<std::shared_ptr<Continent>>>
 m_continents = {};

signals:
void continentChanged();
void continentsChanged();


public:

[[nodiscard]] const std::shared_ptr<Continent> &get_continent(std::tuple<qtgql::bases::scalars::Id> args )const{
return m_continent.at(args);
}
void set_continent(const std::shared_ptr<Continent> & v, std::tuple<qtgql::bases::scalars::Id> args )
{
m_continent[args] = v;
emit continentChanged();
};

[[nodiscard]] const std::vector<std::shared_ptr<Continent>> &get_continents(std::tuple<ContinentFilterInput> args )const{
return m_continents.at(args);
}
void set_continents(const std::vector<std::shared_ptr<Continent>> & v, std::tuple<ContinentFilterInput> args )
{
m_continents[args] = v;
emit continentsChanged();
};



public:
 
[[nodiscard]] static Query* instance(){
static Query inst;
return &inst;
}


Query()= default;

public:
inline const QString & __typename() const final{
static const QString ret = "Query";
return ret;
};
};
class State :  public qtgql::bases::ObjectTypeABC {
Q_OBJECT
public:
QString
 m_code = qtgql::bases::DEFAULTS::STRING;
std::shared_ptr<Country>
 m_country = {};
QString
 m_name = qtgql::bases::DEFAULTS::STRING;

signals:
void codeChanged();
void countryChanged();
void nameChanged();


public:

[[nodiscard]] const QString &get_code()const{
return m_code;
}
void set_code(const QString & v)
{
m_code = v;
emit codeChanged();
};

[[nodiscard]] const std::shared_ptr<Country> &get_country()const{
return m_country;
}
void set_country(const std::shared_ptr<Country> & v)
{
m_country = v;
emit countryChanged();
};

[[nodiscard]] const QString &get_name()const{
return m_name;
}
void set_name(const QString & v)
{
m_name = v;
emit nameChanged();
};



public:

QTGQL_STATIC_MAKE_SHARED(State)


State()= default;

public:
inline const QString & __typename() const final{
static const QString ret = "State";
return ret;
};
};
class Subdivision :  public qtgql::bases::ObjectTypeABC {
Q_OBJECT
public:
qtgql::bases::scalars::Id
 m_code = qtgql::bases::DEFAULTS::ID;
QString
 m_emoji = qtgql::bases::DEFAULTS::STRING;
QString
 m_name = qtgql::bases::DEFAULTS::STRING;

signals:
void codeChanged();
void emojiChanged();
void nameChanged();


public:

[[nodiscard]] const qtgql::bases::scalars::Id &get_code()const{
return m_code;
}
void set_code(const qtgql::bases::scalars::Id & v)
{
m_code = v;
emit codeChanged();
};

[[nodiscard]] const QString &get_emoji()const{
return m_emoji;
}
void set_emoji(const QString & v)
{
m_emoji = v;
emit emojiChanged();
};

[[nodiscard]] const QString &get_name()const{
return m_name;
}
void set_name(const QString & v)
{
m_name = v;
emit nameChanged();
};



public:

QTGQL_STATIC_MAKE_SHARED(Subdivision)


Subdivision()= default;

public:
inline const QString & __typename() const final{
static const QString ret = "Subdivision";
return ret;
};
};


}
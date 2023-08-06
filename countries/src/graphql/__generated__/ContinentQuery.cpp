#include "./ContinentQuery.hpp"

namespace Countries::continentquery{

// Interfaces



// Constructor
Country__continentcountries::Country__continentcountries(ContinentQuery * operation, const std::shared_ptr<Country> &inst)
: m_inst{inst}, ObjectTypeABC
::ObjectTypeABC
(operation)
{
    m_operation = operation;
    
    _qtgql_connect_signals();
}

void Country__continentcountries::_qtgql_connect_signals(){

auto m_inst_ptr = m_inst.get();
Q_ASSERT_X(m_inst_ptr, __FILE__, "Tried to instantiate a proxy object with an empty pointer!");
connect(m_inst_ptr, &Countries::Country::capitalChanged, this,
[&](){
auto operation = m_operation;
emit capitalChanged();

});
connect(m_inst_ptr, &Countries::Country::emojiChanged, this,
[&](){
auto operation = m_operation;
emit emojiChanged();

});
};

// Deserialzier

std::shared_ptr<Country> deserializers::des_Country__continentcountries(const QJsonObject& data, const ContinentQuery * operation){
if (data.isEmpty()){
    return {};
}
auto inst = Country::shared();

if (!data.value("capital").isNull()){
inst->set_capital(data.value("capital").toString() );
    
    
};

if (!data.value("emoji").isNull()){
inst->set_emoji(data.value("emoji").toString() );
    
    
};


return inst;
};


// Updater
void updaters::update_Country__continentcountries(const std::shared_ptr<Country> & inst, const QJsonObject &data, const ContinentQuery * operation)
{
if (!data.value("capital").isNull()){
auto new_capital = data.value("capital").toString();
if (inst->m_capital != new_capital){
inst->set_capital(new_capital );
}


}

else {
inst->set_capital({} );
}

if (!data.value("emoji").isNull()){
auto new_emoji = data.value("emoji").toString();
if (inst->m_emoji != new_emoji){
inst->set_emoji(new_emoji );
}


}


};



// Country__continentcountries Getters
[[nodiscard]] const QString  Country__continentcountries::get_capital() const {

return m_inst->get_capital();};
[[nodiscard]] const QString  Country__continentcountries::get_emoji() const {

return m_inst->get_emoji();};



void Country__continentcountries::qtgql_replace_concrete(const std::shared_ptr<Country> & new_inst){
    if (new_inst == m_inst){
    return;
    }
    m_inst->disconnect(this);
    if(m_inst->m_capital != new_inst->m_capital){
    auto operation = m_operation;
emit capitalChanged();

    };
    if(m_inst->m_emoji != new_inst->m_emoji){
    auto operation = m_operation;
emit emojiChanged();

    };
    m_inst = new_inst;
    _qtgql_connect_signals();
};
// Constructor
Continent__continent::Continent__continent(ContinentQuery * operation, const std::shared_ptr<Continent> &inst)
: m_inst{inst}, ObjectTypeABC
::ObjectTypeABC
(operation)
{
    m_operation = operation;
    
    auto init_vec_countries =  std::vector<Country__continentcountries*>();
    for (const auto & node: m_inst->get_countries()
){
    init_vec_countries.push_back(new Country__continentcountries(operation, node));
    }
    m_countries = new qtgql::bases::ListModelABC<Country__continentcountries *>(this, std::move(init_vec_countries));
    

    _qtgql_connect_signals();
}

void Continent__continent::_qtgql_connect_signals(){

auto m_inst_ptr = m_inst.get();
Q_ASSERT_X(m_inst_ptr, __FILE__, "Tried to instantiate a proxy object with an empty pointer!");
connect(m_inst_ptr, &Countries::Continent::countriesChanged, this,
[&](){
auto operation = m_operation;
auto new_data = m_inst->get_countries();
    auto new_len = new_data.size();
    auto prev_len = m_countries->rowCount();
    if (new_len < prev_len){
        m_countries->removeRows(prev_len - 1, prev_len - new_len);
    }
    for (int i = 0; i < new_len; i++){
        const auto& concrete = new_data.at(i);
    if (i >= prev_len){
            m_countries->append(new Country__continentcountries(operation, concrete));
        } else {
            auto proxy_to_update = m_countries->get(i);
            if(proxy_to_update){
                proxy_to_update->qtgql_replace_concrete(concrete);
            }
            else{ m_countries->replace(i, new Country__continentcountries(operation, concrete));
            }
        }

    
    }

});
};

// Deserialzier

std::shared_ptr<Continent> deserializers::des_Continent__continent(const QJsonObject& data, const ContinentQuery * operation){
if (data.isEmpty()){
    return {};
}
auto inst = Continent::shared();

if (!data.value("countries").isNull()){

        std::vector<std::shared_ptr<Country>> countries_init_vec;
        for (const auto& node: data.value("countries").toArray()){
        
            countries_init_vec.push_back(deserializers::des_Country__continentcountries(node.toObject(), operation));
        
        };
        inst->set_countries(countries_init_vec );
    

};


return inst;
};


// Updater
void updaters::update_Continent__continent(const std::shared_ptr<Continent> & inst, const QJsonObject &data, const ContinentQuery * operation)
{
if (!data.value("countries").isNull()){

    
    
if (!data.value("countries").isNull()){

        std::vector<std::shared_ptr<Country>> countries_init_vec;
        for (const auto& node: data.value("countries").toArray()){
        
            countries_init_vec.push_back(deserializers::des_Country__continentcountries(node.toObject(), operation));
        
        };
        inst->set_countries(countries_init_vec );
    

};
    

}


};



// Continent__continent Getters
[[nodiscard]] const qtgql::bases::ListModelABC<Country__continentcountries *> *  Continent__continent::get_countries() const {

return m_countries;
};



void Continent__continent::qtgql_replace_concrete(const std::shared_ptr<Continent> & new_inst){
    if (new_inst == m_inst){
    return;
    }
    m_inst->disconnect(this);
    if(m_inst->m_countries != new_inst->m_countries){
    auto operation = m_operation;
auto new_data = m_inst->get_countries();
    auto new_len = new_data.size();
    auto prev_len = m_countries->rowCount();
    if (new_len < prev_len){
        m_countries->removeRows(prev_len - 1, prev_len - new_len);
    }
    for (int i = 0; i < new_len; i++){
        const auto& concrete = new_data.at(i);
    if (i >= prev_len){
            m_countries->append(new Country__continentcountries(operation, concrete));
        } else {
            auto proxy_to_update = m_countries->get(i);
            if(proxy_to_update){
                proxy_to_update->qtgql_replace_concrete(concrete);
            }
            else{ m_countries->replace(i, new Country__continentcountries(operation, concrete));
            }
        }

    
    }

    };
    m_inst = new_inst;
    _qtgql_connect_signals();
};
// Constructor
Query__::Query__(ContinentQuery * operation): ObjectTypeABC
::ObjectTypeABC
(operation){
    m_inst = Query::instance();
    auto m_inst_ptr = m_inst;
m_operation = operation;
if (m_inst->get_continent({operation->vars_inst.code.value()})
){
m_continent = new Continent__continent(operation, m_inst->get_continent({operation->vars_inst.code.value()})
);
}

    _qtgql_connect_signals();
}

void Query__::_qtgql_connect_signals(){
auto m_inst_ptr = m_inst;
Q_ASSERT_X(m_inst_ptr, __FILE__, "Tried to instantiate a proxy object with an empty pointer!");
connect(m_inst_ptr, &Countries::Query::continentChanged, this,
[&](){
auto operation = m_operation;
auto concrete = m_inst->get_continent({operation->vars_inst.code.value()});
if (m_continent){
    m_continent->qtgql_replace_concrete(concrete);
}
else{
    m_continent = new Continent__continent(operation, concrete);
    emit continentChanged();
}

});
};

// Deserialzier


// Updater
void updaters::update_Query__(Query * inst, const QJsonObject &data, const ContinentQuery * operation)
{
std::tuple<qtgql::bases::scalars::Id> m_continent_args = {operation->vars_inst.code.value()};
if (!inst->m_continent.contains(m_continent_args))

{
if (!data.value("continent").isNull()){
inst->set_continent(deserializers::des_Continent__continent(data.value("continent").toObject(), operation) 
, {operation->vars_inst.code.value()}
);


};
}
else
if (!data.value("continent").isNull()){

    auto continent_data = data.value("continent").toObject();
    
    updaters::update_Continent__continent(inst->m_continent.at(m_continent_args), continent_data,  operation);
    

}

else {
inst->set_continent({} , m_continent_args
);
}


};



// Query__ Getters
[[nodiscard]] const Continent__continent *  Query__::get_continent() const {

return m_continent;
};




}
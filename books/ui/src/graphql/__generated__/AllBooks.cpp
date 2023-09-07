#include "./AllBooks.hpp"

namespace Books::allbooks{

// Interfaces



// Constructor
Book__allBooks::Book__allBooks(AllBooks * operation, const std::shared_ptr<Book> &inst)
: m_inst{inst}, ObjectTypeABC
::ObjectTypeABC
(operation)
{
    m_operation = operation;



    



    



    



    _qtgql_connect_signals();
}

void Book__allBooks::_qtgql_connect_signals(){
auto m_inst_ptr = m_inst.get();
Q_ASSERT_X(m_inst_ptr, __FILE__, "Tried to instantiate a proxy object with an empty pointer!");
connect(m_inst_ptr, &Books::Book::idChanged, this,
[&](){




auto operation = m_operation;
emit idChanged();

});
connect(m_inst_ptr, &Books::Book::titleChanged, this,
[&](){




auto operation = m_operation;
emit titleChanged();

});
connect(m_inst_ptr, &Books::Book::authorChanged, this,
[&](){




auto operation = m_operation;
emit authorChanged();

});
connect(m_inst_ptr, &Books::Book::contentChanged, this,
[&](){




auto operation = m_operation;
emit contentChanged();

});
};

// Deserialzier

std::shared_ptr<Book> deserializers::des_Book__allBooks(const QJsonObject& data, const AllBooks * operation){
if (data.isEmpty()){
    return {};
}

auto cached_maybe = Book::get_node(data.value("id").toString());
if(cached_maybe.has_value()){
    auto node = cached_maybe.value();
    updaters::update_Book__allBooks(node, data, operation);
    return node;
}
auto inst = Book::shared();

if (!data.value("id").isNull()){
inst->set_id(std::make_shared<qtgql::bases::scalars::Id>(data.value("id").toString()) );
    
    
};

if (!data.value("title").isNull()){
inst->set_title(std::make_shared<QString>(data.value("title").toString()) );
    
    
};

if (!data.value("author").isNull()){
inst->set_author(std::make_shared<QString>(data.value("author").toString()) );
    
    
};

if (!data.value("content").isNull()){
inst->set_content(std::make_shared<QString>(data.value("content").toString()) );
    
    
};


Book::ENV_CACHE()->add_node(inst);

return inst;
};


// Updater
void updaters::update_Book__allBooks(const std::shared_ptr<Book> & inst, const QJsonObject &data, const AllBooks * operation)
{
if (!data.value("id").isNull()){
auto new_id = std::make_shared<qtgql::bases::scalars::Id>(data.value("id").toString());
    auto old_id = inst->m_id;
    if (!old_id || *old_id != *new_id){
        inst->set_id(new_id );
    }
    
}

if (!data.value("title").isNull()){
auto new_title = std::make_shared<QString>(data.value("title").toString());
    auto old_title = inst->m_title;
    if (!old_title || *old_title != *new_title){
        inst->set_title(new_title );
    }
    
}

if (!data.value("author").isNull()){
auto new_author = std::make_shared<QString>(data.value("author").toString());
    auto old_author = inst->m_author;
    if (!old_author || *old_author != *new_author){
        inst->set_author(new_author );
    }
    
}

if (!data.value("content").isNull()){
auto new_content = std::make_shared<QString>(data.value("content").toString());
    auto old_content = inst->m_content;
    if (!old_content || *old_content != *new_content){
        inst->set_content(new_content );
    }
    
}


};



// Book__allBooks Getters
[[nodiscard]] const qtgql::bases::scalars::Id &  Book__allBooks::get_id() const {
return *m_inst->get_id();;
    };
[[nodiscard]] const QString &  Book__allBooks::get_title() const {
return *m_inst->get_title();;
    };
[[nodiscard]] const QString &  Book__allBooks::get_author() const {
return *m_inst->get_author();;
    };
[[nodiscard]] const QString &  Book__allBooks::get_content() const {
return *m_inst->get_content();;
    };

// args builders


void Book__allBooks::qtgql_replace_concrete(const std::shared_ptr<Book> & new_inst){
    if (new_inst == m_inst){
    return;
    }
    m_inst->disconnect(this);
    if(m_inst->m_id != new_inst->m_id){
    



auto operation = m_operation;
emit idChanged();

    };
    if(m_inst->m_title != new_inst->m_title){
    



auto operation = m_operation;
emit titleChanged();

    };
    if(m_inst->m_author != new_inst->m_author){
    



auto operation = m_operation;
emit authorChanged();

    };
    if(m_inst->m_content != new_inst->m_content){
    



auto operation = m_operation;
emit contentChanged();

    };
    m_inst = new_inst;
    _qtgql_connect_signals();
};
// Constructor
Query__::Query__(AllBooks * operation, const std::shared_ptr<Query> &inst)
: m_inst{inst}, ObjectTypeABC
::ObjectTypeABC
(operation)
{
    m_operation = operation;



    
    auto init_vec_allBooks =  std::vector<Book__allBooks*>();
    for (const auto & node: m_inst->get_allBooks()
){
    init_vec_allBooks.push_back(new Book__allBooks(operation, node));
    }
    m_allBooks = new qtgql::bases::ListModelABC<Book__allBooks *>(this, std::move(init_vec_allBooks));
    

    _qtgql_connect_signals();
}

void Query__::_qtgql_connect_signals(){
auto m_inst_ptr = m_inst.get();
Q_ASSERT_X(m_inst_ptr, __FILE__, "Tried to instantiate a proxy object with an empty pointer!");
connect(m_inst_ptr, &Books::Query::allBooksChanged, this,
[&](){




auto operation = m_operation;
auto new_data = m_inst->get_allBooks();
    auto new_len = new_data.size();
    auto prev_len = m_allBooks->rowCount();
    if (new_len < prev_len){
        m_allBooks->removeRows(new_len, prev_len - new_len);
    }
    for (int i = 0; i < new_len; i++){
        const auto& concrete = new_data.at(i);
    if (i >= prev_len){
            m_allBooks->append(new Book__allBooks(operation, concrete));
        } else {
            auto proxy_to_update = m_allBooks->get(i);
            if(proxy_to_update){
                proxy_to_update->qtgql_replace_concrete(concrete);
            }
            else{ m_allBooks->replace(i, new Book__allBooks(operation, concrete));
            }
        }

    
    }

});
};

// Deserialzier


// Updater
void updaters::update_Query__(const std::shared_ptr<Query> & inst, const QJsonObject &data, const AllBooks * operation)
{
if (!data.value("allBooks").isNull()){

    
    
if (!data.value("allBooks").isNull()){

        std::vector<std::shared_ptr<Book>> allBooks_init_vec;
        for (const auto& node: data.value("allBooks").toArray()){
        
            allBooks_init_vec.push_back(deserializers::des_Book__allBooks(node.toObject(), operation));
        
        };
        inst->set_allBooks(allBooks_init_vec );
    

};
    

}


};



// Query__ Getters
[[nodiscard]] const qtgql::bases::ListModelABC<Book__allBooks *> *  Query__::get_allBooks() const {
return m_allBooks;
};

// args builders



}
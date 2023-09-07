#include "./CreateBook.hpp"

namespace Books::createbook{

// Interfaces



// Constructor
Book__createBookresult::Book__createBookresult(CreateBook * operation, const std::shared_ptr<Book> &inst)
: m_inst{inst}, ObjectTypeABC
::ObjectTypeABC
(operation)
{
    m_operation = operation;



    



    



    



    _qtgql_connect_signals();
}

void Book__createBookresult::_qtgql_connect_signals(){
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

std::shared_ptr<Book> deserializers::des_Book__createBookresult(const QJsonObject& data, const CreateBook * operation){
if (data.isEmpty()){
    return {};
}

auto cached_maybe = Book::get_node(data.value("id").toString());
if(cached_maybe.has_value()){
    auto node = cached_maybe.value();
    updaters::update_Book__createBookresult(node, data, operation);
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
void updaters::update_Book__createBookresult(const std::shared_ptr<Book> & inst, const QJsonObject &data, const CreateBook * operation)
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



// Book__createBookresult Getters
[[nodiscard]] const qtgql::bases::scalars::Id &  Book__createBookresult::get_id() const {
return *m_inst->get_id();;
    };
[[nodiscard]] const QString &  Book__createBookresult::get_title() const {
return *m_inst->get_title();;
    };
[[nodiscard]] const QString &  Book__createBookresult::get_author() const {
return *m_inst->get_author();;
    };
[[nodiscard]] const QString &  Book__createBookresult::get_content() const {
return *m_inst->get_content();;
    };

// args builders


void Book__createBookresult::qtgql_replace_concrete(const std::shared_ptr<Book> & new_inst){
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
BookCreatePayload__createBook::BookCreatePayload__createBook(CreateBook * operation, const std::shared_ptr<BookCreatePayload> &inst)
: m_inst{inst}, ObjectTypeABC
::ObjectTypeABC
(operation)
{
    m_operation = operation;



if (m_inst->get_result()
){
m_result = new Book__createBookresult(operation, m_inst->get_result()
);
}

    _qtgql_connect_signals();
}

void BookCreatePayload__createBook::_qtgql_connect_signals(){
auto m_inst_ptr = m_inst.get();
Q_ASSERT_X(m_inst_ptr, __FILE__, "Tried to instantiate a proxy object with an empty pointer!");
connect(m_inst_ptr, &Books::BookCreatePayload::resultChanged, this,
[&](){




auto operation = m_operation;
auto concrete = m_inst->get_result();
if (m_result){
    m_result->qtgql_replace_concrete(concrete);
}
else{
    m_result = new Book__createBookresult(operation, concrete);
    emit resultChanged();
}

});
};

// Deserialzier

std::shared_ptr<BookCreatePayload> deserializers::des_BookCreatePayload__createBook(const QJsonObject& data, const CreateBook * operation){
if (data.isEmpty()){
    return {};
}
auto inst = BookCreatePayload::shared();

if (!data.value("result").isNull()){
inst->set_result(deserializers::des_Book__createBookresult(data.value("result").toObject(), operation) );


};


return inst;
};


// Updater
void updaters::update_BookCreatePayload__createBook(const std::shared_ptr<BookCreatePayload> & inst, const QJsonObject &data, const CreateBook * operation)
{
if (!data.value("result").isNull()){

    auto result_data = data.value("result").toObject();
    
    if (inst->m_result && *inst->m_result->get_id() == result_data.value("id").toString()){
    updaters::update_Book__createBookresult(inst->m_result, result_data,  operation);
    }
    else{
    inst->set_result(deserializers::des_Book__createBookresult(result_data, operation) );
    }
    

}

else {
inst->set_result({} );
}


};



// BookCreatePayload__createBook Getters
[[nodiscard]] const Book__createBookresult *  BookCreatePayload__createBook::get_result() const {
return m_result;
};

// args builders


void BookCreatePayload__createBook::qtgql_replace_concrete(const std::shared_ptr<BookCreatePayload> & new_inst){
    if (new_inst == m_inst){
    return;
    }
    m_inst->disconnect(this);
    if(m_inst->m_result != new_inst->m_result){
    



auto operation = m_operation;
auto concrete = m_inst->get_result();
if (m_result){
    m_result->qtgql_replace_concrete(concrete);
}
else{
    m_result = new Book__createBookresult(operation, concrete);
    emit resultChanged();
}

    };
    m_inst = new_inst;
    _qtgql_connect_signals();
};
// Constructor
Mutation__::Mutation__(CreateBook * operation, const std::shared_ptr<Mutation> &inst)
: m_inst{inst}, ObjectTypeABC
::ObjectTypeABC
(operation)
{
    m_operation = operation;auto args_for_createBook = Mutation__::build_args_for_createBook( operation);



m_createBook = new BookCreatePayload__createBook(operation, m_inst->get_createBook(args_for_createBook)
);

    _qtgql_connect_signals();
}

void Mutation__::_qtgql_connect_signals(){
auto m_inst_ptr = m_inst.get();
Q_ASSERT_X(m_inst_ptr, __FILE__, "Tried to instantiate a proxy object with an empty pointer!");
connect(m_inst_ptr, &Books::Mutation::createBookChanged, this,
[&](){
auto args_for_createBook = Mutation__::build_args_for_createBook(m_operation);



auto operation = m_operation;
auto concrete = m_inst->get_createBook(args_for_createBook);
if (m_createBook){
    m_createBook->qtgql_replace_concrete(concrete);
}
else{
    m_createBook = new BookCreatePayload__createBook(operation, concrete);
    emit createBookChanged();
}

});
};

// Deserialzier


// Updater
void updaters::update_Mutation__(const std::shared_ptr<Mutation> & inst, const QJsonObject &data, const CreateBook * operation)
{
QJsonObject m_createBook_args = Mutation__::build_args_for_createBook(operation);
if (!qtgql::bases::backports::map_contains(inst->m_createBook, m_createBook_args))

{
if (!data.value("createBook").isNull()){
inst->set_createBook(deserializers::des_BookCreatePayload__createBook(data.value("createBook").toObject(), operation) 
, Mutation__::build_args_for_createBook(operation)
);


};
}
else
if (!data.value("createBook").isNull()){

    auto createBook_data = data.value("createBook").toObject();
    
    updaters::update_BookCreatePayload__createBook(inst->m_createBook.at(m_createBook_args), createBook_data,  operation);
    

}


};



// Mutation__ Getters
[[nodiscard]] const BookCreatePayload__createBook *  Mutation__::get_createBook() const {
return m_createBook;
};

// args builders
QJsonObject  Mutation__::build_args_for_createBook(const CreateBook* operation){
    QJsonObject qtgql__ret;
    
qtgql__ret.insert("input",  operation->vars_inst.input 
->to_json());


    return qtgql__ret;
}



}
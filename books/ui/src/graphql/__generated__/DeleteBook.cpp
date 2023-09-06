#include "./DeleteBook.hpp"

namespace Books::deletebook{

// Interfaces



// Constructor
Mutation__::Mutation__(DeleteBook * operation, const std::shared_ptr<Mutation> &inst)
: m_inst{inst}, ObjectTypeABC
::ObjectTypeABC
(operation)
{
    m_operation = operation;auto args_for_deleteBook = Mutation__::build_args_for_deleteBook( operation);



    _qtgql_connect_signals();
}

void Mutation__::_qtgql_connect_signals(){
auto m_inst_ptr = m_inst.get();
Q_ASSERT_X(m_inst_ptr, __FILE__, "Tried to instantiate a proxy object with an empty pointer!");
connect(m_inst_ptr, &Books::Mutation::deleteBookChanged, this,
[&](){
auto args_for_deleteBook = Mutation__::build_args_for_deleteBook(m_operation);



auto operation = m_operation;
emit deleteBookChanged();

});
};

// Deserialzier


// Updater
void updaters::update_Mutation__(const std::shared_ptr<Mutation> & inst, const QJsonObject &data, const DeleteBook * operation)
{
QJsonObject m_deleteBook_args = Mutation__::build_args_for_deleteBook(operation);
if (!qtgql::bases::backports::map_contains(inst->m_deleteBook, m_deleteBook_args))

{
if (!data.value("deleteBook").isNull()){
inst->set_deleteBook(std::make_shared<bool>(data.value("deleteBook").toBool()) 
, Mutation__::build_args_for_deleteBook(operation)
);
    
    
};
}
else
if (!data.value("deleteBook").isNull()){
auto new_deleteBook = std::make_shared<bool>(data.value("deleteBook").toBool());
    auto old_deleteBook = inst->m_deleteBook.at(m_deleteBook_args);
    if (*old_deleteBook != *new_deleteBook){
        inst->set_deleteBook(new_deleteBook , m_deleteBook_args
);
    }
    
}


};



// Mutation__ Getters
[[nodiscard]] const bool &  Mutation__::get_deleteBook() const {
return *m_inst->get_deleteBook(build_args_for_deleteBook(m_operation)
    );;
    };

// args builders
QJsonObject  Mutation__::build_args_for_deleteBook(const DeleteBook* operation){
    QJsonObject qtgql__ret;
    
qtgql__ret.insert("bookId",  operation->vars_inst.bookID 
);


    return qtgql__ret;
}



}
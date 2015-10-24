// $Id: type_checker.cpp,v 1.17 2015/05/19 23:15:48 ist173245 Exp $ -*- c++ -*-
#include <string>
#include "targets/type_checker.h"
#include "ast/all.h"  // automatically generated

#define ASSERT_UNSPEC \
    { if (node->type() != nullptr && \
          node->type()->name() != basic_type::TYPE_UNSPEC) return; }

//---------------------------------------------------------------------------

void pwn::type_checker::do_integer_node(cdk::integer_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(new basic_type(4, basic_type::TYPE_INT));
}

void pwn::type_checker::do_string_node(cdk::string_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(new basic_type(4, basic_type::TYPE_STRING));
}

//---------------------------------------------------------------------------

inline void pwn::type_checker::processUnaryExpression(cdk::unary_expression_node * const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
  if (node->argument()->type()->name() != basic_type::TYPE_INT)
    throw std::string("wrong type in argument of unary expression");

  // in Simple, expressions are always int
  node->type(new basic_type(4, basic_type::TYPE_INT));
}

void pwn::type_checker::do_neg_node(cdk::neg_node * const node, int lvl) {
  processUnaryExpression(node, lvl);
}

//---------------------------------------------------------------------------

inline void pwn::type_checker::processBinaryExpression(cdk::binary_expression_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  if (node->left()->type()->name() != basic_type::TYPE_INT)
    throw std::string("wrong type in left argument of binary expression");

  node->right()->accept(this, lvl + 2);
  if (node->right()->type()->name() != basic_type::TYPE_INT)
    throw std::string("wrong type in right argument of binary expression");

  // in Simple, expressions are always int
  node->type(new basic_type(4, basic_type::TYPE_INT));
}

void pwn::type_checker::do_add_node(cdk::add_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void pwn::type_checker::do_sub_node(cdk::sub_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void pwn::type_checker::do_mul_node(cdk::mul_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void pwn::type_checker::do_div_node(cdk::div_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void pwn::type_checker::do_mod_node(cdk::mod_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void pwn::type_checker::do_lt_node(cdk::lt_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void pwn::type_checker::do_le_node(cdk::le_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void pwn::type_checker::do_ge_node(cdk::ge_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void pwn::type_checker::do_gt_node(cdk::gt_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void pwn::type_checker::do_ne_node(cdk::ne_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void pwn::type_checker::do_eq_node(cdk::eq_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}

//---------------------------------------------------------------------------

void pwn::type_checker::do_rvalue_node(pwn::rvalue_node * const node, int lvl) {
  node->lvalue()->accept(this, lvl);
  node->type(node->lvalue()->type());
}

//---------------------------------------------------------------------------

void pwn::type_checker::do_lvalue_node(pwn::lvalue_node * const node, int lvl) {
  const std::string &id = *node->identifier();
  std::shared_ptr<pwn::symbol> symbol = _symtab.find(id);
  
  if (symbol == nullptr) 
    throw id + " undeclared";
  else
    node->type(symbol->type());
}

//---------------------------------------------------------------------------

void pwn::type_checker::do_assignment_node(pwn::assignment_node * const node, int lvl) {
  ASSERT_UNSPEC;

  // DAVID: horrible hack!
  // (this is caused by Simple not having explicit variable declarations)
  const std::string &id = *node->lvalue()->identifier();
  if (!_symtab.find(id)) {
    _symtab.insert(id, std::make_shared<pwn::symbol>(new basic_type(4, basic_type::TYPE_INT), id, -1)); // put in the symbol table
  }

  node->lvalue()->accept(this, lvl + 2);
  if (node->lvalue()->type()->name() != basic_type::TYPE_INT)
    throw std::string("wrong type in left argument of assignment expression");

  node->rvalue()->accept(this, lvl + 2);
  if (node->rvalue()->type()->name() != basic_type::TYPE_INT)
    throw std::string("wrong type in right argument of assignment expression");

  // in Simple, expressions are always int
  node->type(new basic_type(4, basic_type::TYPE_INT));
}

//---------------------------------------------------------------------------

void pwn::type_checker::do_evaluation_node(pwn::evaluation_node * const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
}

void pwn::type_checker::do_print_node(pwn::print_node * const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
}

//---------------------------------------------------------------------------

void pwn::type_checker::do_read_node(pwn::read_node * const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
}

//---------------------------------------------------------------------------

void pwn::type_checker::do_while_node(cdk::while_node * const node, int lvl) {
  node->condition()->accept(this, lvl + 2);
  
}

void pwn::type_checker::do_repeat_node(pwn::repeat_node * const node, int lvl) {
  node->init()->accept(this, lvl + 2); 
  node->condition()->accept(this, lvl + 4);
  node->inc()->accept(this, lvl + 2);
  node->block()->accept(this, lvl +2); 
}

//---------------------------------------------------------------------------

void pwn::type_checker::do_if_node(cdk::if_node * const node, int lvl) {
  node->condition()->accept(this, lvl + 4);
  node->block()->accept(this, lvl + 4); 
}

void pwn::type_checker::do_if_else_node(cdk::if_else_node * const node, int lvl) {
  node->condition()->accept(this, lvl + 4);
}

void pwn::type_checker::do_next_node(pwn::next_node * const node, int lvl) {
  node->nesimo()->accept(this, lvl + 2);
  
  if(node->nesimo()->type()->name() != basic_type::TYPE_INT){
    throw std::string("Error on next: argument is not an integer");   
  }
}

void pwn::type_checker::do_stop_node(pwn::stop_node * const node, int lvl) {
  node->nesimo()->accept(this, lvl + 2);
  
  if(node->nesimo()->type()->name() != basic_type::TYPE_INT){
    throw std::string("Error on next: argument is not an integer");   
  }
}

void pwn::type_checker::do_funcdec_node(pwn::funcdec_node * const node, int lvl) {
  const char *id = node->identifier()->c_str();
  std::shared_ptr<pwn::symbol> symbol = _symtab.find(id);
  
  if(symbol) 
    throw "Error on function declaration: identifier " + std::string(id) + " is already defined."; 
}

void pwn::type_checker::do_funcdef_node(pwn::funcdef_node * const node, int lvl) {
  if(node->literal()){
      node->literal()->accept(this, lvl+2);
      if(node->literal()->type()->name() != node->type()->name()){
	std::cerr <<  "Error: FunctionDef: default return value has wrong type " << std::endl;
      }
  }
  
  const std::string &id = *node->identifier();
  
  // se nao for encontrado na tabela de simbolos
  if (!_symtab.find(id)) {
    //_symtab.insert(id, std::shared_ptr<pwn::symbol>(node->type(), id, node->literal())); // put in the symbol table
    _symtab.insert(id, std::make_shared<pwn::symbol>(node->type(), id, -1)); // put in the symbol table
  }
  
  if(node->args()) 
    node->args()->accept(this, lvl+2);
  
}

void pwn::type_checker::do_funccall_node(pwn::funccall_node * const node, int lvl) {
  
  const std::string &id = *node->identifier();
  std::shared_ptr<pwn::symbol> symbol = _symtab.find(id);

  if(symbol){
    node->type(symbol->type());
    if(node->args() != NULL){
      if( symbol->num_args() == node->args()->size()){                                                
	 if(symbol->funcargs().size() != (size_t) 0){
	   for(size_t i = 0; i < symbol->num_args(); i++){
	     node->args()->node(i)->accept(this, lvl+2);
	     if(symbol->getarg(i)->name() == basic_type::TYPE_DOUBLE && ((cdk::expression_node*)node->args()->node(i))->type()->name() == basic_type::TYPE_INT){
	     }
	     else if(symbol->getarg(i)->name() != ((cdk::expression_node*)node->args()->node(i))->type()->name()){
	      std::cerr << "Erro no funcCall: argumentos com o tipo errado.\n" ;
	    }   
	  }  
	}
      } else throw "Erro no funcCall: numero errado de argumentos.\n" ;
    }
  } else throw "Erro no funcCall: chamada a funcao nao declarada. " + std::string(id) + "\n";

}

void pwn::type_checker::do_vardec_node(pwn::vardec_node * const node, int lvl) {
  if(node->expression() != NULL) {
      node->expression()->accept(this, lvl+1);
  }
  
}

void pwn::type_checker::do_noob_node(pwn::noob_node * const node, int lvl) {
  //Nao e preciso fazer nada pois nao interfere com argumentos porque e o ponteiro vazio
}

void pwn::type_checker::do_reservememory_node(pwn::reservememory_node * const node, int lvl) {
  node->rvalue()->accept(this, lvl + 2);
  
  if(node->argument()->type()->name() != basic_type::TYPE_INT){
    throw std::string("Error on reserve memory: nof found an integer");
  }
}

void pwn::type_checker::do_and_node(pwn::and_node * const node, int lvl){
  processBinaryExpression(node, lvl);
 
}

void pwn::type_checker::do_or_node(pwn::or_node * const node, int lvl){
  processBinaryExpression(node, lvl);
}

void pwn::type_checker::do_not_node(pwn::not_node * const node, int lvl){
  node->rexpr()->accept(this, lvl + 2);
  
  if(node->rexpr()->type()->name() != basic_type::TYPE_INT){
    throw std::string("Error on not: argument type must be an integer");
  } else node->type(new basic_type(4, basic_type::TYPE_INT)); 
}

void pwn::type_checker::do_adressmemory_node(pwn::adressmemory_node * const node, int lvl){
}

void pwn::type_checker::do_return_node(pwn::return_node * const node, int lvl){
  //Nao e preciso fazer nada porque pode retornar qualquer coisa
}

void pwn::type_checker::do_index_node(pwn::index_node * const node, int lvl){
  const std::string &id = *node->expr();
  if (!_symtab.find(id))
    throw "Error on index: Identifier not declared";
 
  if(node->indexant()->type()->name() != basic_type::TYPE_INT){
      throw "Error on index: Integer not found"; 
  } 
  else node->type(new basic_type(4, basic_type::TYPE_INT));  
}

void pwn::type_checker::do_block_node(pwn::block_node * const node, int lvl){
  if(node->decs())
    node->decs()->accept(this, lvl + 4);
  if(node->exprs())
      node->exprs()->accept(this, lvl + 4);
}

// $Id: postfix_writer.cpp,v 1.24 2015/05/20 01:49:04 ist174117 Exp $ -*- c++ -*-
#include <string>
#include <sstream>
#include "targets/type_checker.h"
#include "targets/postfix_writer.h"
#include "ast/all.h"  // all.h is automatically generated

//---------------------------------------------------------------------------
//     THIS IS THE VISITOR'S DEFINITION
//---------------------------------------------------------------------------

void pwn::postfix_writer::do_sequence_node(cdk::sequence_node * const node, int lvl) {
  for (size_t i = 0; i < node->size(); i++) {
    node->node(i)->accept(this, lvl);
  }
}

//---------------------------------------------------------------------------

void pwn::postfix_writer::do_integer_node(cdk::integer_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  
  if(_global_context) {
    _pf.CONST(node->value()); // push an integer
  }
  else{
    _pf.INT(node->value()); // push an integer
  }
}

void pwn::postfix_writer::do_string_node(cdk::string_node * const node, int lvl) {
  
  int lbl1;

  /* generate the string */
  _pf.RODATA(); // strings are DATA readonly
  _pf.ALIGN(); // make sure we are aligned
  _pf.LABEL(mklbl(lbl1 = ++_lbl)); // give the string a name 
  _pf.STR(node->value()); // output string characters

  if(_global_context){
    _pf.DATA(); // return to the TEXT segment
    _pf.ID(mklbl(lbl1)); // the string to be printed
  } else {
    _pf.TEXT(); // return to the TEXT segment
    _pf.ADDR(mklbl(lbl1)); // the string to be printed
  }
  
  /*
   int lbl1;

  _pf.RODATA(); // strings are DATA readonly
  _pf.ALIGN(); // make sure we are aligned
  _pf.LABEL(mklbl(lbl1 = ++_lbl)); // give the string a name 
  _pf.STR(node->value()); // output string characters

  
  _pf.TEXT(); // return to the TEXT segment
  _pf.ADDR(mklbl(lbl1)); // the string to be printed
  */
}

//---------------------------------------------------------------------------

void pwn::postfix_writer::do_neg_node(cdk::neg_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->argument()->accept(this, lvl); // determine the value
  _pf.NEG(); // 2-complement
}

//---------------------------------------------------------------------------

void pwn::postfix_writer::do_add_node(cdk::add_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.ADD();
}
void pwn::postfix_writer::do_sub_node(cdk::sub_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.SUB();
}
void pwn::postfix_writer::do_mul_node(cdk::mul_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.MUL();
}
void pwn::postfix_writer::do_div_node(cdk::div_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.DIV();
}
void pwn::postfix_writer::do_mod_node(cdk::mod_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.MOD();
}
void pwn::postfix_writer::do_lt_node(cdk::lt_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.LT();
}
void pwn::postfix_writer::do_le_node(cdk::le_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.LE();
}
void pwn::postfix_writer::do_ge_node(cdk::ge_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.GE();
}
void pwn::postfix_writer::do_gt_node(cdk::gt_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.GT();
}
void pwn::postfix_writer::do_ne_node(cdk::ne_node * const node, int lvl) { 
  CHECK_TYPES(_compiler, _symtab, node);
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.NE();
}
void pwn::postfix_writer::do_eq_node(cdk::eq_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.EQ();
}

//---------------------------------------------------------------------------

void pwn::postfix_writer::do_rvalue_node(pwn::rvalue_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->lvalue()->accept(this, lvl);
  _pf.LOAD(); //FIXME: depends on type size
}

//---------------------------------------------------------------------------

void pwn::postfix_writer::do_lvalue_node(pwn::lvalue_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  // simplified generation: all variables are global
  _pf.ADDR(*node->identifier());
}

//---------------------------------------------------------------------------

void pwn::postfix_writer::do_assignment_node(pwn::assignment_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  
  // DAVID: horrible hack!
  // (this is caused by Simple not having explicit variable declarations)
  const std::string &id = *node->lvalue()->identifier();
  std::shared_ptr<pwn::symbol> symbol = _symtab.find(id);
  if (symbol->value() == -1) {
    _pf.DATA(); // variables are all global and live in DATA
    _pf.ALIGN(); // make sure we are aligned
    _pf.LABEL(id); // name variable location
    _pf.CONST(0); // initialize it to 0 (zero)
    _pf.TEXT(); // return to the TEXT segment
    symbol->value(0);
  }

  node->rvalue()->accept(this, lvl); // determine the new value
  _pf.DUP();
  node->lvalue()->accept(this, lvl); // where to store the value
  _pf.STORE(); // store the value at address
}

//---------------------------------------------------------------------------

/*void pwn::postfix_writer::do_program_node(pwn::program_node * const node, int lvl) {
  // Note that Simple doesn't have functions. Thus, it doesn't need
  // a function node. However, it must start in the main function.
  // The ProgramNode (representing the whole program) doubles as a
  // main function node.

  // generate the main function (RTS mandates that its name be "_main")
  _pf.TEXT();
  _pf.ALIGN();
  _pf.GLOBAL("_main", _pf.FUNC());
  _pf.LABEL("_main");
  _pf.ENTER(0);  // Simple doesn't implement local variables

  node->statements()->accept(this, lvl);

  // end the main function
  _pf.INT(0);
  _pf.POP();
  _pf.LEAVE();
  _pf.RET();

  // these are just a few library function imports
  _pf.EXTERN("readi");
  _pf.EXTERN("printi");
  _pf.EXTERN("prints");
  _pf.EXTERN("println");
}*/

//---------------------------------------------------------------------------

void pwn::postfix_writer::do_evaluation_node(pwn::evaluation_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->argument()->accept(this, lvl); // determine the value
  if (node->argument()->type()->name() == basic_type::TYPE_INT) {
    _pf.TRASH(4); // delete the evaluated value
  }
  else if (node->argument()->type()->name() == basic_type::TYPE_STRING) {
    _pf.TRASH(4); // delete the evaluated value's address
  }
  else if (node->argument()->type()->name() == basic_type::TYPE_VOID) {
  }  
  else {
    std::cerr << "ERROR: CANNOT HAPPEN!" << std::endl;
    exit(1);
  }
}

void pwn::postfix_writer::do_print_node(pwn::print_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->argument()->accept(this, lvl); // determine the value to print
  if (node->argument()->type()->name() == basic_type::TYPE_INT) {
    _pf.CALL("printi");
    _pf.TRASH(4); // delete the printed value
  }
  else if (node->argument()->type()->name() == basic_type::TYPE_DOUBLE) {
    _pf.CALL("printd");
    _pf.TRASH(4);
  }
  else if (node->argument()->type()->name() == basic_type::TYPE_STRING) {
    _pf.CALL("prints");
    _pf.TRASH(4); // delete the printed value's address
  }
  else {
    std::cerr << "ERROR: CANNOT HAPPEN!" << std::endl;
    exit(1);
  }
  if(node->isnewline()){
  _pf.CALL("println"); // print a newline
  }
}

//---------------------------------------------------------------------------

void pwn::postfix_writer::do_read_node(pwn::read_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  _pf.CALL("readi");
  _pf.PUSH();
  node->argument()->accept(this, lvl);
  _pf.STORE();
}

//---------------------------------------------------------------------------

void pwn::postfix_writer::do_while_node(cdk::while_node * const node, int lvl) {
  int lbl1, lbl2;
  _pf.LABEL(mklbl(lbl1 = ++_lbl));
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(lbl2 = ++_lbl));
  node->block()->accept(this, lvl + 2);
  _pf.JMP(mklbl(lbl1));
  _pf.LABEL(mklbl(lbl2));
}

void pwn::postfix_writer::do_repeat_node(pwn::repeat_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);

  int lbl1 = ++_lbl;
  int lbl2 = ++_lbl;
  int lbl3 = ++_lbl;
  
  if(node->init())
   node->init()->accept(this, lvl);
  
  _pf.LABEL(mklbl(lbl1));
  if(node->condition()){
    node->condition()->accept(this, lvl);
    _pf.JZ(mklbl(lbl2));
  }
  
  node->block()->accept(this, lvl + 2);
  _pf.LABEL(mklbl(lbl3));
  
  if(node->inc()){
    node->inc()->accept(this, lvl + 2);
  }
  _pf.JMP(mklbl(lbl1));  
  _pf.LABEL(mklbl(lbl2));
}

//---------------------------------------------------------------------------

void pwn::postfix_writer::do_if_node(cdk::if_node * const node, int lvl) {
  int lbl1;
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(lbl1 = ++_lbl));
  node->block()->accept(this, lvl + 2);
  _pf.LABEL(mklbl(lbl1));
}

//---------------------------------------------------------------------------

void pwn::postfix_writer::do_if_else_node(cdk::if_else_node * const node, int lvl) {
  int lbl1, lbl2;
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(lbl1 = ++_lbl));
  node->thenblock()->accept(this, lvl + 2);
  _pf.JMP(mklbl(lbl2 = ++_lbl));
  _pf.LABEL(mklbl(lbl1));
  node->elseblock()->accept(this, lvl + 2);
  _pf.LABEL(mklbl(lbl1 = lbl2));
}

void pwn::postfix_writer::do_next_node(pwn::next_node * const node, int lvl) {
  node->nesimo()->accept(this, lvl);
  
  int value = ((cdk::simple_value_node<int>*)node->nesimo())->value();
  
  int size = _nexts.size();
  
  if(size >= value){
    _pf.JMP(mklbl(_nexts[size-value]));
  } else {
    std::cerr << "Error on next" << std::endl; 
  }
}

void pwn::postfix_writer::do_stop_node(pwn::stop_node * const node, int lvl) {
  node->nesimo()->accept(this, lvl);
  
  int value = ((cdk::simple_value_node<int>*)node->nesimo())->value();
  
  int size = _stops.size();
  
  if(size >= value){
    _pf.JMP(mklbl(_stops[size-value]));
  } else {
    std::cerr << "Error on break" << std::endl; 
  }
}

void pwn::postfix_writer::do_funcdec_node(pwn::funcdec_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
}

void pwn::postfix_writer::do_funcdef_node(pwn::funcdef_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  _global_context = false;
    
  std::string name = *node->identifier();
  if(name == "pwn") {name = "_main";} //Para gerar a main, verificar se a main do pwn se chama main
  else if (name == "main") {name = "._main";}
  _pf.EXTERN("readi");
  _pf.EXTERN("readd");
  _pf.EXTERN("printi");
  _pf.EXTERN("printd");
  _pf.EXTERN("prints");
  _pf.EXTERN("println");
  
  _pf.TEXT();
  _pf.ALIGN();
  _pf.GLOBAL(name, _pf.FUNC());
  _pf.LABEL(name);
  _pf.ENTER(node->type()->size()); 
  
  if(node->block() != nullptr)
    node->block()->accept(this, lvl);

  if(node->literal() != nullptr){
    node->literal()->accept(this, lvl);
    
    if(node->literal()->type()->name() == basic_type::TYPE_INT){
      _pf.LOCAL(-4);
      _pf.STORE();
    }
    else if(node->literal()->type()->name() == basic_type::TYPE_STRING){
      _pf.LOCAL(-4);
      _pf.STORE();
    }
    else if(node->literal()->type()->name() == basic_type::TYPE_DOUBLE){
      _pf.LOCAL(-8);
      _pf.STORE();
    }
  }
  else if(node->type()->name() == basic_type::TYPE_POINTER || node->type()->name() == basic_type::TYPE_INT){
      _pf.INT(0);
  }
  
  _pf.POP();
  _pf.LEAVE();
  _pf.RET();
  
  
  _global_context = true;
  

 
}

void pwn::postfix_writer::do_funccall_node(pwn::funccall_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  
  std::string id = *node->identifier();
  if (id.compare("_main") == 0) id = "._main";
  std::shared_ptr<pwn::symbol> symbol = _symtab.find(id); //simbolo da funcao
  
  if(node->args() != nullptr) {
   size_t size = node->args()->size();
   for (size_t i = 0; i < size; i++) {
     node->args()->node(size-i-1)->accept(this, lvl);
     
   }  
    
  }
    
  _pf.CALL(id);
    
  if(node->args() != NULL){ 
    for(size_t i = 0; i < node->args()->size(); i++){
      cdk::basic_node *temp = node->args()->node(i);
      basic_type *bt = ((cdk::expression_node*)temp)->type();
      _pf.TRASH(bt->size());
      
    } 
    
  }
  
  if(symbol->type()->name() == basic_type::TYPE_INT || symbol->type()->name() == basic_type::TYPE_POINTER) {
    _pf.PUSH();
    
  }
  else if(symbol->type()->name() == basic_type::TYPE_DOUBLE || symbol->type()->name() == basic_type::TYPE_STRING) {
    _pf.DPUSH();
    
  }
  
}

void pwn::postfix_writer::do_vardec_node(pwn::vardec_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  
  std::string label;
  label = mklbl(++_lbl);
  
  const std::string &id = *node->identifier();
  std::shared_ptr<pwn::symbol> symbol (new pwn::symbol(node->type(), id,0));
  _symtab.insert(id, symbol); // put in the symbol table
  
  if(node->expression() == NULL) {
    _pf.DATA(); // variables are all global and live in DATA
    _pf.ALIGN(); // make sure we are aligned
    _pf.LABEL(id); // name variable location
    _pf.CONST(0); // initialize it to 0 (zero)
    _pf.TEXT(); // return to the TEXT segment
    symbol->value(0);
  }
  else{
    _pf.DATA();
    _pf.ALIGN();
    _pf.LABEL(id);
    
    /*
    if((node->type()->name() == basic_type::TYPE_DOUBLE)
    && (node->expression()->type()->name() == basic_type::TYPE_INT)) {
      // _pf.DOUBLE(((cdk::node::expression::Simple<int>*)node->expression())->value());
      std::cout << "convert int to double" << std::endl;
      //TODO tentar metodo ob1
      
    }*/
    
    node->expression()->accept(this, lvl+1);
  }
}

void pwn::postfix_writer::do_noob_node(pwn::noob_node * const node, int lvl) {
  
  //TODO 
}

void pwn::postfix_writer::do_reservememory_node(pwn::reservememory_node * const node, int lvl) {
  
  //TODO 
}

void pwn::postfix_writer::do_and_node(pwn::and_node * const node, int lvl) {
  
  int lbl1 = ++_lbl;
  
  CHECK_TYPES(_compiler, _symtab, node);
  
  node->left()->accept(this, lvl);
  
  if(node->type()->name() == basic_type::TYPE_DOUBLE) { 
    _pf.DDUP();  
  } 
  else { _pf.DUP(); }
  _pf.JZ(mklbl(lbl1));
  
  node->right()->accept(this, lvl);
  
  _pf.AND();
  
  _pf.ALIGN();
  _pf.LABEL(mklbl(lbl1));
}

void pwn::postfix_writer::do_or_node(pwn::or_node * const node, int lvl) {
  
  int lbl1 = ++_lbl;
  
  CHECK_TYPES(_compiler, _symtab, node);
  
  node->left()->accept(this, lvl);
  
  if(node->type()->name() == basic_type::TYPE_DOUBLE) { 
    _pf.DDUP();  
  } 
  else { _pf.DUP(); }
  _pf.JNZ(mklbl(lbl1));
  
  node->right()->accept(this, lvl);
  
  _pf.OR();
  
  _pf.ALIGN();
  _pf.LABEL(mklbl(lbl1));
}

void pwn::postfix_writer::do_not_node(pwn::not_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  node->argument()->accept(this, lvl);
  _pf.NOT(); 
}

void pwn::postfix_writer::do_adressmemory_node(pwn::adressmemory_node * const node, int lvl) {
  
  //TODO
}

void pwn::postfix_writer::do_return_node(pwn::return_node * const node, int lvl) {
  //TODO
}

void pwn::postfix_writer::do_index_node(pwn::index_node * const node, int lvl) {
 /* CHECK_TYPES(_compiler, _symtab, node);
  
  node->expr()->accept(this, lvl+1);
  
  _pf.INT(); //CENAS
  _pf.MUL();
  _pf.ADD();
 */
}

void pwn::postfix_writer::do_block_node(pwn::block_node * const node, int lvl) {
  if(node->decs())
    node->decs()->accept(this, lvl + 4);
  if(node->exprs())
      node->exprs()->accept(this, lvl + 4);
}




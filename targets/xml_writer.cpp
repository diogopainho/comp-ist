// $Id: xml_writer.cpp,v 1.16 2015/05/18 19:41:51 ist173245 Exp $ -*- c++ -*-
#include <string>
#include "targets/xml_writer.h"
#include "targets/type_checker.h"
#include "ast/all.h"  // automatically generated

//---------------------------------------------------------------------------

void pwn::xml_writer::do_sequence_node(cdk::sequence_node * const node, int lvl) {
  os() << std::string(lvl, ' ') << "<sequence_node size='" << node->size() << "'>" << std::endl;
  for (size_t i = 0; i < node->size(); i++)
    node->node(i)->accept(this, lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void pwn::xml_writer::do_integer_node(cdk::integer_node * const node, int lvl) {
  processSimple(node, lvl);
}

void pwn::xml_writer::do_string_node(cdk::string_node * const node, int lvl) {
  processSimple(node, lvl);
}

//---------------------------------------------------------------------------

inline void pwn::xml_writer::processUnaryExpression(cdk::unary_expression_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void pwn::xml_writer::do_neg_node(cdk::neg_node * const node, int lvl) {
  processUnaryExpression(node, lvl);
}

//---------------------------------------------------------------------------

inline void pwn::xml_writer::processBinaryExpression(cdk::binary_expression_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  openTag(node, lvl);
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void pwn::xml_writer::do_add_node(cdk::add_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void pwn::xml_writer::do_sub_node(cdk::sub_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void pwn::xml_writer::do_mul_node(cdk::mul_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void pwn::xml_writer::do_div_node(cdk::div_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void pwn::xml_writer::do_mod_node(cdk::mod_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void pwn::xml_writer::do_lt_node(cdk::lt_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void pwn::xml_writer::do_le_node(cdk::le_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void pwn::xml_writer::do_ge_node(cdk::ge_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void pwn::xml_writer::do_gt_node(cdk::gt_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void pwn::xml_writer::do_ne_node(cdk::ne_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void pwn::xml_writer::do_eq_node(cdk::eq_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}

//---------------------------------------------------------------------------

void pwn::xml_writer::do_rvalue_node(pwn::rvalue_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  openTag(node, lvl);
  node->lvalue()->accept(this, lvl + 4);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void pwn::xml_writer::do_lvalue_node(pwn::lvalue_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  openTag(node, lvl);
  node->accept(this, lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void pwn::xml_writer::do_assignment_node(pwn::assignment_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  openTag(node, lvl);
  node->lvalue()->accept(this, lvl + 2);
  openTag("rvalue", lvl + 2);
  node->rvalue()->accept(this, lvl + 4);
  closeTag("rvalue", lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

/*void pwn::xml_writer::do_program_node(pwn::program_node * const node, int lvl) {
  openTag(node, lvl);
  node->statements()->accept(this, lvl + 4);
  closeTag(node, lvl);
}*/

//---------------------------------------------------------------------------

void pwn::xml_writer::do_evaluation_node(pwn::evaluation_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void pwn::xml_writer::do_print_node(pwn::print_node * const node, int lvl) {
  CHECK_TYPES(_compiler, _symtab, node);
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void pwn::xml_writer::do_read_node(pwn::read_node * const node, int lvl) {
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void pwn::xml_writer::do_while_node(cdk::while_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("condition", lvl + 2);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl + 2);
  openTag("block", lvl + 2);
  node->block()->accept(this, lvl + 4);
  closeTag("block", lvl + 2);
  closeTag(node, lvl);
} 

void pwn::xml_writer::do_repeat_node(pwn::repeat_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("init", lvl + 2);
  node->init()->accept(this, lvl + 4);
  closeTag("init", lvl + 2);
  openTag("condition", lvl + 2);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl + 2);
  openTag("inc", lvl + 2);
  node->inc()->accept(this, lvl + 4);
  closeTag("inc", lvl + 2);
  openTag("block", lvl + 2);
  node->block()->accept(this, lvl + 4);
  closeTag("block", lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void pwn::xml_writer::do_if_node(cdk::if_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("condition", lvl + 2);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl + 2);
  openTag("then", lvl + 2);
  node->block()->accept(this, lvl + 4);
  closeTag("then", lvl + 2);
  closeTag(node, lvl);
}

void pwn::xml_writer::do_if_else_node(cdk::if_else_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("condition", lvl + 2);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl + 2);
  openTag("then", lvl + 2);
  node->thenblock()->accept(this, lvl + 4);
  closeTag("then", lvl + 2);
  openTag("else", lvl + 2);
  node->elseblock()->accept(this, lvl + 4);
  closeTag("else", lvl + 2);
  closeTag(node, lvl);
}

void pwn::xml_writer::do_next_node(pwn::next_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("nesimo", lvl + 2);
  node->nesimo()->accept(this, lvl + 4);
  closeTag("nesimo", lvl + 2);
  closeTag(node, lvl);
}

void pwn::xml_writer::do_stop_node(pwn::stop_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("nesimo", lvl + 2);
  node->nesimo()->accept(this, lvl + 4);
  closeTag("nesimo", lvl + 2);
  closeTag(node, lvl);
}

void pwn::xml_writer::do_funcdec_node(pwn::funcdec_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("type", lvl + 2);
  node->type();
  closeTag("type", lvl + 2);
  openTag("identifier", lvl + 2);
  std::cout<<node->identifier()<<std::endl;
  closeTag("identifier", lvl + 2);
  openTag("args", lvl + 2);
  if(node->args())
    node->args()->accept(this, lvl + 4);
  closeTag("args", lvl + 2);
  closeTag(node, lvl);
}

void pwn::xml_writer::do_funcdef_node(pwn::funcdef_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("type", lvl + 2);
  node->type();
  closeTag("type", lvl + 2);
  openTag("identifier", lvl + 2);
  std::cout<<node->identifier()<<std::endl;
  closeTag("identifier", lvl + 2);
  openTag("args", lvl + 2);
  if(node->args())
    node->args()->accept(this, lvl + 4);
  closeTag("args", lvl + 2);
  openTag("literal", lvl + 2);
  node->literal()->accept(this, lvl + 4);
  closeTag("literal", lvl + 2);
  openTag("block", lvl + 2);
  node->block()->accept(this, lvl + 4);
  closeTag("block", lvl + 2);
  closeTag(node, lvl);
}

void pwn::xml_writer::do_funccall_node(pwn::funccall_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("identifier", lvl + 2);
  std::cout<<node->identifier()<<std::endl;
  closeTag("identifier", lvl + 2);
  openTag("args", lvl + 2);
  if(node->args())
    node->args()->accept(this, lvl + 4);
  closeTag("args", lvl + 2);
  closeTag(node, lvl);
}

void pwn::xml_writer::do_vardec_node(pwn::vardec_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("type", lvl + 2);
  node->type();
  closeTag("type", lvl + 2);
  openTag("identifier", lvl + 2);
  node->identifier();
  closeTag("identifier", lvl + 2);
  closeTag(node, lvl);
}


void pwn::xml_writer::do_noob_node(pwn::noob_node * const node, int lvl){
  openTag(node, lvl);
  openTag(node, lvl);
}

void pwn::xml_writer::do_reservememory_node(pwn::reservememory_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("rvalue", lvl + 2);
  node->rvalue()->accept(this, lvl + 4);
  closeTag("rvalue", lvl + 2);
  closeTag(node, lvl);
}

void pwn::xml_writer::do_and_node(pwn::and_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}

void pwn::xml_writer::do_or_node(pwn::or_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}

void pwn::xml_writer::do_not_node(pwn::not_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("rexpr", lvl + 2);
  node->rexpr()->accept(this, lvl + 4);
  closeTag("rexpr", lvl + 2);
  closeTag(node, lvl);
 
}

void pwn::xml_writer::do_adressmemory_node(pwn::adressmemory_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("expr", lvl + 2);
  node->expr()->accept(this, lvl + 4);
  closeTag("expr", lvl + 2);
  closeTag(node, lvl);
 
}

void pwn::xml_writer::do_return_node(pwn::return_node * const node, int lvl){
  openTag(node, lvl);
  closeTag(node, lvl);
}

void pwn::xml_writer::do_index_node(pwn::index_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("expr", lvl + 2);
  node->expr();
  closeTag("expr", lvl + 2);
  openTag("indexant", lvl + 2);
  node->indexant()->accept(this, lvl + 4);
  closeTag("indexant", lvl + 2); 
  closeTag(node, lvl);
}

void pwn::xml_writer::do_block_node(pwn::block_node * const node, int lvl) {
  openTag(node, lvl);
  openTag("decs", lvl + 2);
  if(node->decs())
    node->decs()->accept(this, lvl + 4);
  closeTag("decs", lvl + 2);
  
  openTag("expr", lvl + 2);
  if(node->exprs())
      node->exprs()->accept(this, lvl + 4); 
  closeTag("expr", lvl + 2); 
  closeTag(node, lvl);
}

// $Id: index_node.h,v 1.6 2015/04/13 02:33:42 ist174117 Exp $ -*- c++ -*-
#ifndef __PWN_INDEXNODE_H__
#define __PWN_INDEXNODE_H__

#include <cdk/ast/expression_node.h>


namespace pwn {

  /**
   * Class for describing index node.
   */
  class index_node: public pwn::lvalue_node {
    std::string *_expr;
    cdk::expression_node *_indexant;
    //cdk::expression_node *_expression;

  public:
    inline index_node(int lineno, std::string *expr, cdk::expression_node *indexant) :
        lvalue_node(lineno, expr), _expr(expr), _indexant(indexant)  {
    }
    /*
    inline index_node(int lineno, cdk::expression_node *expression, cdk::expression_node *indexant) :
        lvalue_node(lineno), _expression(expression), _indexant(indexant)  {
    }
    */
    
  public:
    inline std::string *expr(){
      return _expr; 
    }
    inline cdk::expression_node *indexant(){
      return _indexant; 
    }
    /*
    inline cdk::expression_node *expression(){
      return _expression; 
    }*/
    
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_index_node(this, level);
    }

  };

} // pwn

#endif
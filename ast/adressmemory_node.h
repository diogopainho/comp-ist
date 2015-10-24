// $Id: adressmemory_node.h,v 1.1 2015/03/23 23:44:45 ist173245 Exp $ -*- c++ -*-
#ifndef __PWN_ADRESSMEMORYNODE_H__
#define __PWN_ADRESSMEMORYNODE_H__

#include <cdk/ast/expression_node.h>
#include <cdk/ast/unary_expression_node.h>

namespace pwn {

  /**
   * Class for describing adress memory node.
   */
  class adressmemory_node: public cdk::unary_expression_node {
    cdk::expression_node *_expr;

  public:
    inline adressmemory_node(int lineno, cdk::expression_node *expr) :
        unary_expression_node(lineno, expr) {
    }

  public:
    inline cdk::expression_node *expr() {
      return _expr;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_adressmemory_node(this, level);
    }

  };

} // pwn

#endif
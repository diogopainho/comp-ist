// $Id: or_node.h,v 1.2 2015/05/18 19:42:56 ist173245 Exp $ -*- c++ -*-
#ifndef __PWN_ORNODE_H__
#define __PWN_ORNODE_H__

#include <cdk/ast/expression_node.h>
#include <cdk/ast/binary_expression_node.h>

namespace pwn {

  /**
   * Class for describing or node.
   */
  class or_node: public cdk::binary_expression_node {

  public:
    inline or_node(int lineno, cdk::expression_node *lexpr, cdk::expression_node *rexpr) :
        binary_expression_node(lineno, lexpr, rexpr) {
    }

  public:

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_or_node(this, level);
    }

  };

} // pwn

#endif
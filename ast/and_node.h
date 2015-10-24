// $Id: and_node.h,v 1.3 2015/05/18 19:42:49 ist173245 Exp $ -*- c++ -*-
#ifndef __PWN_ANDNODE_H__
#define __PWN_ANDNODE_H__

#include <cdk/ast/expression_node.h>
#include <cdk/ast/binary_expression_node.h>

namespace pwn {

  /**
   * Class for describing and node.
   */
  class and_node: public cdk::binary_expression_node {

  public:
    inline and_node(int lineno, cdk::expression_node *lexpr, cdk::expression_node *rexpr) :
        binary_expression_node(lineno, lexpr, rexpr) {
    }

  public:
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_and_node(this, level);
    }

  };

} // pwn

#endif
// $Id: not_node.h,v 1.1 2015/03/23 23:44:46 ist173245 Exp $ -*- c++ -*-
#ifndef __PWN_NOTNODE_H__
#define __PWN_NOTNODE_H__

#include <cdk/ast/expression_node.h>
#include <cdk/ast/binary_expression_node.h>

namespace pwn {

  /**
   * Class for describing not node.
   */
  class not_node: public cdk::unary_expression_node {
    cdk::expression_node *_rexpr;

  public:
    inline not_node(int lineno, cdk::expression_node *rexpr) :
        unary_expression_node(lineno, rexpr) {
    }

  public:
    inline cdk::expression_node *rexpr() {
      return _rexpr;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_not_node(this, level);
    }

  };

} // pwn

#endif
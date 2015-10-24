// $Id: next_node.h,v 1.1 2015/03/19 19:58:35 ist173245 Exp $ -*- c++ -*-
#ifndef __PWN_NEXTNODE_H__
#define __PWN_NEXTNODE_H__

#include <cdk/ast/integer_node.h>

namespace pwn {

  /**
   * Class for describing next node.
   */
  class next_node: public cdk::basic_node {
    cdk::integer_node *_nesimo;

  public:
    inline next_node(int lineno, cdk::integer_node *nesimo) :
        basic_node(lineno),_nesimo(nesimo) {
    }

  public:
    inline cdk::integer_node *nesimo() {
      return _nesimo;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_next_node(this, level);
    }

  };

} // pwn

#endif
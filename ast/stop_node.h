// $Id: stop_node.h,v 1.1 2015/03/19 19:58:35 ist173245 Exp $ -*- c++ -*-
#ifndef __PWN_STOPNODE_H__
#define __PWN_STOPNODE_H__

#include <cdk/ast/integer_node.h>

namespace pwn {

  /**
   * Class for describing stop node.
   */
  class stop_node: public cdk::basic_node {
    cdk::integer_node *_nesimo;

  public:
    inline stop_node(int lineno, cdk::integer_node *nesimo) :
        basic_node(lineno),_nesimo(nesimo) {
    }

  public:
    inline cdk::integer_node *nesimo() {
      return _nesimo;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_stop_node(this, level);
    }

  };

} // pwn

#endif
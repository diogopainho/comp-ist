// $Id: print_node.h,v 1.2 2015/05/16 18:32:12 ist173245 Exp $ -*- c++ -*-
#ifndef __PWN_PRINTNODE_H__
#define __PWN_PRINTNODE_H__

#include <cdk/ast/expression_node.h>

namespace pwn {

  /**
   * Class for describing print nodes.
   */
  class print_node: public cdk::basic_node {
    cdk::expression_node *_argument;
    bool _isnewline;

  public:
    inline print_node(int lineno, cdk::expression_node *argument, bool isnewline) :
        cdk::basic_node(lineno), _argument(argument), _isnewline(isnewline) {
    }

  public:
    inline cdk::expression_node *argument() {
      return _argument;
    }
    
    inline bool isnewline() {
      return _isnewline;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_print_node(this, level);
    }

  };

} // pwn

#endif

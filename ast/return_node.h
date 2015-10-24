// $Id: return_node.h,v 1.2 2015/03/24 17:02:07 ist173245 Exp $ -*- c++ -*-
#ifndef __PWN_RETURNNODE_H__
#define __PWN_RETURNNODE_H__

#include <cdk/ast/expression_node.h>

namespace pwn {

  /**
   * Class for describing noob node.
   */
  class return_node: public cdk::basic_node {

  public:
    inline return_node(int lineno) :
        basic_node(lineno) {
    }
    
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_return_node(this, level);
    }

  };

} // pwn

#endif
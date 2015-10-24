// $Id: noob_node.h,v 1.3 2015/03/25 09:41:01 ist173245 Exp $ -*- c++ -*-
#ifndef __PWN_NOOBNODE_H__
#define __PWN_NOOBNODE_H__

#include <cdk/ast/expression_node.h>

namespace pwn {

  /**
   * Class for describing noob node.
   */
  class noob_node: public cdk::expression_node {

  public:
    inline noob_node(int lineno) :
        expression_node(lineno) {
    }

  public:
    
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_noob_node(this, level);
    }

  };

} // pwn

#endif
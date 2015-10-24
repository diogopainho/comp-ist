// $Id: reservememory_node.h,v 1.2 2015/04/13 00:17:41 ist174117 Exp $ -*- c++ -*-
#ifndef __PWN_RESERVEMEMORYNODE_H__
#define __PWN_RESERVEMEMORYNODE_H__

#include "ast/rvalue_node.h"


namespace pwn {

  /**
   * Class for describing reserve memory node.
   */
  class reservememory_node: public cdk::unary_expression_node {
    cdk::expression_node *_rvalue;

  public:
    inline reservememory_node(int lineno, cdk::expression_node *rvalue) :
        unary_expression_node(lineno, _rvalue) {
    }

  public:
    inline cdk::expression_node *rvalue(){
      return _rvalue; 
    }
    
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_reservememory_node(this, level);
    }

  };

} // pwn

#endif
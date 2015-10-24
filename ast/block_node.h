#ifndef __PWN_BLOCKNODE_H__
#define __PWN_BLOCKNODE_H__

#include <cdk/ast/sequence_node.h>

namespace pwn {

  /**
   * Class for describing block node.
   */
  class block_node: public cdk::basic_node {
    cdk::sequence_node *_decs;
    cdk::sequence_node *_exprs;

  public:
    inline block_node(int lineno, cdk::sequence_node *decs, cdk::sequence_node *exprs ) :
        basic_node(lineno),_decs(decs), _exprs(exprs) {
    }

  public:
    inline cdk::sequence_node *decs() {
      return _decs;
    }
    
    inline cdk::sequence_node *exprs() {
      return _exprs;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_block_node(this, level);
    }

  };

} // pwn

#endif
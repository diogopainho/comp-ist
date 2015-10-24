#ifndef __PWN_FUNCCALLNODE_H__
#define __PWN_FUNCCALLNODE_H__

#include <cdk/ast/expression_node.h>
#include <cdk/ast/sequence_node.h>



namespace pwn {

  /**
   * Class for describing function-call node.
   */
  class funccall_node: public cdk::expression_node {
    std::string *_identifier;
    cdk::sequence_node *_args;

  public:
    inline funccall_node(int lineno,  std::string *identifier, cdk::sequence_node *args) :
        expression_node(lineno), _identifier(identifier), _args(args) {
    }

  public:
    inline std::string *identifier() {
      return _identifier;
    }

    inline cdk::sequence_node *args() {
      return _args;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_funccall_node(this, level);
    }

  };

} // pwn

#endif
// $Id: lvalue_node.h,v 1.4 2015/04/13 02:33:42 ist174117 Exp $
#ifndef __PWN_NODE_EXPRESSION_LEFTVALUE_H__
#define __PWN_NODE_EXPRESSION_LEFTVALUE_H__

#include <cdk/ast/expression_node.h>
#include <string>

namespace pwn {

  /**
   * Class for describing syntactic tree leaves for holding lvalues.
   */
  class lvalue_node: public cdk::expression_node {
    std::string *_identifier;
    
  public:
    inline lvalue_node(int lineno, std::string *identifier) :
        cdk::expression_node(lineno), _identifier(identifier) {
    }

  public:
    inline std::string *identifier() {
      return _identifier;
    }
    
    /**
     * @param sp semantic processor visitor
     * @param level syntactic tree level
     */
    virtual void accept(basic_ast_visitor *sp, int level) {
      sp->do_lvalue_node(this, level);
    }

  };

} // pwn

#endif

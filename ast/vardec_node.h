#ifndef __PWN_VARDECNODE_H__
#define __PWN_VARCDECNODE_H__

#include <cdk/ast/expression_node.h>
#include "lvalue_node.h"
#include <string.h>

namespace pwn {

  /**
   * Class for describing variable-declaration node.
   */
  class vardec_node: public cdk::basic_node {
    bool _isImport;
    bool _isLocal;
    bool _isConst;
    basic_type *_type;
    std::string *_identifier;
    cdk::expression_node *_expression;

  public:
    inline vardec_node(int lineno, bool isImport, bool isLocal, bool isConst, basic_type *type, std::string *identifier, cdk::expression_node *expression) :
        basic_node(lineno), _isImport(isImport), _isLocal(isLocal), _isConst(isConst), _type(type), _identifier(identifier), _expression(expression) {
    }
    
    inline vardec_node(int lineno, vardec_node *_variable, cdk::expression_node *expression) :
	basic_node(lineno), _isImport(_variable->isImport()), _isLocal(_variable->isLocal()),_isConst(_variable->isConst()), _type(_variable->type()), _identifier(_variable->identifier()), _expression(expression) {
    }
    
  public:
    inline bool isImport() {
      return _isImport; 
    }
    
    inline bool isLocal() {
      return _isLocal; 
    } 
    
    inline bool isConst() {
      return _isConst; 
    }
    
    inline basic_type *type() {
      return _type;
    }

    inline std::string *identifier() {
      return _identifier;
    }
    
    inline cdk::expression_node *expression() {
      return _expression;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_vardec_node(this, level);
    }
    
    pwn::lvalue_node *makeDeclLeftValue() {
      return new pwn::lvalue_node(lineno(), identifier());
    }
    
  };

} // pwn

#endif
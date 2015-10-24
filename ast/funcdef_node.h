#ifndef __PWN_FUNCDEFNODE_H__
#define __PWN_FUNCDEFNODE_H__

#include <cdk/ast/expression_node.h>
#include <cdk/ast/identifier_node.h>
#include <cdk/ast/integer_node.h>
#include <cdk/ast/sequence_node.h>
#include "ast/block_node.h"

namespace pwn {

  /**
   * Class for describing function-defenition node.
   */
  class funcdef_node: public cdk::basic_node {
    bool _isImport;  
    bool _isLocal; 
    basic_type *_type;
    std::string *_identifier;
    cdk::sequence_node *_args;
    cdk::expression_node *_literal;
    pwn::block_node *_block;

  public:
    inline funcdef_node(int lineno, bool isImport, bool isLocal, basic_type *type, std::string *identifier, cdk::sequence_node *args, cdk::expression_node *literal,  pwn::block_node *block) :
        basic_node(lineno), _isImport(isImport), _isLocal(isLocal), _type(type), _identifier(identifier), _args(args), _literal(literal), _block(block) {
    }
    
  public:
    inline bool isImport() {
      return _isImport; 
    }
    
    inline bool isLocal() {
      return _isLocal; 
    }  
    
    inline basic_type *type() {
      return _type;
    }

    inline std::string *identifier() {
      return _identifier;
    }

    inline cdk::expression_node *literal() {
      return _literal;
    }
    
    inline cdk::sequence_node *args() {
      return _args;
    }
    
    inline pwn::block_node *block() {
      return _block;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_funcdef_node(this, level);
    }

  };

} // pwn

#endif
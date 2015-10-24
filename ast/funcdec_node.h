#ifndef __PWN_FUNCDECNODE_H__
#define __PWN_FUNCDECNODE_H__

#include <cdk/ast/expression_node.h>
#include <cdk/ast/identifier_node.h>
#include <cdk/ast/integer_node.h>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/basic_node.h>

namespace pwn {

  /**
   * Class for describing function-declaration node.
   */
  class funcdec_node: public cdk::basic_node {
    bool _isImport;  
    bool _isLocal; 
    basic_type *_type;
    std::string *_identifier;
    cdk::sequence_node *_args;

  public:
    inline funcdec_node(int lineno, bool isImport, bool isLocal, basic_type *type, std::string *identifier, cdk::sequence_node *args) :
        basic_node(lineno), _isImport(isImport), _isLocal(isLocal), _type(type), _identifier(identifier), _args(args) {
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
    
    inline cdk::sequence_node *args() {
      return _args;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_funcdec_node(this, level);
    }

  };

} // pwn

#endif
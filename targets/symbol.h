// $Id: symbol.h,v 1.3 2015/05/19 23:10:05 ist174117 Exp $ -*- c++ -*-
#ifndef __PWN_SEMANTICS_SYMBOL_H__
#define __PWN_SEMANTICS_SYMBOL_H__

#include <string>
#include <cdk/basic_type.h>

namespace pwn {

    class symbol {
      basic_type *_type;
      std::string _name;
      long _value; // hack!
      std::vector<basic_type*> _funcargs;

    public:
      inline symbol(basic_type *type, const std::string &name, long value) :
          _type(type), _name(name), _value(value) {
      }

      virtual ~symbol() {
        delete _type;
      }

      inline basic_type *type() const {
        return _type;
      }
      inline const std::string &name() const {
        return _name;
      }
      inline long value() const {
        return _value;
      }
      inline long value(long v) {
        return _value = v;
      }
      
      inline basic_type *getarg(size_t i) {
	return _funcargs[i];
      }
      
      inline std::vector<basic_type*> funcargs() const {
	return _funcargs;
      }
      
      inline size_t num_args() const {
	return _funcargs.size();
      }
      
      //construtor
      inline void funcargs(std::vector<basic_type*> args){
	for(size_t s = 0; s < args.size(); s++){
	  _funcargs.push_back(args[s]);
	}
      }
      
    };

} // pwn

#endif

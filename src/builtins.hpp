#pragma once
#include "object.hpp"

Object* built_in_len(std::vector<Object*>, std::shared_ptr<Environment>);
Object* built_in_print(std::vector<Object*>, std::shared_ptr<Environment>);
Object* newError(std::string);


typedef struct Builtin : Object {
  int function_type;
  int builtin_type;

  Builtin() {
    this->type = BUILTIN_OBJ;
    this->function_type = builtinFunction;
  }

  inline std::string inspectType() { return ObjectType.BUILTIN_OBJ; };
  inline std::string inspectObject() { return "builtin function"; };
} Builtin;


enum BuiltinFunctions {
  len,
  print,
};


const std::unordered_map<std::string, int> builtins {
  {"len", len},
  {"print", print}
};

#pragma once
#include <string>


enum ObjectEnum {
    INTEGER_OBJ,
    BOOLEAN_TRUE,
    BOOLEAN_FALSE,
    STRING_OBJ,
    IDENT_OBJ,
    FLOAT_OBJ,
    NULL_OBJ,
};

const struct Objecttype {
    std::string INTEGER_OBJ = {"INTEGER"};
    std::string BOOLEAN_OBJ = {"BOOLEAN"};
    std::string STRING_OBJ = {"STRING"};
    std::string IDENT_OBJ = {"IDENT"};
    std::string FLOAT_OBJ = {"FLOAT"};
    std::string NULL_OBJ = {"NULL"};
} ObjectType;


typedef struct Object {
    int type;

    virtual ~Object() = default;

    virtual std::string inspectObject();
    virtual std::string inspectType();
} Object;


typedef struct Integer : Object {
    int value;

    Integer(int v) {
        this->value = v;
        this->type = INTEGER_OBJ;
    }

    inline std::string inspectObject() { return std::to_string(this->value); }
    inline std::string inspectType() { return ObjectType.INTEGER_OBJ; }
} Integer;


typedef struct Boolean : Object {
    bool value;

    Boolean(bool b) {
        this->value = b;
        if (b) { this->type = BOOLEAN_TRUE; }
        else { this->type = BOOLEAN_FALSE; }
    }

    inline std::string inspectObject() { return this->value ? "true" : "false"; }
    inline std::string inspectType() { return ObjectType.BOOLEAN_OBJ; }
} Boolean;


typedef struct Float : Object {
    float value;

    Float(float b) {
        this->value = b;
        this->type = FLOAT_OBJ;
    }

    inline std::string inspectObject() { return std::to_string(this->value); }
    inline std::string inspectType() { return ObjectType.FLOAT_OBJ; }
} Float;


typedef struct String : Object {
    std::string value;

    String(std::string b) {
        this->value = b;
        this->type = STRING_OBJ;
    }

    inline std::string inspectObject() { return this->value; }
    inline std::string inspectType() { return ObjectType.STRING_OBJ; }
} String;


typedef struct Null : Object {

    Null() { this->type = NULL_OBJ; }

    inline std::string inspectObject() { return "null"; }
    inline std::string inspectType() { return ObjectType.NULL_OBJ; }
} Null;

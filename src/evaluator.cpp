#include "ast.hpp"
#include "object.hpp"

using namespace std;

// GLOBALS
Boolean _TRUE_BOOL = Boolean(true);
Boolean _FALSE_BOOL = Boolean(false);
Null _NULL = Null{};

// FORWARD DECLARATIONS
shared_ptr<Boolean> nativeToBoolean(bool);
shared_ptr<Object> evalPrefixExpression(string, shared_ptr<Object>);
shared_ptr<Object> evalBangOperatorExpression(shared_ptr<Object>);
shared_ptr<Object> evalMinusOperatorExpression(shared_ptr<Object>);

// MAIN
// Object* evalNode(Node* node) {
shared_ptr<Object> evalNode(Node* node) {
    if (node->nodetype == statement) {
        Statement* stmt = static_cast<Statement*>(node);
        switch (stmt->type) {
            case identifierStatement:{
                break;
            }
            case functionStatement: {
                break;
            }
            case letStatement: {
                break;
            }
            case returnStatement: {
                break;
            }
            case expressionStatement: {
                ExpressionStatement* es = static_cast<ExpressionStatement*>(stmt);
                return evalNode(es->expression);
            }
            case blockStatement: {
                break;
            }
        }
    }
    else {
        Expression* expr = static_cast<Expression*>(node);
        switch (expr->type) {
            case integerLiteral: {
                IntegerLiteral* i = static_cast<IntegerLiteral*>(expr);
                shared_ptr<Object> newi = make_shared<Object>(new Integer(i->value));
                return newi;
            }   
            case floatLiteral: {
                FloatLiteral* f = static_cast<FloatLiteral*>(expr);
                shared_ptr<Object> newf = make_shared<Object>(new Float(f->value));
                return newf;
            }   
            case booleanExpression: {
                BooleanLiteral* b = static_cast<BooleanLiteral*>(expr);
                return static_pointer_cast<Object>(nativeToBoolean(b->value));

                // return nativeToBoolean(b->value);
            }   
            case stringLiteral: {
                StringLiteral* s = static_cast<StringLiteral*>(expr);
                shared_ptr<Object> news = make_shared<Object>(new String(s->value));
                return news;
            }   
            case identifier: {
            //     IdentifierLiteral* b = static_cast<IdentifierLiteral*>(expr);
            //     break;
            //     // return new Identifier(b->value);
            }   
            case prefixExpression: {
                PrefixExpression* p = static_cast<PrefixExpression*>(expr);
                shared_ptr<Object> right = evalNode(p->_right);
                return static_pointer_cast<Object>(evalPrefixExpression(p->_operator, right));
                // BooleanLiteral* b = static_cast<BooleanLiteral*>(expr);
                // break;
                // return new Boolean(b->value);
            }   
            case infixExpression: {
                // BooleanLiteral* b = static_cast<BooleanLiteral*>(expr);
                // break;
                // return Boolean(b->value);
            }   
            case ifExpression: {
                // BooleanLiteral* b = static_cast<BooleanLiteral*>(expr);
                // break;
                // return Boolean(b->value);
            }   
            case functionLiteral: {
                // BooleanLiteral* b = static_cast<BooleanLiteral*>(expr);
                // break;
                // return Boolean(b->value);
            }   
            case callExpression: {
                // BooleanLiteral* b = static_cast<BooleanLiteral*>(expr);
                // break;
                // return Boolean(b->value);
            }   
            case groupedExpression: {
                // BooleanLiteral* b = static_cast<BooleanLiteral*>(expr);
                // break;
                // return Boolean(b->value);
            }   
        }
    }
}


shared_ptr<Object> evalPrefixExpression(string _operator, shared_ptr<Object> _right) {
    switch(_operator[0]) {
        case '!':
            return evalBangOperatorExpression(_right);
        case '-':
            return evalMinusOperatorExpression(_right);
        default:
            return NULL;
    }
}


shared_ptr<Object> evalBangOperatorExpression(shared_ptr<Object> _right) {
    switch (_right->type) {
        case BOOLEAN_TRUE:
            return make_shared<Object>(&_FALSE_BOOL);
        case BOOLEAN_FALSE:
            return make_shared<Object>(&_TRUE_BOOL);
        case NULL_OBJ:
            return make_shared<Object>(&_TRUE_BOOL);
        default:
            return make_shared<Object>(&_FALSE_BOOL);
    }
}


shared_ptr<Object> evalMinusOperatorExpression(shared_ptr<Object> _right) {
    if (_right->inspectType() != ObjectType.INTEGER_OBJ) {
        return NULL;
    }
    shared_ptr<Integer> i = static_pointer_cast<Integer>(_right);
    shared_ptr<Object> newInt = make_shared<Object>(new Integer(-i->value));
    return newInt;
}


shared_ptr<Boolean> nativeToBoolean(bool input) {
    if (input) {
        shared_ptr<Boolean> b = make_shared<Boolean>(&_TRUE_BOOL);
        return b;
    }
    shared_ptr<Boolean> b = make_shared<Boolean>(&_FALSE_BOOL);
    return b;
}

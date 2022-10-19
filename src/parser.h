#pragma once
#include "lexer.h"
#include <vector>

struct Expression;
struct IntegerLiteral;
struct StringLiteral;
struct Identifier;
struct Statement;
struct LetStatement;
struct ReturnStatement;
struct ExpressionStatement;

class Parser {
    public:
        Lexer* lexer;
        Token currentToken;
        Token peekToken;

        std::vector<std::string> errors;

        Parser(std::string input) {
            this->lexer = new Lexer(input);
            this->nextToken();
            this->nextToken();
        }

        ~Parser() {
            delete this->lexer;
        }

        void nextToken();
        bool expectPeek(std::string);
        void peekErrors(std::string);

        Identifier* parseIdentifier();
        Expression* parseExpression();
        IntegerLiteral* parseIntegerLiteral();
        StringLiteral* parseStringLiteral();
        Statement* parseStatement();
        LetStatement* parseLetStatement();
        ReturnStatement* parseReturnStatement();
        ExpressionStatement* parseExpressionStatement();
};
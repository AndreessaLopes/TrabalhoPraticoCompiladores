#ifndef ANALISESINTATICA_H
#define ANALISESINTATICA_H

#include "AnaliseLexica.h"

class AnaliseSintatica
{
public:
    AnaliseSintatica(AnaliseLexica& lex);
    void analisar(); // ponto de entrada

private:
    AnaliseLexica& lexico;
    TokenEncontrado tokenAtual;

    void avancar();
    void erro(const std::string& esperado);

    // Não-terminais da gramática X++
    void program();
    void classList();
    void classDecl();
    void classBody();

    void varDecl();
    void constructorDecl();
    void methodDecl();
    void methodBody();

    void statement();
    void statList();

    void atribStat();
    void printStat();
    void readStat();
    void returnStat();
    void ifStat();
    void forStat();

    void expression();
    void numExpr();
    void term();
    void unaryExpr();
    void factor();
};

#endif

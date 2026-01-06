/*
   Nomes:
   Andressa Caroline Lopes de Assis - RA: 0072749 - Código de Análise Léxica Completa, pesquisas, etc
   Bruno Augusto de Oliveira - RA: 0073211 - Código de Análise Sintática Completa, pesquisas, etc
*/

#include "AnaliseSintatica.h"
#include <iostream>
#include <cstdlib>

using namespace std;

AnaliseSintatica::AnaliseSintatica(AnaliseLexica& lex)
    : lexico(lex)
{
    tokenAtual = lexico.proximoToken();
}

void AnaliseSintatica::avancar()
{
    tokenAtual = lexico.proximoToken();
}

void AnaliseSintatica::erro(const string& esperado)
{
    cout << "Erro sintático na linha " << tokenAtual.linha
         << ". Esperado: " << esperado
         << ", encontrado: " << tokenAtual.t.key << endl;
    exit(1);
}

void AnaliseSintatica::analisar()
{
    program();

    if (tokenAtual.t.key != "EOF")
    {
        erro("EOF");
    }

    cout << "Análise sintática concluída com sucesso." << endl;
}

void AnaliseSintatica::program()
{
    classList();
}

void AnaliseSintatica::classList()
{
    while (tokenAtual.t.key == "class")
    {
        classDecl();
    }
}



void AnaliseSintatica::classDecl()
{
    if (tokenAtual.t.key != "class")
        erro("class");

    avancar();

    if (tokenAtual.t.key != "ID")
        erro("identificador da classe");

    avancar();

    // extends opcional
    if (tokenAtual.t.key == "extends")
    {
        avancar();
        if (tokenAtual.t.key != "ID")
            erro("identificador da superclasse");
        avancar();
    }

    classBody();
}


void AnaliseSintatica::printStat()
{
    if (tokenAtual.t.key != "print")
        erro("print");

    avancar();
    expression();
}

void AnaliseSintatica::readStat()
{
    if (tokenAtual.t.key != "read")
        erro("read");

    avancar();

    if (tokenAtual.t.key != "ID")
        erro("identificador");

    avancar();
}

void AnaliseSintatica::returnStat()
{
    if (tokenAtual.t.key != "return")
        erro("return");

    avancar();
    expression();
}

void AnaliseSintatica::ifStat()
{
    if (tokenAtual.t.key != "if")
        erro("if");

    avancar();

    if (tokenAtual.t.key != "(")
        erro("(");

    avancar();
    expression();

    if (tokenAtual.t.key != ")")
        erro(")");

    avancar();
    statement();

    if (tokenAtual.t.key == "else")
    {
        avancar();
        statement();
    }
}

void AnaliseSintatica::forStat()
{
    if (tokenAtual.t.key != "for")
        erro("for");

    avancar();

    if (tokenAtual.t.key != "(")
        erro("(");
    avancar();

    // atribstat opcional
    if (tokenAtual.t.key != ";")
        atribStat();

    if (tokenAtual.t.key != ";")
        erro(";");
    avancar();

    // expression opcional
    if (tokenAtual.t.key != ";")
        expression();

    if (tokenAtual.t.key != ";")
        erro(";");
    avancar();

    // atribstat opcional
    if (tokenAtual.t.key != ")")
        atribStat();

    if (tokenAtual.t.key != ")")
        erro(")");
    avancar();

    statement();
}




void AnaliseSintatica::classBody()
{
    if (tokenAtual.t.key != "{")
        erro("{");

    avancar();

    // declarações de variáveis
    while (tokenAtual.t.key == "int" || tokenAtual.t.key == "string")
    {
        varDecl();

        if (tokenAtual.t.key != ";")
            erro(";");

        avancar();
    }

    // construtor
    if (tokenAtual.t.key == "constructor")
    {
        constructorDecl();
    }

    // métodos
    while (tokenAtual.t.key == "int" ||
            tokenAtual.t.key == "string" ||
            tokenAtual.t.key == "ID")
    {
        methodDecl();
    }

    if (tokenAtual.t.key != "}")
        erro("}");

    avancar();
}

void AnaliseSintatica::varDecl()
{
    // tipo
    if (tokenAtual.t.key != "int" &&
            tokenAtual.t.key != "string" &&
            tokenAtual.t.key != "ID")
        erro("tipo");

    avancar();

    // nome da variável
    if (tokenAtual.t.key != "ID")
        erro("identificador");

    avancar();

    // vetores []
    while (tokenAtual.t.key == "[")
    {
        avancar();
        if (tokenAtual.t.key != "]")
            erro("]");
        avancar();
    }
}

void AnaliseSintatica::constructorDecl()
{
    if (tokenAtual.t.key != "constructor")
        erro("constructor");

    avancar();
    methodBody();
}

void AnaliseSintatica::methodDecl()
{
    // tipo de retorno
    if (tokenAtual.t.key != "int" &&
        tokenAtual.t.key != "string" &&
        tokenAtual.t.key != "ID")
        erro("tipo de retorno do método");

    avancar(); // consome tipo

    // nome do método
    if (tokenAtual.t.key != "ID")
        erro("identificador do método");

    avancar(); // consome nome

    methodBody();
}


void AnaliseSintatica::methodBody()
{
    if (tokenAtual.t.key != "(")
        erro("(");

    avancar();

    if (tokenAtual.t.key != ")")
        erro(")");

    avancar();

    statement();
}

void AnaliseSintatica::statement()
{
    // bloco
    if (tokenAtual.t.key == "{")
    {
        avancar();
        statList();

        if (tokenAtual.t.key != "}")
            erro("}");

        avancar();

        return;
    }

    // declaração de variável
    if (tokenAtual.t.key == "int" || tokenAtual.t.key == "string")
    {
        varDecl();
        if (tokenAtual.t.key != ";")
            erro(";");
        avancar();
        return;
    }

    // atribuição
    if (tokenAtual.t.key == "ID")
    {
        atribStat();
        if (tokenAtual.t.key != ";")
            erro(";");
        avancar();
        return;
    }

    // print
    if (tokenAtual.t.key == "print")
    {
        printStat();
        if (tokenAtual.t.key != ";")
            erro(";");
        avancar();
        return;
    }

    // read
    if (tokenAtual.t.key == "read")
    {
        readStat();
        if (tokenAtual.t.key != ";")
            erro(";");
        avancar();
        return;
    }

    // return
    if (tokenAtual.t.key == "return")
    {
        returnStat();
        if (tokenAtual.t.key != ";")
            erro(";");
        avancar();
        return;
    }

    // if
    if (tokenAtual.t.key == "if")
    {
        ifStat();
        return;
    }

    // for
    if (tokenAtual.t.key == "for")
    {
        forStat();
        return;
    }

    // break
    if (tokenAtual.t.key == "break")
    {
        avancar();
        if (tokenAtual.t.key != ";")
            erro(";");
        avancar();
        return;
    }

    // comando vazio
    if (tokenAtual.t.key == ";")
    {
        avancar();
        return;
    }

    erro("statement");
}


void AnaliseSintatica::statList()
{
    while (tokenAtual.t.key != "}" &&
            tokenAtual.t.key != "EOF")
    {
        statement();
    }
}


void AnaliseSintatica::atribStat()
{
    if (tokenAtual.t.key != "ID")
        erro("identificador");

    avancar();

    if (tokenAtual.t.key != "=")
        erro("=");

    avancar();

    expression();
}

void AnaliseSintatica::expression()
{
    numExpr();

    if (tokenAtual.t.key == "==" ||
            tokenAtual.t.key == "!=" ||
            tokenAtual.t.key == "<" ||
            tokenAtual.t.key == ">" ||
            tokenAtual.t.key == "<=" ||
            tokenAtual.t.key == ">=")
    {

        avancar();
        numExpr();
    }
}

void AnaliseSintatica::numExpr()
{
    term();

    while (tokenAtual.t.key == "+" || tokenAtual.t.key == "-")
    {
        avancar();
        term();
    }
}

void AnaliseSintatica::term()
{
    unaryExpr();

    while (tokenAtual.t.key == "*" ||
            tokenAtual.t.key == "/" ||
            tokenAtual.t.key == "%")
    {
        avancar();
        unaryExpr();
    }
}

void AnaliseSintatica::unaryExpr()
{
    if (tokenAtual.t.key == "+" || tokenAtual.t.key == "-")
    {
        avancar();
    }
    factor();
}

void AnaliseSintatica::factor()
{
    if (tokenAtual.t.key == "NUM" ||
            tokenAtual.t.key == "LITERAL" ||
            tokenAtual.t.key == "null")
    {
        avancar();
        return;
    }

    if (tokenAtual.t.key == "ID")
    {
        avancar();
        return;
    }

    if (tokenAtual.t.key == "(")
    {
        avancar();
        expression();
        if (tokenAtual.t.key != ")")
            erro(")");
        avancar();
        return;
    }

    erro("fator");
}

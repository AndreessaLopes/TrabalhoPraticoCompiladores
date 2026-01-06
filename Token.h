/*
   Nomes:
   Andressa Caroline Lopes de Assis - RA: 0072749 - Código de Análise Léxica Completa, pesquisas, etc
   Bruno Augusto de Oliveira - RA: 0073211 - Código de Análise Sintática Completa, pesquisas, etc
*/

#ifndef TOKEN_H
#define TOKEN_H

#include <string>

struct Token {
    int id;
    std::string key;
    std::string desc;
};

struct TokenEncontrado {
    Token t;               // tipo do token
    std::string encontrado; // lexema
    int linha;              // linha no código fonte
};

#endif

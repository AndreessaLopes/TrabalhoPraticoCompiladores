/*
   Nomes:
   Andressa Caroline Lopes de Assis - RA: 0072749 - Código de Análise Léxica Completa, pesquisas, etc
   Bruno Augusto de Oliveira - RA: 0073211 - Código de Análise Sintática Completa, pesquisas, etc
*/

#ifndef ANALISELEXICA_H
#define ANALISELEXICA_H

#include <string>
#include <vector>
#include <fstream>
#include "Token.h"

class AnaliseLexica
{
public:
    AnaliseLexica(std::string nomeArquivo);
    ~AnaliseLexica();

    bool abrirArquivo();
    void carregarDicionarioDeTokens();
    TokenEncontrado proximoToken();

private:
    Token getTokenPelaChave(std::string chave);
    TokenEncontrado criarToken(std::string chave, std::string lexema);

    std::vector<Token> tokens;
    std::ifstream arquivo;
    std::string nomeArquivo;
    int linha;

    void getChar();
    TokenEncontrado lerIdentificador();
    TokenEncontrado lerNumero();
    TokenEncontrado lerLiteral();
    TokenEncontrado lerSimbolo();

    char car;
    std::string lexema;
};

#endif

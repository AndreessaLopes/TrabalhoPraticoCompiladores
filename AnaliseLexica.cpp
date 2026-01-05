#include "AnaliseLexica.h"
#include <cctype>

using namespace std;

/* ================= CONSTRUTOR ================= */

AnaliseLexica::AnaliseLexica(string nomeArquivo)
    : nomeArquivo(nomeArquivo),
      linha(1),
      car('\0')
{
}

/* ================= DESTRUTOR ================= */

AnaliseLexica::~AnaliseLexica()
{
    if (arquivo.is_open())
        arquivo.close();
}

/* ================= ARQUIVO ================= */

bool AnaliseLexica::abrirArquivo()
{
    arquivo.open(nomeArquivo);
    return arquivo.is_open();
}

/* ================= DICIONÁRIO ================= */

void AnaliseLexica::carregarDicionarioDeTokens()
{
    tokens.clear();

    vector<string> classes =
    {
        // Palavras reservadas da X++
        "class", "extends",
        "int", "string",
        "constructor",
        "if", "else",
        "for", "return",
        "break",
        "print", "read",
        "super", "new",
        "null",

        // Identificadores e constantes
        "ID", "NUM", "LITERAL",

        // Operadores
        "+", "-", "*", "/", "%",
        "=", "==", "!=", "<", ">", "<=", ">=",

        // Delimitadores
        ";", ",", ".", "(", ")", "{", "}", "[", "]",

        // Controle
        "EOF", "ERRO"
    };

    int id = 1;
    for (auto &c : classes)
    {
        Token t;
        t.id = id++;
        t.key = c;
        t.desc = c;
        tokens.push_back(t);
    }
}

/* ================= AUXILIARES ================= */

void AnaliseLexica::getChar()
{
    int c = arquivo.get();
    if (c == EOF)
    {
        car = '\0';
    }
    else
    {
        car = static_cast<char>(c);
        if (car == '\n')
            linha++;
    }
}

Token AnaliseLexica::getTokenPelaChave(string chave)
{
    for (auto &t : tokens)
        if (t.key == chave)
            return t;

    Token erro;
    erro.id = -1;
    erro.key = "ERRO";
    erro.desc = "Token inválido";
    return erro;
}

TokenEncontrado AnaliseLexica::criarToken(string chave, string lexema)
{
    TokenEncontrado te;
    te.t = getTokenPelaChave(chave);
    te.encontrado = lexema;
    te.linha = linha;
    return te;
}

/* ================= LEITURAS ================= */

TokenEncontrado AnaliseLexica::lerIdentificador()
{
    lexema.clear();

    while (isalnum(car) || car == '_')
    {
        lexema.push_back(car);
        getChar();
    }

    arquivo.unget();

    // Verifica se o lexema é palavra reservada
    Token reservado = getTokenPelaChave(lexema);
    if (reservado.id != -1)
    {
        return criarToken(lexema, lexema);
    }

    return criarToken("ID", lexema);
}

TokenEncontrado AnaliseLexica::lerNumero()
{
    lexema.clear();

    while (isdigit(car))
    {
        lexema.push_back(car);
        getChar();
    }

    arquivo.unget();
    return criarToken("NUM", lexema);
}

TokenEncontrado AnaliseLexica::lerLiteral()
{
    lexema.clear();
    getChar(); // pula "

    while (car != '"' && car != '\0')
    {
        lexema.push_back(car);
        getChar();
    }

    if (car == '\0')
    {
        return criarToken("ERRO", "Literal não finalizado: " + lexema);
    }

    return criarToken("LITERAL", lexema);
}

TokenEncontrado AnaliseLexica::lerSimbolo()
{
    string s(1, car);

    getChar();

    // Operadores compostos
    if (s == "<" && car == '>') return criarToken("<>", "<>");
    if (s == "=" && car == '=') return criarToken("==", "==");
    if (s == "<" && car == '=') return criarToken("<=", "<=");
    if (s == ">" && car == '=') return criarToken(">=", ">=");
    if (s == "!" && car == '=') return criarToken("!=", "!=");


    arquivo.unget();

    // Símbolos válidos
    if (s == "+" || s == "-" || s == "*" || s == "/" ||
            s == "=" || s == "<" || s == ">" ||
            s == ";" || s == "," ||
            s == "(" || s == ")" ||
            s == "{" || s == "}")
    {
        return criarToken(s, s);
    }

    // ❌ ERRO LÉXICO
    return criarToken("ERRO", s);
}

/* ================= TOKEN PRINCIPAL ================= */

TokenEncontrado AnaliseLexica::proximoToken()
{
    while (true)
    {
        getChar();

        if (car == ' ' || car == '\t' || car == '\n')
            continue;

        if (car == '\0')
            return criarToken("EOF", "EOF");

        if (isalpha(car) || car == '_')
            return lerIdentificador();

        if (isdigit(car))
            return lerNumero();

        if (car == '"')
            return lerLiteral();

        return lerSimbolo();
    }
}

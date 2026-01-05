#include <iostream>
#include <clocale>
#include<locale>
#include "AnaliseLexica.h"
#include "AnaliseSintatica.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "pt-BR.UTF-8");
    AnaliseLexica lex("erro_lexico1.xpp");

    if (!lex.abrirArquivo()) {
        cout << "Erro ao abrir o arquivo fonte." << endl;
        return 1;
    }

    lex.carregarDicionarioDeTokens();

    AnaliseSintatica sintatico(lex);
    sintatico.analisar();

    return 0;
}

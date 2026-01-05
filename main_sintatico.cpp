#include <iostream>
#include <clocale>
#include <locale>
#include "AnaliseLexica.h"
#include "AnaliseSintatica.h"

using namespace std;

int main(int argc, char* argv[]) {

    setlocale(LC_ALL, "pt_BR.UTF-8");

    if (argc < 2) {
        cout << "Uso: ./sintatico <arquivo.xpp>" << endl;
        return 1;
    }

    AnaliseLexica lex(argv[1]);

    if (!lex.abrirArquivo()) {
        cout << "Erro ao abrir o arquivo fonte: " << argv[1] << endl;
        return 1;
    }

    lex.carregarDicionarioDeTokens();

    AnaliseSintatica sintatico(lex);
    sintatico.analisar();

    return 0;
}

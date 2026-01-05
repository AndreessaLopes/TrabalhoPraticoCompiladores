#include <iostream>
#include <locale>
#include <clocale>
#include "AnaliseLexica.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "pt-BR.UTF-8");
    AnaliseLexica lex("erro_lexico1.xpp");

    if (!lex.abrirArquivo()) {
        cout << "Erro ao abrir o arquivo fonte." << endl;
        return 1;
    }

    lex.carregarDicionarioDeTokens();

    TokenEncontrado tk;

    do {
        tk = lex.proximoToken();

        cout << "Linha: " << tk.linha
             << " | Token: " << tk.t.key
             << " | Lexema: " << tk.encontrado << endl;

        if (tk.t.key == "ERRO") {
            cout << ">>> ERRO LÉXICO DETECTADO <<<" << endl;
        }

    } while (tk.t.key != "EOF");

    return 0;
}

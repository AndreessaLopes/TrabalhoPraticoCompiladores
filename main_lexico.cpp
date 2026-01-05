#include <iostream>
#include <clocale>
#include <locale>
#include "AnaliseLexica.h"

using namespace std;

int main(int argc, char* argv[]) {

    setlocale(LC_ALL, "pt_BR.UTF-8");

    if (argc < 2) {
        cout << "Uso: ./lexico <arquivo.xpp>" << endl;
        return 1;
    }

    AnaliseLexica lex(argv[1]);

    if (!lex.abrirArquivo()) {
        cout << "Erro ao abrir o arquivo fonte: " << argv[1] << endl;
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
            break;
        }

    } while (tk.t.key != "EOF");

    return 0;
}

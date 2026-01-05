# =====================================
# Makefile - Compiladores (X++)
# Autores: Andressa Caroline Lopes de Assis
#          Bruno Augusto de Oliveira
# =====================================

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# ======================
# Executáveis
# ======================
LEXICO = lexico
SINTATICO = sintatico

# ======================
# Diretórios
# ======================
TESTES_DIR = testes

# ======================
# Arquivos
# ======================
LEXICO_SRC = main_lexico.cpp AnaliseLexica.cpp
SINTATICO_SRC = main_sintatico.cpp AnaliseLexica.cpp AnaliseSintatica.cpp

HEADERS = AnaliseLexica.h AnaliseSintatica.h Token.h

# ======================
# Regras principais
# ======================

all: $(LEXICO) $(SINTATICO)

# Compila o analisador léxico
$(LEXICO): $(LEXICO_SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(LEXICO_SRC) -o $(LEXICO)

# Compila o analisador sintático
$(SINTATICO): $(SINTATICO_SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SINTATICO_SRC) -o $(SINTATICO)

# ======================
# Execução
# ======================

run-lexico: $(LEXICO)
	./$(LEXICO) $(TESTES_DIR)/teste.xpp

run-sintatico: $(SINTATICO)
	./$(SINTATICO) $(TESTES_DIR)/teste.xpp

# ======================
# Limpeza
# ======================

clean:
	rm -f $(LEXICO) $(SINTATICO)

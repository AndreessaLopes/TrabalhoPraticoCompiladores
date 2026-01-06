# =====================================
# Makefile - Compiladores (X++)
# Autores:
#	Andressa Caroline Lopes de Assis - RA: 0072749 - C�digo de An�lise L�xica Completa, pesquisas, etc
#   Bruno Augusto de Oliveira - RA: 0073211 - C�digo de An�lise Sint�tica Completa, pesquisas, etc
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

# Arquivo de teste padrão (pode sobrescrever na linha de comando)
ARQ ?= teste.xpp

# ======================
# Arquivos fonte
# ======================
LEXICO_SRC = main_lexico.cpp AnaliseLexica.cpp
SINTATICO_SRC = main_sintatico.cpp AnaliseLexica.cpp AnaliseSintatica.cpp

HEADERS = AnaliseLexica.h AnaliseSintatica.h Token.h

# ======================
# Regras principais
# ======================

all: $(LEXICO) $(SINTATICO)

# ======================
# Compilação
# ======================

$(LEXICO): $(LEXICO_SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(LEXICO_SRC) -o $(LEXICO)

$(SINTATICO): $(SINTATICO_SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SINTATICO_SRC) -o $(SINTATICO)

# ======================
# Execução
# ======================

run-lexico: $(LEXICO)
	./$(LEXICO) $(TESTES_DIR)/$(ARQ)

run-sintatico: $(SINTATICO)
	./$(SINTATICO) $(TESTES_DIR)/$(ARQ)

# ======================
# Limpeza
# ======================

clean:
	del /Q $(LEXICO).exe $(SINTATICO).exe 2>nul || rm -f $(LEXICO) $(SINTATICO)

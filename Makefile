# ==========================================================
# Makefile – Trabalho Prático de Compiladores (X++)
#
# Autores:
#   Andressa Caroline Lopes de Assis – RA: 0072749
#     • Implementação da Análise Léxica
#
#   Bruno Augusto de Oliveira – RA: 0073211
#     • Implementação da Análise Sintática
# ==========================================================

# ----------------------------------------------------------
# Compilador e flags
# ----------------------------------------------------------
CXX      = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# ----------------------------------------------------------
# Executáveis
# ----------------------------------------------------------
LEXICO     = lexico
SINTATICO  = sintatico

# ----------------------------------------------------------
# Diretórios
# ----------------------------------------------------------
TESTES_DIR = testes

# Arquivo padrão (caso não seja informado)
ARQ ?= teste_lexico_valido.xpp

# ----------------------------------------------------------
# Arquivos fonte
# ----------------------------------------------------------
LEXICO_SRC    = main_lexico.cpp AnaliseLexica.cpp
SINTATICO_SRC = main_sintatico.cpp AnaliseLexica.cpp AnaliseSintatica.cpp

HEADERS = AnaliseLexica.h AnaliseSintatica.h Token.h

# ----------------------------------------------------------
# Regras principais
# ----------------------------------------------------------
all: $(LEXICO) $(SINTATICO)

# ----------------------------------------------------------
# Compilação
# ----------------------------------------------------------
$(LEXICO): $(LEXICO_SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(LEXICO_SRC) -o $(LEXICO)

$(SINTATICO): $(SINTATICO_SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SINTATICO_SRC) -o $(SINTATICO)

# ----------------------------------------------------------
# Execução genérica
# ----------------------------------------------------------
run-lexico: $(LEXICO)
	./$(LEXICO) $(TESTES_DIR)/$(ARQ)

run-sintatico: $(SINTATICO)
	./$(SINTATICO) $(TESTES_DIR)/$(ARQ)

# ----------------------------------------------------------
# Testes Léxicos
# ----------------------------------------------------------
lexico-valido:
	$(MAKE) run-lexico ARQ=teste_lexico_valido.xpp

lexico-erro-string:
	$(MAKE) run-lexico ARQ=erro_lexico_string.xpp

lexico-erro-simbolo:
	$(MAKE) run-lexico ARQ=erro_lexico_simbolo.xpp

lexico-erro-caractere:
	$(MAKE) run-lexico ARQ=erro_lexico_caractere.xpp

lexico-erro-literal-vazio:
	$(MAKE) run-lexico ARQ=erro_lexico_literal_vazio.xpp

# ----------------------------------------------------------
# Testes Sintáticos
# ----------------------------------------------------------
sintatico-valido:
	$(MAKE) run-sintatico ARQ=teste_sintatico_valido.xpp

sintatico-erro-ponto-virgula:
	$(MAKE) run-sintatico ARQ=erro_sintatico_ponto_virgula.xpp

sintatico-erro-parenteses:
	$(MAKE) run-sintatico ARQ=erro_sintatico_parenteses.xpp

sintatico-erro-if:
	$(MAKE) run-sintatico ARQ=erro_sintatico_if.xpp

sintatico-erro-estrutura:
	$(MAKE) run-sintatico ARQ=erro_sintatico_estrutura.xpp

# ----------------------------------------------------------
# Limpeza
# ----------------------------------------------------------
clean:
	@echo Limpando arquivos gerados...
	@del /Q $(LEXICO).exe $(SINTATICO).exe 2>nul || rm -f $(LEXICO) $(SINTATICO)

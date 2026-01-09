# Compilador X++ – Análise Léxica e Sintática

Este repositório contém a implementação das duas primeiras etapas de um compilador para a linguagem **X++**, desenvolvida como Trabalho Prático da disciplina de **Compiladores** do Instituto Federal de Minas Gerais (IFMG).

O projeto contempla:
- Analisador léxico completo
- Analisador sintático baseado em descida recursiva
- Tratamento de erros léxicos e sintáticos
- Conjunto de testes válidos e inválidos
- Automatização da compilação e execução via Makefile

---

## 👥 Autores

- **Andressa Caroline Lopes de Assis**  
  RA: 0072749  
  Responsável pela análise léxica, organização dos testes, Makefile e documentação

- **Bruno Augusto de Oliveira**  
  RA: 0073211  
  Responsável pela análise sintática e definição das regras gramaticais

Curso: Bacharelado em Engenharia de Computação  
Instituição: Instituto Federal de Minas Gerais – IFMG

---

## 📁 Estrutura do Projeto

```text
.
├── AnaliseLexica.cpp
├── AnaliseLexica.h
├── AnaliseSintatica.cpp
├── AnaliseSintatica.h
├── Token.h
├── main_lexico.cpp
├── main_sintatico.cpp
├── Makefile
├── README.md
├── testes/
   ├── teste_lexico_valido.xpp
   ├── erro_lexico_string.xpp
   ├── erro_lexico_simbolo.xpp
   ├── erro_lexico_caractere.xpp
   ├── erro_lexico_literal_vazio.xpp
   ├── teste_sintatico_valido.xpp
   ├── erro_sintatico_ponto_virgula.xpp
   ├── erro_sintatico_parenteses.xpp
   ├── erro_sintatico_if.xpp
   └── erro_sintatico_estrutura.xpp
```

## 🧠 Etapa 1 – Analisador Léxico

O analisador léxico percorre o código-fonte **caractere por caractere**, agrupando-os em **tokens válidos** da linguagem X++.

### Tokens reconhecidos

- Palavras reservadas (`class`, `if`, `for`, `return`, `constructor`)
- Identificadores
- Constantes numéricas
- Literais de string
- Operadores e delimitadores

### Tratamento de erros léxicos

Durante a análise, o sistema identifica e reporta erros como:

- Símbolos inválidos
- Literais de string não finalizados
- Caracteres não reconhecidos pela linguagem

Ao encontrar um erro léxico, a análise é interrompida e são informados:
- A linha do erro
- O problema identificado

---

## 🧠 Etapa 2 – Analisador Sintático

O analisador sintático foi implementado utilizando a técnica de **descida recursiva**, conforme apresentado por Delamaro.

Cada regra da gramática da linguagem X++ foi representada por um método específico, permitindo validar as principais estruturas do programa.

### Estruturas validadas

- Declarações de classes
- Métodos e construtores
- Comandos condicionais (`if`)
- Blocos de código
- Expressões e comandos

### Tratamento de erros sintáticos

Quando um erro sintático é encontrado, o sistema informa:

- A linha do erro
- O símbolo esperado
- O token encontrado

A execução é interrompida no **primeiro erro**, conforme a especificação do trabalho.

---

## 🧪 Testes Implementados

Foram criados testes válidos e testes com erros propositalmente inseridos para validar o funcionamento do compilador.

### 🔍 Testes Léxicos

| Arquivo | Descrição |
|--------|----------|
| `teste_lexico_valido.xpp` | Código sem erros léxicos |
| `erro_lexico_string.xpp` | Literal de string não finalizado |
| `erro_lexico_simbolo.xpp` | Uso de símbolo inválido |
| `erro_lexico_caractere.xpp` | Caractere não reconhecido |
| `erro_lexico_literal_vazio.xpp` | Literal mal formado |

### 🔍 Testes Sintáticos

| Arquivo | Descrição |
|--------|----------|
| `teste_sintatico_valido.xpp` | Programa sintaticamente correto |
| `erro_sintatico_ponto_virgula.xpp` | Ausência de `;` |
| `erro_sintatico_parenteses.xpp` | Parênteses não fechados |
| `erro_sintatico_if.xpp` | Estrutura incorreta do `if` |
| `erro_sintatico_estrutura.xpp` | Bloco não finalizado |

Todos os testes foram executados e validados por meio dos **logs exibidos no terminal**, utilizados posteriormente no relatório.

---

## ⚙️ Compilação

O projeto utiliza um **Makefile** para facilitar a compilação.

### Compilar os analisadores

```bash
mingw32-make
```

Esse comando gera os executáveis:

- `lexico`
- `sintatico`

---

## ▶️ Execução dos Testes

Os testes são executados informando o arquivo de entrada por meio da variável `ARQ`.

### Executar analisador léxico

```bash
mingw32-make run-lexico ARQ=teste_lexico_valido.xpp
```

### Executar analisador sintático

```bash
mingw32-make run-sintatico ARQ=erro_sintatico_if.xpp
```

## Os arquivos de teste devem estar localizados no diretório:

```text
testes/
```

---

## 🧹 Limpeza dos Executáveis

Para remover os arquivos gerados durante a compilação, utilize o comando:

```bash
mingw32-make clean
```

## 📚 Referência

DELAMARO, M. E.
Como Construir um Compilador.
São Paulo: Novatec, 2004.
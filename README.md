# Trabalho Prático – Compiladores  
## Analisador Léxico e Sintático da Linguagem X++

Este repositório contém a implementação de um **Analisador Léxico** e de um **Analisador Sintático** para a linguagem **X++**, desenvolvidos em **C++**, conforme as especificações apresentadas no livro:

> **DELAMARO, M. E.**  
> *Como Construir um Compilador: utilizando ferramenta Java*.  
> São Paulo: Novatec, 2004.

O projeto faz parte da disciplina de **Compiladores** e contempla a **Etapa 1 (Analisador Léxico)** e a **Etapa 2 (Analisador Sintático)** do trabalho prático.

---

## 👥 Integrantes da Dupla

- **Andressa Caroline Lopes de Assis**  
- **Bruno Augusto de Oliveira**

---

## 🎯 Objetivos do Projeto

- Implementar um **analisador léxico** para a linguagem X++.
- Reconhecer todos os tokens definidos na especificação da linguagem.
- Detectar e reportar **erros léxicos**, informando a linha do erro.
- Implementar um **analisador sintático descendente recursivo**.
- Validar programas escritos corretamente em X++.
- Identificar e reportar **erros sintáticos**.
- Integrar o analisador léxico ao analisador sintático.

---

## 📁 Estrutura do Projeto

```text
TrabalhoPraticoCompiladores/
├── AnaliseLexica.cpp
├── AnaliseLexica.h
├── AnaliseSintatica.cpp
├── AnaliseSintatica.h
├── Token.h
├── main_lexico.cpp
├── main_sintatico.cpp
├── Makefile
├── testes/
│   ├── teste.xpp
│   ├── erro_lexico1.xpp
│   └── erro_lexico2.xpp
├── bin/
├── obj/
└── README.md
```

---

## 🧩 Etapa 1 – Analisador Léxico

O analisador léxico é responsável por ler o código-fonte escrito em **X++** e transformá-lo em uma sequência de **tokens**, que serão utilizados pelo analisador sintático.

### Tokens Reconhecidos

- Palavras reservadas (`class`, `constructor`, `if`, `else`, `for`, `return`, `print`, `read`, etc.)
- Identificadores
- Números inteiros
- Literais de string
- Operadores aritméticos e relacionais
- Delimitadores e símbolos especiais

### Funcionalidades

- Identificação de tokens com:
  - Tipo do token
  - Lexema correspondente
  - Linha de ocorrência
- Detecção de erros léxicos, como:
  - Símbolos inválidos
  - Literais de string não finalizados
- Geração de logs detalhados da análise léxica

### Execução do Analisador Léxico
```bash
mingw32-make run-lexico
```

## Ou especificando o arquivo de teste:
```bash
mingw32-make run-lexico ARQ=teste.xpp
```
```bash
mingw32-make run-lexico ARQ=erro_lexico1.xpp
```
```bash
mingw32-make run-lexico ARQ=erro_lexico2.xpp
```

## 🧩 Etapa 2 – Analisador Sintático

O analisador sintático foi implementado utilizando a técnica de **descida recursiva**, conforme os capítulos 4 e 5 do livro do Delamaro.

Ele consome os tokens gerados pelo analisador léxico e verifica se a estrutura do programa está de acordo com a gramática da linguagem **X++**.

### Não-Terminais Implementados

- `program`
- `classList`
- `classDecl`
- `classBody`
- `varDecl`
- `constructorDecl`
- `methodDecl`
- `methodBody`
- `statement`
- `statList`
- `ifStat`
- `forStat`
- `atribStat`
- `expression`
- `numExpr`
- `term`
- `factor`

### Tratamento de Erros Sintáticos

Mensagens de erro informando:

- Linha do erro
- Símbolo esperado
- Símbolo encontrado

A análise é interrompida imediatamente ao detectar um erro sintático.

### Execução do Analisador Sintático

```bash
mingw32-make run-sintatico
```

## Ou especificando o arquivo de teste:
```bash
mingw32-make run-sintatico ARQ=teste.xpp
```
```bash
mingw32-make run-sintatico ARQ=erro_lexico1.xpp
```
```bash
mingw32-make run-sintatico ARQ=erro_lexico2.xpp
```

---

## 🧪 Arquivos de Teste

### Programa X++ Válido

- `testes/teste.xpp`

Contém:

- Declaração de classe
- Variáveis
- Construtor
- Método
- Estrutura condicional (`if`)
- Expressões e comandos válidos

### Programas com Erros Léxicos

- `testes/erro_lexico1.xpp`  
  - Literal de string não finalizado

- `testes/erro_lexico2.xpp`  
  - Uso de símbolo inválido (`@`)

Os erros são corretamente detectados e reportados pelo analisador léxico e, quando aplicável, pelo analisador sintático.

---

## ⚙️ Compilação

O projeto utiliza um **Makefile** para facilitar o processo de compilação.

### Compilar os executáveis

```bash
mingw32-make
```

### Limpar arquivos gerados
```bash
mingw32-make clean
```

---

## 🛠️ Tecnologias Utilizadas

- **Linguagem:** C++ (padrão C++17)



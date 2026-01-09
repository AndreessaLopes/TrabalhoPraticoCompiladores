# Compilador X++ – Análise Léxica e Sintática

Este repositório contém a implementação das duas primeiras etapas de um compilador para a linguagem *X++, desenvolvida como Trabalho Prático da disciplina de **Compiladores* do Instituto Federal de Minas Gerais (IFMG).


O projeto contempla:
- Analisador léxico completo
- Analisador sintático baseado em descida recursiva
- Tratamento de erros léxicos e sintáticos
- Conjunto de testes válidos e inválidos
- *Compilação e execução automatizadas via Makefile (não utilize Code::Blocks)*

---

## Importante: Compilação e Execução


*Todo o processo de compilação e execução dos testes deve ser feito exclusivamente pelo Makefile, tanto no Linux quanto no Windows.*

- Não é necessário utilizar Code::Blocks ou configurar targets específicos.
- Basta utilizar os comandos do Makefile conforme instruções abaixo.
- Os executáveis gerados são independentes: lexico (analisador léxico) e sintatico (analisador sintático), cada um com sua própria função principal (main).
- Os testes são executados diretamente pelo terminal, usando os comandos do Makefile.

---

## Instruções para Linux e Windows

### Linux

1. Abra o terminal na pasta do projeto.
2. Compile os analisadores:
  bash
  make
  
3. Execute os testes:
  bash
  make run-lexico ARQ=teste_lexico_valido.xpp
  make run-sintatico ARQ=erro_sintatico_if.xpp

  Obs.: Faça para todos os arquivos presentes na pasta "testes"
  
4. Para limpar os executáveis:
  bash
  make clean
  

### Windows

1. Abra o terminal (cmd ou PowerShell) na pasta do projeto.
2. Certifique-se de ter o compilador g++ instalado (MinGW recomendado) e o comando make disponível (MinGW/MSYS ou similar).
3. Compile os analisadores:
  cmd
  mingw32-make
  
4. Execute os testes:
  cmd
  mingw32-make run-lexico ARQ=teste_lexico_valido.xpp
  mingw32-make run-sintatico ARQ=erro_sintatico_if.xpp
  
  Obs.: Faça para todos os arquivos presentes na pasta "testes"
  
5. Para limpar os executáveis:
  cmd
  mingw32-make clean
  

*Observação:* Os comandos e nomes dos executáveis são os mesmos em ambos os sistemas. Apenas o comando make pode variar: make no Linux e mingw32-make no Windows.

---

---

## Autores

- *Andressa Caroline Lopes de Assis*  
  RA: 0072749  
  Responsável pela análise léxica, organização dos testes, Makefile e documentação

- *Bruno Augusto de Oliveira*  
  RA: 0073211  
  Responsável pela análise sintática e definição das regras gramaticais

Curso: Bacharelado em Engenharia de Computação  
Instituição: Instituto Federal de Minas Gerais – IFMG

---

## Estrutura do Projeto

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


## Etapa 1 – Analisador Léxico

O analisador léxico percorre o código-fonte *caractere por caractere, agrupando-os em **tokens válidos* da linguagem X++.

### Tokens reconhecidos

- Palavras reservadas (class, if, for, return, constructor)
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

## Etapa 2 – Analisador Sintático

O analisador sintático foi implementado utilizando a técnica de *descida recursiva*, conforme apresentado por Delamaro.

Cada regra da gramática da linguagem X++ foi representada por um método específico, permitindo validar as principais estruturas do programa.

### Estruturas validadas

- Declarações de classes
- Métodos e construtores
- Comandos condicionais (if)
- Blocos de código
- Expressões e comandos

### Tratamento de erros sintáticos

Quando um erro sintático é encontrado, o sistema informa:

- A linha do erro
- O símbolo esperado
- O token encontrado

A execução é interrompida no *primeiro erro*, conforme a especificação do trabalho.

---

## Testes Implementados


Foram criados testes válidos e testes com erros propositalmente inseridos para validar o funcionamento do compilador. Todos os arquivos de teste estão no diretório testes/.

###  Lista completa de arquivos de teste

### Testes Léxicos

| Arquivo | Descrição |
|--------|----------|
| teste_lexico_valido.xpp | Código sem erros léxicos |
| erro_lexico_string.xpp | Literal de string não finalizado |
| erro_lexico_simbolo.xpp | Uso de símbolo inválido |
| erro_lexico_caractere.xpp | Caractere não reconhecido |
| erro_lexico_literal_vazio.xpp | Literal mal formado |

### Testes Sintáticos

| Arquivo | Descrição |
|--------|----------|
| teste_sintatico_valido.xpp | Programa sintaticamente correto |
| erro_sintatico_ponto_virgula.xpp | Ausência de ; |
| erro_sintatico_parenteses.xpp | Parênteses não fechados |
| erro_sintatico_if.xpp | Estrutura incorreta do if |
| erro_sintatico_estrutura.xpp | Bloco não finalizado |

Todos os testes foram executados e validados por meio dos *logs exibidos no terminal*, utilizados posteriormente no relatório.

---

## Referência

DELAMARO, M. E.
Como Construir um Compilador.
São Paulo: Novatec, 2004.

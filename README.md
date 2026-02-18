# Mini projeto em C - 📚 Sistema de Livraria

Este projeto é um **sistema de livraria desenvolvido em C**, executado via terminal, que simula o funcionamento básico de uma loja de livros.

O sistema utiliza **estruturas de dados clássicas**:

- 📌 Lista encadeada (Clientes e Livros)
- 📌 Fila (Controle de atendimento - FIFO)
- 📌 Pilha (Histórico de vendas - LIFO)
- 📌 Percurso em lista para relatórios

Permite cadastrar clientes e livros, organizar atendimento por ordem de chegada, realizar vendas, desfazer vendas e gerar relatórios.

---

## 🧠 Estruturas de Dados Utilizadas

### 📚 Lista Encadeada
- Armazena clientes
- Armazena livros
- Permite busca, inserção e remoção

### 🚶 Fila (FIFO)
- Controla a ordem de atendimento dos clientes
- Primeiro que entra → primeiro que é atendido

### 🗂️ Pilha (LIFO)
- Armazena histórico de vendas
- Permite desfazer a última venda realizada

---

## ⚙️ Funcionalidades

### 👤 Clientes
- Cadastrar cliente
- Listar clientes
- Remover cliente
- Buscar cliente por ID

### 📖 Livros
- Cadastrar livro
- Listar livros
- Controle de estoque
- Controle de quantidade vendida

### 🛒 Atendimento
- Cliente entra na fila
- Atendimento respeita ordem FIFO
- Cliente pode comprar vários livros
- Estoque é atualizado automaticamente

### 🔄 Histórico
- Visualizar histórico de vendas
- Desfazer última venda (restaura estoque)

### 📊 Relatórios
- Exibe o livro mais vendido (Top Livro)

---

## 📋 Pré-requisitos

Antes de começar, você precisa ter instalado:

- GCC (ou outro compilador C)
- Git
- Terminal (Prompt de Comando, PowerShell, Bash ou similar)

---

## 📥 Clonar o repositório

`git clone https://github.com/luisfabian0/mini-projeto-ed.git`

## 📥 Entre na pasta do projeto

`cd mini-projeto-ed`

## 📥 Compile o arquivo principal

`gcc main.c -o livraria`

## 📥 Ou compile todos os arquivos manualmente

`gcc *.c -o livraria`

## ▶️ Execução

Após compilar, execute com:

`./livraria`

No Windows:

`./livraria.exe`

## 📂 Estrutura do Projeto

📁 sistema-livraria
 ├── main.c
 ├── cliente.c / cliente.h
 ├── livro.c / livro.h
 ├── fila.c / fila.h
 ├── pilha.c / pilha.h
 ├── venda.c / venda.h
 ├── relatorio.c / relatorio.h

## 🧪 Fluxo de Uso

1. Cadastrar clientes e livros

2. Cliente entra na fila

3. Atender cliente (realizar venda)

4. Visualizar histórico

5. Gerar relatório do livro mais vendido

## 🎓 Conceitos Aplicados

- Ponteiros

- Alocação dinâmica (malloc / free)

- Listas encadeadas

- Fila (FIFO)

- Pilha (LIFO)

- Modularização em C

- Separação em .c e .h

## 📌 Observações Técnicas

- IDs duplicados não são permitidos

- Não é possível vender mais livros do que há em estoque

- O sistema é totalmente baseado em terminal

- O histórico permite desfazer vendas com restauração automática do estoque

## 👨‍💻 Autores

- JOÃO PHELLIPE ANDRADE REIS

- LUIS FABIANO CARVALHO LEITE

- PEDRO AFONSO TAVARES BARRETO DA SILVA
 
- YASMIN SILVA SANTOS



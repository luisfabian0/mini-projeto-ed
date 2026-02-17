#ifndef VENDA_H
#define VENDA_H

#include "livro.h"
#include "cliente.h"
#include "vendedor.h"
#include "fila.h"
#include "pilha.h"

void menuCadastros(Livro **livros, Cliente **clientes, Vendedor **vendedores);
void menuFila(Fila *fila, Cliente *clientes, Livro *livros, Vendedor *vendedores, Pilha *historico);
void menuHistorico(Pilha *historico, Livro *livros, Vendedor *vendedores);

#endif

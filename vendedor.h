#ifndef VENDEDOR_H
#define VENDEDOR_H

typedef struct Vendedor {
    int id;
    char nome[50];
    int totalVendas;
    struct Vendedor *prox;
} Vendedor;

Vendedor* vendedorBuscar(Vendedor *lista, int id);
void vendedorListar(Vendedor *lista);
void vendedorInserir(Vendedor **lista);

#endif

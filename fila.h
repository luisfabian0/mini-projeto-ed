#ifndef FILA_H
#define FILA_H

typedef struct NoFila {
    int idCliente;
    struct NoFila *prox;
} NoFila;

typedef struct Fila {
    NoFila *ini;
    NoFila *fim;
    int tam;
} Fila;

void filaInit(Fila *f);
int filaVazia(Fila *f);
int filaEnfileirar(Fila *f, int idCliente);
int filaDesenfileirar(Fila *f, int *idOut);
int filaTamanho(Fila *f);

#endif


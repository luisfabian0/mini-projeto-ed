#ifndef LIVRO_H
#define LIVRO_H

typedef struct Livro {
    int id;
    char nome[50];
    char genero[30];
    int ano;
    float preco;
    int quantidade;
    int vendidos;
    struct Livro *prox;
} Livro;

Livro* livroBuscar(Livro *lista, int id);
void livroListar(Livro *lista);
void cadastrarLivro(Livro **lista);

#endif


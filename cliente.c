// Módulo: cliente.c
// Responsável por implementar a lista encadeada de clientes.
// Permite buscar, listar e inserir clientes no sistema.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

// Função: clienteBuscar
// Percorre a lista encadeada procurando um cliente pelo ID.
// Retorna ponteiro para o cliente encontrado ou NULL se não existir.
Cliente* clienteBuscar(Cliente *lista, int id) {
    while(lista != NULL) {
        if(lista->id == id)
            return lista; // Cliente encontrado
        lista = lista->prox; // Avança para o próximo nó
    }
    return NULL; // Cliente não encontrado
}

// Função: clienteListar
// Exibe todos os clientes cadastrados na lista.
void clienteListar(Cliente *lista) {
    printf("\n=== CLIENTES ===\n");

    // Verifica se a lista está vazia
    if(lista == NULL) {
        printf("(vazio)\n");
        return;
    }

    // Percorre toda a lista imprimindo os dados
    while(lista != NULL) {
        printf("ID:%d | %s\n", lista->id, lista->nome);
        lista = lista->prox;
    }
}

// Função: clienteInserir
// Insere um novo cliente no início da lista encadeada.
// Também verifica se o ID já existe para evitar duplicação.
void clienteInserir(Cliente **lista) {

    // Aloca memória para novo cliente
    Cliente *novo = (Cliente*) malloc(sizeof(Cliente));
    if(!novo) return; // Falha na alocação

    printf("ID Cliente: ");
    scanf("%d", &novo->id);

    // Verifica se já existe cliente com o mesmo ID
    if(clienteBuscar(*lista, novo->id)) {
        printf("ID ja existe.\n");
        free(novo); // Libera memória alocada
        return;
    }

    printf("Nome: ");
    scanf(" %[^\n]", novo->nome);

    // Inserção no início da lista (mais eficiente)
    novo->prox = *lista;
    *lista = novo;

    printf("Cliente cadastrado!\n");
}



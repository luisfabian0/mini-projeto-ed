// Módulo: vendedor.c
// Implementação da lista encadeada de vendedores.
// Permite buscar, listar e inserir vendedores no sistema.
// Cada vendedor possui controle de total de itens vendidos.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vendedor.h"

// Função: vendedorBuscar
// Percorre a lista encadeada procurando um vendedor pelo ID.
// Retorna ponteiro para o vendedor encontrado ou NULL se não existir.
Vendedor* vendedorBuscar(Vendedor *lista, int id) {

    while(lista != NULL) {
        if(lista->id == id)
            return lista; // Vendedor encontrado
        lista = lista->prox; // Avança para o próximo nó
    }

    return NULL; // Vendedor não encontrado
}

// Função: vendedorListar
// Exibe todos os vendedores cadastrados no sistema.
void vendedorListar(Vendedor *lista) {

    printf("\n=== VENDEDORES ===\n");

    // Verifica se a lista está vazia
    if(lista == NULL) {
        printf("(vazio)\n");
        return;
    }

    // Percorre a lista exibindo informações
    while(lista != NULL) {
        printf("ID:%d | %s | Itens vendidos:%d\n",
               lista->id,
               lista->nome,
               lista->totalVendas);

        lista = lista->prox;
    }
}

// Função: vendedorInserir
// Insere um novo vendedor no início da lista encadeada.
// Também verifica duplicidade de ID.
void vendedorInserir(Vendedor **lista) {

    // Aloca memória para novo vendedor
    Vendedor *novo = (Vendedor*) malloc(sizeof(Vendedor));
    if(!novo) return; // Falha na alocação

    printf("ID Vendedor: ");
    scanf("%d", &novo->id);

    // Verifica se já existe vendedor com esse ID
    if(vendedorBuscar(*lista, novo->id)) {
        printf("ID ja existe.\n");
        free(novo); // Libera memória em caso de duplicidade
        return;
    }

    printf("Nome: ");
    scanf(" %[^\n]", novo->nome);

    // Inicializa contador de vendas
    novo->totalVendas = 0;

    // Inserção no início da lista (operação O(1))
    novo->prox = *lista;
    *lista = novo;

    printf("Vendedor cadastrado!\n");
}


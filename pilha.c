// Módulo: pilha.c
// Implementação da estrutura de dados Pilha .
// Utilizada para armazenar o histórico de vendas.
// Permite desfazer a última venda realizada.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

// Função: pilhaInit
// Inicializa a pilha deixando o topo como NULL e tamanho zero.
void pilhaInit(Pilha *p) {
    p->topo = NULL;  // Topo da pilha
    p->tam = 0;      // Quantidade de elementos
}

// Função: pilhaVazia
// Verifica se a pilha está vazia.
// Retorna 1 se vazia, 0 caso contrário.
int pilhaVazia(Pilha *p) {
    return (p->topo == NULL);
}

// Função: pilhaPush
// Insere um novo registro de venda no topo da pilha.
// Mantém a regra LIFO.
// Retorna 1 se sucesso, 0 se falha na alocação.
int pilhaPush(Pilha *p, RegistroVenda reg) {

    // Aloca memória para novo nó da pilha
    RegistroVenda *novo = (RegistroVenda*) malloc(sizeof(RegistroVenda));
    if(!novo) return 0; // Falha na alocação

    // Copia os dados do registro recebido
    *novo = reg;

    // Novo elemento passa a apontar para o antigo topo
    novo->prox = p->topo;

    // Atualiza o topo da pilha
    p->topo = novo;

    p->tam++; // Incrementa tamanho
    return 1;
}

// Função: pilhaPop
// Remove o elemento do topo da pilha.
// Retorna os dados removidos através do ponteiro 'out'.
// Retorna 1 se sucesso, 0 se pilha vazia.
int pilhaPop(Pilha *p, RegistroVenda *out) {

    // Verifica se a pilha está vazia
    if(pilhaVazia(p)) return 0;

    // Guarda o topo atual
    RegistroVenda *temp = p->topo;

    // Atualiza o topo para o próximo elemento
    p->topo = temp->prox;

    // Retorna os dados removidos se ponteiro for válido
    if(out)
        *out = *temp;

    free(temp); // Libera memória
    p->tam--;   // Decrementa tamanho

    return 1;
}

// Função: pilhaMostrar
// Exibe todos os registros da pilha do topo até a base.
// Mostra o histórico em ordem inversa de inserção.
void pilhaMostrar(Pilha *p) {

    printf("\n=== HISTORICO ===\n");

    // Verifica se a pilha está vazia
    if(pilhaVazia(p)) {
        printf("(vazio)\n");
        return;
    }

    // Percorre do topo até o final
    RegistroVenda *aux = p->topo;
    while(aux != NULL) {
        printf("Cliente:%d | Livro:%s | Vendedor:%s | Qtd:%d | Total:R$%.2f\n",
               aux->idCliente,
               aux->nomeLivro,
               aux->nomeVendedor,
               aux->qtd,
               aux->total);

        aux = aux->prox;
    }
}

// Função: pilhaTamanho
// Retorna a quantidade atual de elementos na pilha.
int pilhaTamanho(Pilha *p) {
    return p->tam;
}


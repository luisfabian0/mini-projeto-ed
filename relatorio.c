// Módulo: relatorio.c
// Responsável por exibir relatórios do sistema.
// Aqui utilizamos:
// - Arrays (para armazenar temporariamente os dados de vendas por vendedor)
// - Percurso em lista encadeada (para encontrar top vendedor e top livro)

#include <stdio.h>
#include <string.h>
#include "relatorio.h"

// Função: menuRelatorios
// Exibe um submenu com relatórios do sistema.
// Relatórios disponíveis:
// 1) Vendas por vendedor (usando array)
// 2) Top vendedor (maior totalVendas)
// 3) Top livro (maior vendidos)
void menuRelatorios(Vendedor *vendedores, Livro *livros) {

    int op;

    do {
        printf("\n=== RELATORIOS ===\n");
        printf("1 - Vendas por vendedor\n");
        printf("2 - Top vendedor\n");
        printf("3 - Top livro\n");
        printf("0 - Voltar\n");

        printf("Opcao: ");
        scanf("%d", &op);

        // Opção 1: relatório de vendas por vendedor usando arrays
        // Ideia: percorrer lista encadeada e copiar os dados para arrays,
        // depois imprimir de forma organizada.
        if(op == 1) {

            int vendas[200];      // guarda o total de vendas de cada vendedor
            char nomes[200][50];  // guarda o nome de cada vendedor
            int i = 0;            // quantidade de vendedores copiados

            // Percorre a lista de vendedores e armazena nos arrays
            Vendedor *p = vendedores;
            while(p != NULL && i < 200) {
                vendas[i] = p->totalVendas;
                strcpy(nomes[i], p->nome);
                i++;
                p = p->prox;
            }

            // Imprime os dados do array
            for(int j = 0; j < i; j++) {
                printf("%s - Itens vendidos: %d\n", nomes[j], vendas[j]);
            }
        }

        // Opção 2: encontra o vendedor com maior número de vendas
        else if(op == 2) {

            Vendedor *top = NULL; // vai apontar para o vendedor com mais vendas
            Vendedor *p = vendedores;

            // Percorre a lista comparando totalVendas
            while(p != NULL) {
                if(top == NULL || p->totalVendas > top->totalVendas)
                    top = p;
                p = p->prox;
            }

            if(top)
                printf("Top vendedor: %s (%d)\n", top->nome, top->totalVendas);
            else
                printf("Sem vendedores.\n");
        }

        // Opção 3: encontra o livro mais vendido (maior campo vendidos)
        else if(op == 3) {

            Livro *top = NULL; // vai apontar para o livro com mais vendas
            Livro *p = livros;

            // Percorre a lista comparando o campo 'vendidos'
            while(p != NULL) {
                if(top == NULL || p->vendidos > top->vendidos)
                    top = p;
                p = p->prox;
            }

            if(top)
                printf("Top livro: %s (vendidos: %d)\n", top->nome, top->vendidos);
            else
                printf("Sem livros.\n");
        }

    } while(op != 0); // sai quando o usuário escolher 0
}



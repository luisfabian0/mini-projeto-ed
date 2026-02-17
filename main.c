// Arquivo principal do sistema de livraria
// Responsável por iniciar as estruturas e controlar o menu principal.
// Estruturas utilizadas no sistema:
// - Lista encadeada (livros, clientes e vendedores)
// - Fila (controle de atendimento - FIFO)
// - Pilha (historico de vendas - LIFO)
// - Array (relatorios)

#include <stdio.h>
#include "livro.h"
#include "cliente.h"
#include "vendedor.h"
#include "fila.h"
#include "pilha.h"
#include "venda.h"
#include "relatorio.h"

int main() {

    // Ponteiros das listas encadeadas principais
    Livro *livros = NULL;
    Cliente *clientes = NULL;
    Vendedor *vendedores = NULL;

    // Inicializacao da fila de atendimento
    Fila fila;
    filaInit(&fila);

    // Inicializacao da pilha de historico de vendas
    Pilha historico;
    pilhaInit(&historico);

    int op; // opcao do menu principal

    // Menu principal do sistema
    do {
        printf("\n==== LIVRARIA ====\n");
        printf("1 - Cadastros\n");
        printf("2 - Fila (entrar / atender)\n");
        printf("3 - Relatorios\n");
        printf("4 - Historico\n");
        printf("0 - Sair\n");

        printf("Opcao: ");
        scanf("%d", &op);

        // Direciona para o modulo correspondente
        switch(op) {
            case 1:
                // Submenu de cadastros (clientes, vendedores, livros)
                menuCadastros(&livros, &clientes, &vendedores);
                break;

            case 2:
                // Controle da fila e realizacao de vendas
                menuFila(&fila, clientes, livros, vendedores, &historico);
                break;

            case 3:
                // Geracao de relatorios do sistema
                menuRelatorios(vendedores, livros);
                break;

            case 4:
                // Exibicao e desfazer vendas do historico
                menuHistorico(&historico, livros, vendedores);
                break;
        }

    } while(op != 0); // Executa ate o usuario escolher sair

    return 0; // Finaliza o programa
}

// Módulo: venda.c
// Este módulo integra as principais estruturas do sistema:
// - Fila (FIFO): controla a ordem de atendimento dos clientes
// - Listas encadeadas: armazenam clientes, vendedores e livros
// - Pilha (LIFO): registra o histórico de vendas e permite desfazer a última operação
//
// Também contém os submenus:
// - menuCadastros
// - menuFila (entrada na fila e atendimento/venda)
// - menuHistorico (mostrar e desfazer vendas)

#include <stdio.h>
#include <string.h>

#include "venda.h"
#include "livro.h"
#include "cliente.h"
#include "vendedor.h"
#include "fila.h"
#include "pilha.h"

// Função interna (static): atenderProximo
// Remove o próximo cliente da fila e inicia o atendimento.
// Durante o atendimento o cliente pode comprar vários livros (loop).
// Cada compra realizada:
// - reduz estoque do livro
// - incrementa vendidos do livro
// - incrementa totalVendas do vendedor
// - salva um RegistroVenda na pilha de histórico (para permitir desfazer)
static void atenderProximo(Fila *fila, Cliente *clientes, Livro *livros, Vendedor *vendedores, Pilha *historico) {

    // 1) Pega o primeiro cliente da fila (FIFO)
    int idCliente;
    if(!filaDesenfileirar(fila, &idCliente)) {
        printf("Fila vazia!\n");
        return;
    }

    // 2) Busca o cliente na lista encadeada
    Cliente *c = clienteBuscar(clientes, idCliente);
    if(!c) {
        printf("Cliente nao existe!\n");
        return;
    }

    // 3) Escolhe o vendedor que vai atender (pode variar a cada atendimento)
    int idVendedor;
    printf("ID do vendedor que vai atender: ");
    scanf("%d", &idVendedor);

    // 4) Busca o vendedor na lista encadeada
    Vendedor *v = vendedorBuscar(vendedores, idVendedor);
    if(!v) {
        printf("Vendedor nao existe!\n");
        return;
    }

    printf("\nCliente da vez: %s\n", c->nome);

    // 5) Loop de compras: o cliente pode comprar vários livros até digitar 0
    while(1) {
        int idLivro;
        printf("\nID do livro (0 para finalizar): ");
        scanf("%d", &idLivro);

        // 0 encerra o atendimento do cliente
        if(idLivro == 0) break;

        // 6) Busca o livro na lista encadeada
        Livro *l = livroBuscar(livros, idLivro);
        if(!l) {
            printf("Livro nao existe!\n");
            continue;
        }

        // 7) Solicita a quantidade a comprar
        int qtd;
        printf("Quantidade: ");
        scanf("%d", &qtd);

        // Validação: quantidade positiva e estoque suficiente
        if(qtd <= 0 || l->quantidade < qtd) {
            printf("Quantidade invalida ou estoque insuficiente!\n");
            continue;
        }

        // 8) Atualiza estoque e contadores
        l->quantidade -= qtd;      // diminui estoque
        l->vendidos += qtd;        // aumenta vendidos do livro
        v->totalVendas += qtd;     // aumenta vendas do vendedor

        // 9) Monta o registro da venda e empilha no histórico (Pilha = LIFO)
        RegistroVenda reg;
        reg.idCliente = idCliente;
        reg.idLivro = idLivro;
        reg.idVendedor = idVendedor;
        reg.qtd = qtd;
        reg.total = l->preco * qtd;

        // Armazena nomes no registro para facilitar exibição do histórico
        strcpy(reg.nomeLivro, l->nome);
        strcpy(reg.nomeVendedor, v->nome);

        // Empilha a venda para permitir "desfazer a última"
        pilhaPush(historico, reg);

        printf("Venda OK: %s x%d (R$%.2f)\n", l->nome, qtd, reg.total);
    }

    printf("Atendimento finalizado.\n");
}

// Função interna (static): entrarFila
// Permite inserir clientes já cadastrados na fila de atendimento.
// O usuário digita vários IDs e encerra digitando 0.
static void entrarFila(Fila *fila, Cliente *clientes) {

    int id;
    printf("ID do cliente (0 para parar): ");
    scanf("%d", &id);

    // Enquanto o usuário não digitar 0, tenta colocar o cliente na fila
    while(id != 0) {

        // Só entra na fila se o cliente existir no cadastro
        if(clienteBuscar(clientes, id)) {
            filaEnfileirar(fila, id);
            printf("Cliente %d entrou na fila.\n", id);
        } else {
            printf("Cliente nao cadastrado.\n");
        }

        printf("ID do cliente (0 para parar): ");
        scanf("%d", &id);
    }
}

// Função: menuCadastros
// Submenu responsável por cadastrar e listar:
// - clientes
// - vendedores
// - livros
void menuCadastros(Livro **livros, Cliente **clientes, Vendedor **vendedores) {

    int op;
    do {
        printf("\n=== CADASTROS ===\n");
        printf("1 - Cadastrar Cliente\n");
        printf("2 - Cadastrar Vendedor\n");
        printf("3 - Cadastrar Livro\n");
        printf("4 - Listar tudo\n");
        printf("0 - Voltar\n");

        printf("Opcao: ");
        scanf("%d", &op);

        if(op == 1)
            clienteInserir(clientes);

        else if(op == 2)
            vendedorInserir(vendedores);

        else if(op == 3)
            cadastrarLivro(livros); // cadastra um novo livro na lista

        else if(op == 4) {
            // Listagem completa para conferência dos dados
            clienteListar(*clientes);
            vendedorListar(*vendedores);
            livroListar(*livros);
        }

    } while(op != 0);
}

// Função: menuFila
// Submenu responsável por:
// 1) adicionar clientes na fila
// 2) atender o próximo cliente e realizar compras/venda
void menuFila(Fila *fila, Cliente *clientes, Livro *livros, Vendedor *vendedores, Pilha *historico) {

    int op;
    do {
        printf("\n=== FILA ===\n");
        printf("Aguardando: %d\n", filaTamanho(fila));
        printf("1 - Entrar na fila\n");
        printf("2 - Atender proximo (faz venda)\n");
        printf("0 - Voltar\n");

        printf("Opcao: ");
        scanf("%d", &op);

        if(op == 1)
            entrarFila(fila, clientes);

        else if(op == 2)
            atenderProximo(fila, clientes, livros, vendedores, historico);

    } while(op != 0);
}

// Função: menuHistorico
// Submenu responsável por:
// 1) mostrar histórico de vendas (pilha)
// 2) desfazer a última venda (pop da pilha e estorna os dados)
void menuHistorico(Pilha *historico, Livro *livros, Vendedor *vendedores) {

    int op;
    do {
        printf("\n=== HISTORICO ===\n");
        printf("1 - Mostrar historico\n");
        printf("2 - Desfazer ultima venda\n");
        printf("0 - Voltar\n");

        printf("Opcao: ");
        scanf("%d", &op);

        // Mostra todas as vendas registradas na pilha
        if(op == 1)
            pilhaMostrar(historico);

        // Desfaz a última venda realizada (LIFO)
        else if(op == 2) {

            RegistroVenda reg;

            // Remove do topo da pilha
            if(pilhaPop(historico, &reg)) {

                // Busca livro e vendedor para reverter a operação
                Livro *l = livroBuscar(livros, reg.idLivro);
                Vendedor *v = vendedorBuscar(vendedores, reg.idVendedor);

                // Estorna: devolve estoque e ajusta contadores
                if(l) {
                    l->quantidade += reg.qtd;
                    l->vendidos -= reg.qtd;
                }
                if(v) {
                    v->totalVendas -= reg.qtd;
                }

                printf("Desfeito: %s x%d\n", reg.nomeLivro, reg.qtd);

            } else {
                printf("Historico vazio.\n");
            }
        }

    } while(op != 0);
}



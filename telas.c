#include <stdio.h>
#include "bibli.h"

void menu() {
    int opcao;
    do {
        printf("\n----- Bem-Vindo ao Menu Supermecado-----\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Comprar Produto\n");
        printf("4. Remover do Carrinho\n");
        printf("5. Atualizar Produto\n");
        printf("6. Visualizar Carrinho\n");
        printf("7. Fechar Pedido\n");
        printf("8. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1: cadastrarProduto(); break;
            case 2: listarProdutos(); break;
            case 3: comprarProduto(); break;
            case 4: removerDoCarrinho(); break;
            case 5: atualizarProduto(); break;
            case 6: visualizarCarrinho(); break;
            case 7: fecharPedido(); break;
            case 8: printf("Saindo do sistema...\n"); break;
            default: printf("Opcao invalida!\n"); break;
        }
    } while (opcao != 8);
}

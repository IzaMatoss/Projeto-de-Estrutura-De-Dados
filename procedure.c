#include <stdio.h>
#include <string.h>
#include "bibli.h"

Produto produtos[MAX_PRODUTOS];
Carrinho carrinho[MAX_CARRINHO];
int totalProdutos = 0;
int totalCarrinho = 0;

void cadastrarProduto() {
    if (totalProdutos >= MAX_PRODUTOS) {
        printf("Limite de produtos alcançado!\n");
        return;
    }
    
    Produto novoProduto;
    printf("Digite o codigo do produto: ");
    scanf("%d", &novoProduto.codigo);
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", novoProduto.nome);
    printf("Digite o preco do produto: ");
    scanf("%f", &novoProduto.preco);
    
    produtos[totalProdutos++] = novoProduto;
    printf("Produto cadastrado com sucesso!\n");
}

void listarProdutos() {
    printf("\n----- Produtos Cadastrados -----\n");
    for (int i = 0; i < totalProdutos; i++) {
        printf("Codigo: %d | Nome: %s | Preco: %.2f\n", produtos[i].codigo, produtos[i].nome, produtos[i].preco);
    }
}

void comprarProduto() {
    int codigo, quantidade;
    printf("Digite o codigo do produto: ");
    scanf("%d", &codigo);
    
    Produto* produto = pegarProdutoPorCodigo(codigo);
    if (produto == NULL) {
        printf("Produto nao encontrado!\n");
        return;
    }
    
    printf("Digite a quantidade: ");
    scanf("%d", &quantidade);
    
    int index = temNoCarrinho(codigo);
    if (index != -1) {
        carrinho[index].quantidade += quantidade;
    } else {
        if (totalCarrinho >= MAX_CARRINHO) {
            printf("Limite do carrinho alcançado!\n");
            return;
        }
        carrinho[totalCarrinho].produto = *produto;
        carrinho[totalCarrinho].quantidade = quantidade;
        totalCarrinho++;
    }
    
    printf("Produto adicionado ao carrinho!\n");
}

void visualizarCarrinho() {
    printf("\n----- Carrinho -----\n");
    for (int i = 0; i < totalCarrinho; i++) {
        printf("Produto: %s | Quantidade: %d | Preco: %.2f | Subtotal: %.2f\n", 
               carrinho[i].produto.nome, 
               carrinho[i].quantidade, 
               carrinho[i].produto.preco, 
               carrinho[i].quantidade * carrinho[i].produto.preco);
    }
}

void fecharPedido() {
    float total = 0;
    printf("\n----- Fatura -----\n");
    for (int i = 0; i < totalCarrinho; i++) {
        float subtotal = carrinho[i].quantidade * carrinho[i].produto.preco;
        printf("Produto: %s | Quantidade: %d | Subtotal: %.2f\n", 
               carrinho[i].produto.nome, 
               carrinho[i].quantidade, 
               subtotal);
        total += subtotal;
    }
    printf("Total da compra: %.2f\n", total);
    
    // Limpar o carrinho
    totalCarrinho = 0;
    printf("Pedido fechado com sucesso!\n");
}

int temNoCarrinho(int codigo) {
    for (int i = 0; i < totalCarrinho; i++) {
        if (carrinho[i].produto.codigo == codigo) {
            return i; // Retorna o índice no carrinho
        }
    }
    return -1; // Produto não está no carrinho
}

Produto* pegarProdutoPorCodigo(int codigo) {
    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            return &produtos[i];
        }
    }
    return NULL; // Produto não encontrado
}

void removerDoCarrinho() {
    int codigo;
    printf("Digite o codigo do produto a ser removido: ");
    scanf("%d", &codigo);
    
    int index = temNoCarrinho(codigo);
    if (index == -1) {
        printf("Produto nao encontrado no carrinho!\n");
        return;
    }

    // Se o produto tiver mais de uma unidade, diminui a quantidade
    if (carrinho[index].quantidade > 1) {
        carrinho[index].quantidade--;
        printf("Quantidade do produto %s reduzida. Nova quantidade: %d\n", 
               carrinho[index].produto.nome, carrinho[index].quantidade);
    } else {
        // Remove o produto do carrinho
        for (int i = index; i < totalCarrinho - 1; i++) {
            carrinho[i] = carrinho[i + 1];
        }
        totalCarrinho--;
        printf("Produto removido do carrinho!\n");
    }
}

void atualizarProduto() {
    int codigo;
    printf("Digite o codigo do produto a ser atualizado: ");
    scanf("%d", &codigo);
    
    Produto* produto = pegarProdutoPorCodigo(codigo);
    if (produto == NULL) {
        printf("Produto nao encontrado!\n");
        return;
    }

    printf("Atualizar nome (atual: %s): ", produto->nome);
    scanf(" %[^\n]", produto->nome);
    printf("Atualizar preco (atual: %.2f): ", produto->preco);
    scanf("%f", &produto->preco);

    printf("Produto atualizado com sucesso!\n");
}

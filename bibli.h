#ifndef BIBLI_H
#define BIBLI_H

#define MAX_PRODUTOS 50
#define MAX_CARRINHO 50

typedef struct {
    int codigo;
    char nome[30];
    float preco;
} Produto;

typedef struct {
    Produto produto;
    int quantidade;
} Carrinho;

void menu();
void cadastrarProduto();
void listarProdutos();
void comprarProduto();
void visualizarCarrinho();
void fecharPedido();
int temNoCarrinho(int codigo);
Produto* pegarProdutoPorCodigo(int codigo);
void removerDoCarrinho();
void atualizarProduto();

#endif // BIBLI_H

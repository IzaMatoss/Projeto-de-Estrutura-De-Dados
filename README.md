# Sistema de Supermercado em C

Este é um sistema simples de supermercado desenvolvido em linguagem de programação C. O objetivo deste projeto é fornecer uma interface de console para gerenciar produtos e um carrinho de compras, implementando conceitos de estruturas de dados como `structs` e arrays.

## Estrutura do Projeto

O projeto é dividido em quatro arquivos principais:

1. **bibli.h**: Contém as definições de estruturas e declarações de funções.
2. **procedure.c**: Implementa as funções que manipulam produtos e o carrinho de compras.
3. **main.c**: Contém a função principal que chama o menu do sistema.
4. **telas.c**: Implementa a interface do usuário e gerencia a interação com o usuário.

## Funcionalidades Implementadas

O sistema oferece as seguintes funcionalidades:

1. **Cadastrar Produto**: Permite que o usuário cadastre novos produtos com um código único, nome e preço.
2. **Listar Produtos**: Exibe todos os produtos cadastrados com suas informações.
3. **Comprar Produto**: Permite que o usuário adicione produtos ao carrinho de compras, selecionando-os pelo código.
4. **Remover do Carrinho**: Permite que o usuário remova produtos do carrinho ou diminua a quantidade.
5. **Atualizar Produto**: O usuário pode atualizar as informações de um produto cadastrado (nome e preço).
6. **Visualizar Carrinho**: Mostra os produtos no carrinho, suas quantidades e subtotais.
7. **Fechar Pedido**: Calcula o total da compra, exibe uma fatura detalhada e limpa o carrinho.
8. **Sair do Sistema**: Encerra a execução do programa de forma segura.

## Como Compilar e Executar

### Requisitos

Certifique-se de ter um compilador C instalado em sua máquina, como GCC ou Clang.

### Compilação

Para compilar o projeto, navegue até o diretório onde os arquivos estão localizados e execute o seguinte comando:

```bash
gcc main.c procedure.c telas.c -o supermercado

//
// Created by Gabriel on 20/05/2022.
//

#include "GerenciadorDeProdutos.h"

Produtos *GerenciadorDeProdutos::criarProduto(string nome, double preco, int codigo, int tipo) {
    // TODO tratamento de erro necessário para impedir que o codigo quebre nos campos que guardam números. Há conversão de string para int/double.
    Produtos* novo_produto = new Produtos();
    novo_produto->setNomeProduto(nome);
    novo_produto->setPreco(preco);
    novo_produto->setCodigo(codigo);
    novo_produto->setTipo(tipo);
    return novo_produto;
}

void GerenciadorDeProdutos::modificarInformacoes(Produtos *produto, string nome, double preco, int codigo, int tipo) {
    // TODO tratamento de erro necessário para impedir que o codigo quebre nos campos que guardam números. Há conversão de string para int/double.
    produto->setNomeProduto(nome);
    produto->setPreco(preco);
    produto->setCodigo(codigo);
    produto->setTipo(tipo);
}

//
// Created by Gabriel on 20/05/2022.
//

#ifndef MPS___MASTER_GERENCIADORDEPRODUTOS_H
#define MPS___MASTER_GERENCIADORDEPRODUTOS_H


#include "Entidades/Produtos.h"

class GerenciadorDeProdutos {
public:
    Produtos* criarProduto(string nome, int quantidade, double preco, int codigo, int tipo);
    void modificarInformacoes(Produtos* produto, string nome, double preco, int codigo, int tipo);
};


#endif //MPS___MASTER_GERENCIADORDEPRODUTOS_H

//
// Created by Gabriel on 29/05/2022.
//

#include "Command/AddProductToUser.h"

AddProductToUser::AddProductToUser(ListaDeCompras &lista, Produtos &produto, Usuario &usuario) {
    lista_de_compras_ = &lista;
    produto_ = &produto;
    usuario_ = &usuario;
}

void AddProductToUser::execute() const {
    lista_de_compras_->adiconarProdutoAoUsuario(usuario_, produto_);
}

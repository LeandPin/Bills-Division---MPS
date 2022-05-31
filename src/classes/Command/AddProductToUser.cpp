//
// Created by Gabriel on 29/05/2022.
//

#include "Command/AddProductToUser.h"

AddProductToUser::AddProductToUser(ListaDeCompras &lista, Produtos &produto, Usuario &usuario) {
    listaDeCompras_ = &lista;
    produto_ = &produto;
    usuario_ = &usuario;
}

void AddProductToUser::Execute() const {
    listaDeCompras_->adiconarProdutoAoUsuario(usuario_, produto_);
}

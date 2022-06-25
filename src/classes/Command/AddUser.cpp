//
// Created by Gabriel on 29/05/2022.
//

#include "Command/AddUser.h"

AddUser::AddUser(ListaDeCompras &lista, Usuario &usuario) {
    lista_de_compras_ = &lista;
    usuario_ = &usuario;
}


void AddUser::execute() const {
    lista_de_compras_->adicionarUsuarioALista(usuario_);
}




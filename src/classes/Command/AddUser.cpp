//
// Created by Gabriel on 29/05/2022.
//

#include "Command/AddUser.h"

AddUser::AddUser(ListaDeCompras &lista, Usuario &usuario) {
    listaDeCompras_ = &lista;
    usuario_ = &usuario;
}


void AddUser::Execute() const {
    listaDeCompras_->adicionarUsuarioALista(usuario_);
}




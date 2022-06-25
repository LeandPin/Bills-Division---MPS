//
// Created by Gabriel on 25/05/2022.
//

#include "Creators/AdminUserCreator.h"

UsuarioAdmin *AdminUserCreator::factoryMethod() const {
    UsuarioAdmin* novo_usuario = new UsuarioAdmin();

    return novo_usuario;
}
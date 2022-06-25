//
// Created by Gabriel on 25/05/2022.
//

#include "Creators/NormalUserCreator.h"

UsuarioNormal *NormalUserCreator::factoryMethod() const {
    UsuarioNormal* novo_usuario = new UsuarioNormal();

    return novo_usuario;
}

//
// Created by Gabriel on 25/05/2022.
//

#ifndef MPS___MASTER_ADMINUSERCREATOR_H
#define MPS___MASTER_ADMINUSERCREATOR_H

#include "../headers/Creators/UserCreator.h"
#include "Entidades/UsuarioAdmin.h"

class AdminUserCreator: public UserCreator {
public:
    UsuarioAdmin* factoryMethod() const override;
};


#endif //MPS___MASTER_ADMINUSERCREATOR_H

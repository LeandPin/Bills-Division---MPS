//
// Created by Gabriel on 25/05/2022.
//

#ifndef MPS___MASTER_ADMINUSERCREATOR_H
#define MPS___MASTER_ADMINUSERCREATOR_H

#include "../headers/Creators/UserCreator.h"
#include "../headers/UsuarioAdmin.h"

class AdminUserCreator: public UserCreator {
public:
    UsuarioAdmin* FactoryMethod() const override;
};


#endif //MPS___MASTER_ADMINUSERCREATOR_H

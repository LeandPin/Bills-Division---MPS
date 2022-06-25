//
// Created by Gabriel on 25/05/2022.
//

#ifndef MPS___MASTER_NORMALUSERCREATOR_H
#define MPS___MASTER_NORMALUSERCREATOR_H

#include "../headers/Creators/UserCreator.h"
#include "Entidades/UsuarioNormal.h"

class NormalUserCreator: public UserCreator {
public:
    UsuarioNormal* factoryMethod() const override;
};


#endif //MPS___MASTER_NORMALUSERCREATOR_H

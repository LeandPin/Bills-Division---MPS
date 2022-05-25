//
// Created by Gabriel on 25/05/2022.
//

#ifndef MPS___MASTER_NORMALUSERCREATOR_H
#define MPS___MASTER_NORMALUSERCREATOR_H

#include "../headers/Creators/UserCreator.h"
#include "UsuarioNormal.h"

class NormalUserCreator: public UserCreator {
public:
    UsuarioNormal* FactoryMethod() const override;
};


#endif //MPS___MASTER_NORMALUSERCREATOR_H

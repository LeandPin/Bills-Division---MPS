//
// Created by Gabriel on 25/05/2022.
//

#ifndef MPS___MASTER_USERCREATOR_H
#define MPS___MASTER_USERCREATOR_H


#include "Entidades/Usuario.h"

class UserCreator {
public:
    virtual ~UserCreator()= default;;
    virtual Usuario* factoryMethod() const = 0;
};


#endif //MPS___MASTER_USERCREATOR_H

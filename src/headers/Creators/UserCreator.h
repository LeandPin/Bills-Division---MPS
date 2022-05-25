//
// Created by Gabriel on 25/05/2022.
//

#ifndef MPS___MASTER_USERCREATOR_H
#define MPS___MASTER_USERCREATOR_H


#include "Usuario.h"

class UserCreator {
public:
    virtual ~UserCreator()= default;;
    virtual Usuario* FactoryMethod() const = 0;
};


#endif //MPS___MASTER_USERCREATOR_H

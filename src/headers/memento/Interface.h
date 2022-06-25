//
// Created by Gabriel on 31/05/2022.
//

#ifndef MPS___FORK_INTERFACE_H
#define MPS___FORK_INTERFACE_H


#include "Entidades/Usuario.h"
#include "Entidades/Produtos.h"
#include <unordered_map>
#include <vector>

class Interface {
public:
    virtual std::string date() const = 0;
    virtual unordered_map<Usuario*, vector<Produtos*>> state() const = 0;
};


#endif //MPS___FORK_INTERFACE_H

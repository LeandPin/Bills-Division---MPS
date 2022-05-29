//
// Created by Gabriel on 29/05/2022.
//

#ifndef MPS___FORK_MEMENTO_H
#define MPS___FORK_MEMENTO_H

#include <unordered_map>
#include "Entidades/Usuario.h"
#include "Entidades/Produtos.h"


class Memento {
public:
    virtual std::string date() const = 0;
    virtual unordered_map<Usuario*, vector<Produtos*>> state() const = 0;
};


#endif //MPS___FORK_MEMENTO_H

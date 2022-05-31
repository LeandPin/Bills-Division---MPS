//
// Created by Gabriel on 31/05/2022.
//

#ifndef MPS___FORK_LISTADECOMPRAS_H
#define MPS___FORK_LISTADECOMPRAS_H

#include "Usuario.h"
#include "Produtos.h"
#include <unordered_map>
#include <vector>


class ListaDeCompras {
protected:
    unordered_map<Usuario*, vector<Produtos*>> listaDeCompras;

public:
    Usuario* getUsuario();
    vector<Produtos*>* getProdutos(string login);
};


#endif //MPS___FORK_LISTADECOMPRAS_H

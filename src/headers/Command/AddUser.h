//
// Created by Gabriel on 29/05/2022.
//

#ifndef MPS___FORK_ADDUSER_H
#define MPS___FORK_ADDUSER_H

#include "CommandInterface.h"
#include "../Entidades/Usuario.h"
#include "../Facade/ListaDeCompras.h"

class AddUser: public CommandInterface {
private:
    ListaDeCompras *listaDeCompras_;
    Usuario* usuario_;

public:
    AddUser(ListaDeCompras &lista, Usuario &usuario);
    void Execute() const override;
};


#endif //MPS___FORK_ADDUSER_H

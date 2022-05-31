//
// Created by Gabriel on 29/05/2022.
//

#ifndef MPS___FORK_ADDPRODUCTTOUSER_H
#define MPS___FORK_ADDPRODUCTTOUSER_H

#include "../Facade/ListaDeCompras.h" // Receiver
#include "../Entidades/Usuario.h" // Informação para operação
#include "../Entidades/Produtos.h" // Informação para operação
#include "CommandInterface.h" // Interface do comando

class AddProductToUser: public CommandInterface{
private:
    ListaDeCompras* listaDeCompras_;
    Produtos* produto_;
    Usuario* usuario_;

public:
    AddProductToUser(ListaDeCompras &lista, Produtos &produto, Usuario &usuario);
    void Execute() const override;

};


#endif //MPS___FORK_ADDPRODUCTTOUSER_H

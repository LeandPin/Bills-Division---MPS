//
// Created by Gabriel on 29/05/2022.
//

#ifndef MPS___FORK_INVOKER_H
#define MPS___FORK_INVOKER_H

#include "CommandINterface.h"
#include "../Controllers/GerenciadorDeUsuarios.h"

class Invoker {
private:
    CommandInterface* add_user_;
    CommandInterface* add_product_to_user_;


public:
    ~Invoker();

    void AddUser(CommandInterface* command);
    void AddProductToUser(CommandInterface* command);

    void Do();
    void criarUsuario();
};


#endif //MPS___FORK_INVOKER_H

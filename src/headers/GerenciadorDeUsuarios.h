//
// Created by Gabriel on 19/04/2022.
//

#ifndef MPS_GERENCIADORDEUSUARIOS_H
#define MPS_GERENCIADORDEUSUARIOS_H

#include "../headers/Usuario.h"


class GerenciadorDeUsuarios {
public:
    static Usuario* CriarUsuario(string nome, string login, string senha, bool privelegios);
    void alterarDadosDoUsuario(Usuario u, string nome="", string login="", string senha="", bool privilegio=false);
};


#endif //MPS_GERENCIADORDEUSUARIOS_H

//
// Created by Gabriel on 19/04/2022.
//

#ifndef MPS_GERENCIADORDEUSUARIOS_H
#define MPS_GERENCIADORDEUSUARIOS_H

#include "../headers/Usuario.h"


class GerenciadorDeUsuarios {
public:
    static Usuario* CriarUsuario(string nome, string login, string senha, bool privelegios, int dia, int mes, int ano);
    void alterarDadosDoUsuario(Usuario &u, string nome="", string login="", string senha="", bool privilegio=false, int dia=00, int mes=00, int ano=0000);
};


#endif //MPS_GERENCIADORDEUSUARIOS_H

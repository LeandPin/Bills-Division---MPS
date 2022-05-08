//
// Created by Gabriel on 19/04/2022.
//

#ifndef MPS_TELAS_H
#define MPS_TELAS_H

#include <iostream>

using namespace std;

class Telas {
public:
    static void MenuPrincipal();
    static void AdminFaltado();
    static void Cadastrar(string x);
    static void login();

    static void exibirInformacoes(string nome, string login, string senha, bool p);

    static void alterarNome();

    static void alterarSenha();

    static void semPrivilegios();

    static void areaAdm();

    static void login_invalido();

    static void senha_invalida();

    static void usuario_nao_encontrado();
};


#endif //MPS_TELAS_H

//
// Created by Gabriel on 19/04/2022.
//

#ifndef MPS_TELAS_H
#define MPS_TELAS_H

#include <iostream>
#include <vector>
#include "Usuario.h"

using namespace std;

class Telas {
public:
    static void MenuPrincipal(string login);
    static void AdminFaltado();
    static void Cadastrar(string x);
    static void login();

    static void exibirInformacoes(string nome, string login, string senha, bool p, std::tuple<int, int, int> dataNascimento);
    static void exibirlogins(vector<Usuario*> usuarios);

    static void alterarNome();

    static void alterarSenha();

    static void semPrivilegios();

    static void areaAdm();

    static void login_invalido();

    static void senha_invalida();

    static void usuario_nao_encontrado();

    static void modoExib();

    static void AdicionarProdutoNome();
    static void AdicionarProdutoQuantidade();
    static void AdicionarProdutoPreco();
    static void AdicionarProdutoID();
};


#endif //MPS_TELAS_H

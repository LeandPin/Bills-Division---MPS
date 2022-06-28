//
// Created by Gabriel on 19/04/2022.
//

#ifndef MPS_TELAS_H
#define MPS_TELAS_H

#include <iostream>
#include <vector>
#include "Entidades/Usuario.h"
#include "Entidades/Produtos.h"

using namespace std;

class Telas {
public:
    static void menuPrincipal(string login);
    static void adminFaltado();
    static void cadastrar(string x);
    static void login();

    static void exibirInformacoes(string nome, string login, string senha, bool p, std::tuple<int, int, int> dataNascimento);
    static void exibirlogins(vector<Usuario*> usuarios);
    static void exibirProdutos(string login, vector<Produtos*> produtos);

    static void alterarNome();

    static void alterarSenha();

    static void semPrivilegios();

    static void areaAdm();

    static void loginInvalido();

    static void senhaInvalida();

    static void usuarioNaoEncontrado();

    static void modoExib();

    static void adicionarProdutoNome();
    static void adicionarProdutoQuantidade();
    static void adicionarProdutoPreco();
    static void adicionarProdutoId();

    static void salvar();
};


#endif //MPS_TELAS_H

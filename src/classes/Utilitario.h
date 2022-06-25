//
// Created by Gabriel on 25/06/2022.
//

#ifndef MPS___MASTER_UTILITARIO_H
#define MPS___MASTER_UTILITARIO_H

#include <tuple>
#include <string>
#include <vector>

#include "Entidades/Usuario.h"
#include "Telas.h"
#include "Controllers/GerenciadorDeUsuarios.h"
#include "Exceptions/UserNotFoundException.h"


class Utilitario {
public:
    static bool existeAdmin(std::vector <Usuario *> usuarios);
    static bool compare(std::tuple<int, int, int> d1, std::tuple<int, int, int> d2);

    static Usuario* loginUsuario(std::vector <Usuario *> usuarios);
    static void pegarInformacoes(std::string &nome, std::string &login, std::string &senha, bool &privilegio, int &dia, int &mes, int &ano, bool perguntar);
    static Usuario * criarUsuario(bool perguntar);


    static void alterarDados(Usuario * user, GerenciadorDeUsuarios gerente);
    static void obterInformacoesProduto(std::string &nomeProduto, int &quantidade, double &preco, int &ID);

};


#endif //MPS___MASTER_UTILITARIO_H

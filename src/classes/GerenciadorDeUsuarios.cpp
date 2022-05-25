//
// Created by Gabriel on 19/04/2022.
//

#include "../headers/GerenciadorDeUsuarios.h"
#include "../headers/UserNameException.h"
#include "../headers/UserPasswordException.h"
#include <utility>

Usuario* GerenciadorDeUsuarios::CriarUsuario(string nome, string login, string senha, bool privilegios, int dia, int mes, int ano) {
    Usuario* novo_usuario = new Usuario();

    try{
    novo_usuario->setLogin(std::move(login));
    novo_usuario->setSenha(std::move(senha));
    novo_usuario->setDATA(dia, mes, ano);
    }
    catch (UserNameException& e) {
        throw e;
    }
    catch (UserPasswordException& e) {
        throw e;
    }
    novo_usuario->setNome(std::move(nome));
    novo_usuario->setPrivilegios(privilegios);

    return novo_usuario;
}


void GerenciadorDeUsuarios::alterarDadosDoUsuario(Usuario &u, string nome, string login, string senha, bool privilegio, int dia, int mes, int ano) {
    try {
    u.setNome(nome);
    u.setSenha(senha);
    u.setPrivilegios(privilegio);
    u.setDATA(dia, mes, ano);
    }
    catch (UserPasswordException &e) {
        throw e;
    }
}


bool GerenciadorDeUsuarios::compararLogin(const string& login_registrado, const string& login_recebido) {
    if (login_registrado == login_recebido) return true;

    return false;
}


bool GerenciadorDeUsuarios::compararSenha(const string& senha_registrado, const string& senha_recebido) {
    if (senha_registrado == senha_recebido) return true;

    return false;
}
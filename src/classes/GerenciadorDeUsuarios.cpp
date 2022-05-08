//
// Created by Gabriel on 19/04/2022.
//

#include "../headers/GerenciadorDeUsuarios.h"
#include "../headers/UserNameException.h"
#include "../headers/UserPasswordException.h"
#include <utility>

Usuario* GerenciadorDeUsuarios::CriarUsuario(string nome, string login, string senha, bool privilegios) {
    Usuario* novo_usuario = new Usuario();

    try{
    novo_usuario->setLogin(std::move(login));
    novo_usuario->setSenha(std::move(senha));
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


void GerenciadorDeUsuarios::alterarDadosDoUsuario(Usuario u, string nome, string login, string senha, bool privilegio) {
    u.modificarInformacoes(nome, login, senha);
    u.setPrivilegios(privilegio);
}



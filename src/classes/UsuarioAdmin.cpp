#include "../headers/UsuarioAdmin.h"
#include "../headers/Usuario.h"
#include <string>
#include <iostream>
using namespace std;

/*
Construtor Padrão da classe UsuarioAdmin.
*/

UsuarioAdmin::UsuarioAdmin(): Usuario()
{
    setPrivilegios(true);
}

Usuario* UsuarioAdmin::CriarUsuario(string nome, string login, string senha, bool privilegios, int dia, int mes, int ano) {
    return GerenciadorDeUsuarios::CriarUsuario(nome, login, senha, privilegios, dia, mes, ano);
}



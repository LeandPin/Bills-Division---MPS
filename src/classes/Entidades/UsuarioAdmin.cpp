#include "Entidades/UsuarioAdmin.h"
#include "Entidades/Usuario.h"
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


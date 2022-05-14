#ifndef USUARIOADMIN_H
#define USUARIOADMIN_H
#include <iostream>
#include <string>
#include "../headers/Usuario.h"
#include "../headers/GerenciadorDeUsuarios.h"
/*
Classe UsuarioAdmin
Herda Da superclasse Usuario
*/
using namespace std;
#pragma once

class UsuarioAdmin : public Usuario
{
public:
    UsuarioAdmin();
    static Usuario* CriarUsuario(string nome, string login, string senha, bool privilegios, int dia, int mes, int ano);
    
    
    

private:
 

   

};

#endif

/*
Super-classe Referente aos Usuários, com atributos e classes para cadastro.
*/
#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <iostream>
#include "../headers/UserNameException.h"
#include "../headers/UserPasswordException.h"

using namespace std;


class Usuario
{
public:
    /*
    Métodos Utilizados na superclasse, com prioridade de cadastro.
    */
    Usuario();
    void setNome(string nome);
    void setSenha(string senha);
    void setLogin(string login);
    void setPrivilegios(bool p);
    string getNome();
    string getSenha();
    string getLogin();
    bool getPrivilegios();
   
    void modificarInformacoes(string nome="", string login="", string senha="");
    bool compararLogin(string login);
    bool compararSenha(string senha);


private:
    /*
    Atributos Utilizados Para Cadastro do usuário.
    */
    string nomeDoUsuario;
    string Senha;
    string Login;
    bool privilegios;


    static bool CheckLogin(string login);
    static bool CheckPswd(string senha);


};

#endif
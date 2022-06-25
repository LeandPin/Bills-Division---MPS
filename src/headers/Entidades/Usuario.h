
/*
Super-classe Referente aos Usuários, com atributos e classes para cadastro.
*/
#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <iostream>
#include "Exceptions/UserNameException.h"
#include "Exceptions/UserPasswordException.h"
#include "Data.h"

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
    void setDATA(int dia, int mes, int ano);
    void setPrivilegios(bool p);

    string getNome();
    string getSenha();
    string getLogin();
    std::tuple<int, int, int> getData();
    int getAno();
    int getMes();
    int getDia();
    bool getPrivilegios();


private:
    /*
    Atributos Utilizados Para Cadastro do usuário.
    */
    string nome_do_usuario;
    string Senha;
    string Login;
    bool privilegios;
    Data data_nascimento;
    


    static bool checkLogin(string login);
    static bool checkPswd(string senha);


};

#endif
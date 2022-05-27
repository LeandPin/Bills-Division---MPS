#include "Entidades/Usuario.h"
#include <string>
#include <tuple>

/*
Arquivo Usuario.cpp contendo Construtor da superclasse Usuário 
e métodos gets e seters para os atributos nomeDoUsuario,Senha e Login.
*/

using namespace std;


Usuario::Usuario(){
    nomeDoUsuario = "";
    Senha = "";
    Login = "";
    privilegios = false;
}


void Usuario::setNome(string nome){
    nomeDoUsuario = nome;
}


string Usuario::getNome(){
    return nomeDoUsuario;
}


void Usuario::setSenha(string senha){
    if (CheckPswd(senha)) {
    Senha = senha;
    }
    else throw UserPasswordException();
 }


void Usuario::setLogin(string login){
    if (CheckLogin(login)) {
        Login = login;
    }
    else throw UserNameException();
 }


string Usuario::getSenha(){
    return Senha;
}


string Usuario::getLogin(){
    return Login;
}


 void Usuario::setPrivilegios(bool p){
     privilegios = p;
 }


bool Usuario::getPrivilegios(){
     return privilegios;
    }


bool Usuario::CheckLogin(string login){
    /*
     * Verifica os seguintes parametros:
     *      - Máximo 12 caracteres
     *      - Não pode estar vazio
     *      - Não pode ter números
     */
    if (login.length()==0){ // O login não pode ser vazio.
        return false;
    }
    if (login.length()>12){ // O login deve ter, no máximo, 12 caracteres.
        return false;
    }
    for (int i = 0; i < login.length();i++) { // O login não deve ter números.
        if (isdigit(login[i])){
            return false;
        }
    }
    return true;
}


bool Usuario::CheckPswd(string senha){
    /*
     * Verificar os seguintes parâmetros:
     *      - Máximo 12 caracteres
     *      - Mínimo 8 caracteres
     *      - Deve possuir letras e no mínimo 2 números.
     */
    if (senha.length()<8 || senha.empty()){ // A senha deve possuir, no mínimo, 8 dígitos.
        return false;
    }else if (senha.length()>=21){ // A senha deve possuir, no máximo, 20 dígitos.
        return false;
    }
    int letras=0, numeros=0;
    for (int i = 0; i < senha.length(); i++){
        if (isdigit(senha[i])){
            numeros++;
        }else if (isalpha(senha[i])){
            letras++;
        }else{ // Caractere inválido.
            return false;
        }
    }
    if ((letras<1)||(numeros<2)){ // A senha deve possuir letras e números e ao menos 2 números.
        return false;
    }
    return true;
}


void Usuario::setDATA(int dia, int mes, int ano){
   data_nascimento.setDia(dia);
   data_nascimento.setMes(mes);
   data_nascimento.setAno(ano);
}

std::tuple<int, int, int> Usuario::getData(){
    return  {data_nascimento.getDia(),data_nascimento.getMes(), data_nascimento.getAno()};
}

int Usuario::getAno(){
    return  data_nascimento.getAno();
}

int Usuario::getMes(){
    return  data_nascimento.getMes();
}

int Usuario::getDia(){
    return  data_nascimento.getDia();
}
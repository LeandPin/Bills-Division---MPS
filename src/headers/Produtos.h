#ifndef PRODUTOS_H
#define PRODUTOS_H
#include <string>
#include <iostream>

using namespace std;

#pragma once

class Produtos
{
public:
    Produtos();
    ~Produtos();
    void setNomeProduto(string nome);
    void setCodigo(int codigo);
    string getnomeProduto();
    int getCodigo();
    

private:
string nomeProduto;
int codigo;
int tipo;


};

#endif
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
    void setTipo(int tipo);
    void setPreco(double preco);

    string getnomeProduto();
    int getCodigo();
    int getTipo();
    double getPreco();
    

private:
    string nomeProduto;
    int codigo;
    double preco;
    int tipo;


};

#endif
#include "Produtos.h"

Produtos::Produtos()
{
    nomeProduto = "";
    codigo = 0;
    tipo = 0;
    preco = 0;
}


Produtos::~Produtos()
{

}


void Produtos::setNomeProduto(string nome){
    nomeProduto = nome;
}
void Produtos::setCodigo(int codigo){
        this-> codigo = codigo;
}

void Produtos::setTipo(int tipo){
    this->tipo = tipo;
}

void Produtos::setPreco(double preco) {
    this->preco = preco;
}


string Produtos::getnomeProduto(){
    return nomeProduto;
}


int Produtos::getCodigo(){
 return codigo;
}

int Produtos::getTipo(){
    return tipo;
}


double Produtos::getPreco() {
    return preco;
}

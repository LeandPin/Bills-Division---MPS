#include "Entidades/Produtos.h"

Produtos::Produtos()
{
    nome_produto = "";
    codigo = 0;
    tipo = 0;
    preco = 0;
}


Produtos::~Produtos()
{

}


void Produtos::setNomeProduto(string nome){
    nome_produto = nome;
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
    return nome_produto;
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

void Produtos::setQuantidade(int qnt) {
    this->quantidade = qnt;
}

int Produtos::getQuantidade() {
    return quantidade;
}

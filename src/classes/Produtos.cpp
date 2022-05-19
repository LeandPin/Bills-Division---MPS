#include "Produtos.h"

Produtos::Produtos()
{

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
string Produtos::getnomeProduto(){
    return nomeProduto;
}
int Produtos::getCodigo(){
 return codigo;
}
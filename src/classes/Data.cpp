#include "../headers/Data.h"

Data::Data()
{

}

Data::~Data()
{

}

Data::Data(int dia, int mes, int ano){
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
}

int Data::getDia(){
    return dia;
}
int Data::getAno(){
    return ano;
}
int Data::getMes(){
    return mes;
}
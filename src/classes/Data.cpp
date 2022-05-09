#include "../headers/Data.h"

Data::Data()
{

}

Data::~Data()
{

}



void Data::setDia(int dia){
     this->dia = dia;
}
void Data::setAno(int ano){
this->ano = ano;
}

void Data::setMes(int mes){
this->mes = mes;
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
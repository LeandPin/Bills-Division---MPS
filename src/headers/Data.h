#ifndef DATA_H
#define DATA_H

#pragma once
class Data
{
public:
    Data();
    ~Data();
    void setDia(int dia);
    void setAno(int ano);
    void setMes(int mes);
    int getDia();
    int getAno();
    int getMes();

private:
int dia;
int mes;
int ano;

};

#endif
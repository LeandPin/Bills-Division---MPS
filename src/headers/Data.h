#ifndef DATA_H
#define DATA_H

#pragma once

class Data
{
public:
    Data();
    Data(int dia, int mes, int ano);
    ~Data();
    int getDia();
    int getAno();
    int getMes();

private:
int dia;
int mes;
int ano;

};

#endif
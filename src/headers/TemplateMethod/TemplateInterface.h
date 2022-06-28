//
// Created by Gabriel on 25/06/2022.
//

#ifndef MPS___FORK_TEMPLATEINTERFACE_H
#define MPS___FORK_TEMPLATEINTERFACE_H
#include "Facade/ListaDeCompras.h"
#include <string>
#include <utility>
#include <fstream>

class TemplateInterface {
private:

protected:
    ListaDeCompras* informacoes;
    string path_;
    string buffer_;
    string tipo_;

    TemplateInterface(ListaDeCompras* lista, std::string path);
    virtual void estruturarInformacoes() = 0;
    virtual void definirTipo() = 0;
    void gerarArquivo();

public:
    void executar();
    std::string getPath();
};


#endif //MPS___FORK_TEMPLATEINTERFACE_H

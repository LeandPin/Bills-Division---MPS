//
// Created by Gabriel on 25/06/2022.
//

#ifndef MPS___FORK_SAVEASTXT_H
#define MPS___FORK_SAVEASTXT_H

#include "TemplateMethod/TemplateInterface.h"
class SaveAsTxt: public TemplateInterface{
public:
    SaveAsTxt(ListaDeCompras *lista, std::string path);
    void definirTipo() override;
    void estruturarInformacoes() override;
};


#endif //MPS___FORK_SAVEASTXT_H

//
// Created by Gabriel on 25/06/2022.
//

#ifndef MPS___FORK_SAVEASHTML_H
#define MPS___FORK_SAVEASHTML_H

#include "TemplateMethod/TemplateInterface.h"

class SaveAsHtml: public TemplateInterface{
public:
    SaveAsHtml(ListaDeCompras *lista, std::string path);
protected:
    void estruturarInformacoes() override;
    void definirTipo() override;
};


#endif //MPS___FORK_SAVEASHTML_H

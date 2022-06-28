//
// Created by Gabriel on 25/06/2022.
//

#include "TemplateMethod/TemplateInterface.h"


TemplateInterface::TemplateInterface(ListaDeCompras *lista, std::string path) {
    this->informacoes = lista;
    this->path_ = std::move(path);
}

void TemplateInterface::gerarArquivo() {
    string caminho = getPath() + "/relatorio" + tipo_;
    std::ofstream new_file(caminho, ios_base::trunc);
    new_file << buffer_;
    new_file.close();
}

void TemplateInterface::executar() {
    this->definirTipo();
    this->estruturarInformacoes();
    this->gerarArquivo();
}


std::string TemplateInterface::getPath() {
    return path_;
}

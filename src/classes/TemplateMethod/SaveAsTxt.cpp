//
// Created by Gabriel on 25/06/2022.
//

#include "TemplateMethod/SaveAsTxt.h"

SaveAsTxt::SaveAsTxt(ListaDeCompras *lista, std::string path) : TemplateInterface(lista, path) {
    this->informacoes = lista;
    this->path_ = path;
}

void SaveAsTxt::definirTipo() {
    tipo_ = ".txt";
}

void SaveAsTxt::estruturarInformacoes() {
    informacoes->listaDeUsuarios();
    for (auto elemento: this->informacoes->listaDeUsuarios()) {
        if (elemento->getPrivilegios())
            buffer_ += elemento->getNome() + "|" + elemento->getLogin() + "|" + elemento->getSenha() + "| ADMIN\n";
        else
            buffer_ += elemento->getNome() + "|" + elemento->getLogin() + "|" + elemento->getSenha() + "| NORMAL\n";
        for (auto elmento_produto: informacoes->listaDeProdutos(elemento->getLogin())) {
            buffer_ += elmento_produto->getnomeProduto() + "|" + to_string(elmento_produto->getQuantidade()) + to_string(elmento_produto->getPreco()) + "|" + to_string(elmento_produto->getCodigo()) + "\n";
        }
    }
}

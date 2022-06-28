//
// Created by Gabriel on 25/06/2022.
//

#include "TemplateMethod/SaveAsHtml.h"

SaveAsHtml::SaveAsHtml(ListaDeCompras *lista, std::string path) : TemplateInterface(lista, path) {
    informacoes = lista;
    path_ = path;
}

void SaveAsHtml::definirTipo() {
    tipo_ = ".html";
}


void SaveAsHtml::estruturarInformacoes() {
    buffer_ = "<html><body><div><dl>";
    for (auto elemento: informacoes->listaDeUsuarios()) {
        buffer_ += "<dt>" + elemento->getNome() + "|" + elemento->getLogin() + "|" + elemento->getSenha() + "| privilegio = " + to_string(elemento->getPrivilegios()) + "</dt>";
        for (auto elemento_produto: informacoes->listaDeProdutos(elemento->getLogin())) {
            buffer_ += "<dd>" + to_string(elemento_produto->getCodigo()) + "| " + elemento_produto->getnomeProduto() + " | " + to_string(elemento_produto->getPreco()) + " | " +
                    to_string(elemento_produto->getQuantidade()) +"</dd>";
        }
    }
    buffer_ += "</dl></div></body></html>";
}

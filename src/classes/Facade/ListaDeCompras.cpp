//
// Created by Gabriel on 21/05/2022.
//

#include "Facade/ListaDeCompras.h"
ListaDeCompras* ListaDeCompras::fachada_= nullptr;

ListaDeCompras::ListaDeCompras(GerenciadorDeUsuarios *gerenciadorDeUsuarios, GerenciadorDeProdutos *gerenciadorDeProdutos) {

}

ListaDeCompras *
ListaDeCompras::GetInstance(GerenciadorDeUsuarios *gerenciadorDeUsuarios, GerenciadorDeProdutos *gerenciadorDeProdutos) {
    if (fachada_ == nullptr) {
        fachada_ = new ListaDeCompras(gerenciadorDeUsuarios, gerenciadorDeProdutos);
    }
    return fachada_;
}

void ListaDeCompras::adicionarUsuarioALista(Usuario *usuario) {
    if (usuario == nullptr) throw std::invalid_argument("nullptr");
    vector<Produtos*> vetor_vazio;
    pair<Usuario*, vector<Produtos*>> novo_elemento (usuario, vetor_vazio);

    listaDeCompras.insert(novo_elemento);
}

void ListaDeCompras::adiconarProdutoAoUsuario(Usuario *usuario, Produtos *produto) {
    for (auto &item : listaDeCompras) {
        if (item.first->getNome() == usuario->getNome()) {
            item.second.push_back(produto);
            return;
        }
    }
    throw UserNotFoundException();
}

vector<Produtos *> ListaDeCompras::listaDeProdutos(string login) {
    for (auto &item : listaDeCompras) {
        if (item.first->getLogin() == login) {
            return item.second;
        }
    }
    throw UserNotFoundException();
}

vector<Usuario *> ListaDeCompras::listaDeUsuarios() {
    vector<Usuario*> lista;
    for (auto &item : listaDeCompras) {
        lista.push_back(item.first);
    }
    return lista;
}

Memento *ListaDeCompras::save() {
    return new ListaDeCompraMemento(this->listaDeCompras);
}

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
    elemento novo = elemento {
        usuario,
    };
    listaDeCompras.push_back(novo);
}

void ListaDeCompras::adiconarProdutoAoUsuario(Usuario *usuario, Produtos *produto) {
    for (auto &item : listaDeCompras) {
        bool teste = item.usuario->getNome() == usuario->getNome();
        if (item.usuario->getNome() == usuario->getNome()) {
            item.produtos.push_back(produto);
            return;
        }
    }
    throw UserNotFoundException();
}

vector<Produtos *> ListaDeCompras::listaDeProdutos(string login) {
    for (auto &item : listaDeCompras) {
        if (item.usuario->getLogin() == login) {
            return item.produtos;
        }
    }
    throw UserNotFoundException();
}

vector<Usuario *> ListaDeCompras::listaDeUsuarios() {
    vector<Usuario*> lista;
    for (auto &item : listaDeCompras) {
        lista.push_back(item.usuario);
    }
    return lista;
}

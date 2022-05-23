//
// Created by Gabriel on 21/05/2022.
//

#include "Fachada.h"
Fachada* Fachada::fachada_= nullptr;

Fachada::Fachada(GerenciadorDeUsuarios *gerenciadorDeUsuarios, GerenciadorDeProdutos *gerenciadorDeProdutos) {

}

Fachada *
Fachada::GetInstance(GerenciadorDeUsuarios *gerenciadorDeUsuarios, GerenciadorDeProdutos *gerenciadorDeProdutos) {
    if (fachada_ == nullptr) {
        fachada_ = new Fachada(gerenciadorDeUsuarios, gerenciadorDeProdutos);
    }
    return fachada_;
}

void Fachada::adicionarUsuarioALista(Usuario *usuario) {
    if (usuario == nullptr) throw std::invalid_argument("nullptr");
    elemento novo = elemento {
        usuario,
    };
    listaDeCompras.push_back(novo);
}

void Fachada::adiconarProdutoAoUsuario(Usuario *usuario, Produtos *produto) {
    for (auto &item : listaDeCompras) {
        bool teste = item.usuario->getNome() == usuario->getNome();
        if (item.usuario->getNome() == usuario->getNome()) {
            item.produtos.push_back(produto);
            return;
        }
    }
    throw UserNotFoundException();
}

vector<Produtos *> Fachada::listaDeProdutos(string login) {
    for (auto &item : listaDeCompras) {
        if (item.usuario->getLogin() == login) {
            return item.produtos;
        }
    }
    throw UserNotFoundException();
}

vector<Usuario *> Fachada::listaDeUsuarios() {
    vector<Usuario*> lista;
    for (auto &item : listaDeCompras) {
        lista.push_back(item.usuario);
    }
    return lista;
}

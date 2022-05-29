//
// Created by Gabriel on 29/05/2022.
//

#include "Memento/ListaDeCompraMemento.h"

ListaDeCompraMemento::ListaDeCompraMemento(unordered_map<Usuario *, vector<Produtos *>> state): state_(state) {
    this->state_ = state;
    std::time_t now = std::time(0);

    this->date_ = std::ctime(&now);
}

unordered_map<Usuario *, vector<Produtos *>> ListaDeCompraMemento::state() const {
    return this->state_;
}

string ListaDeCompraMemento::date() const {
    return this->date_;
}




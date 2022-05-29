//
// Created by Gabriel on 29/05/2022.
//

#include "Memento/Caretaker.h"

Caretaker::Caretaker(ListaDeCompras *originator): listaDeCompras_() {
    this->listaDeCompras_ = originator;
}

void Caretaker::backup() {
    this->mementos_.push_back(this->listaDeCompras_->save());
}

void Caretaker::undo() {
    if (!this->mementos_.size()) return;

    Memento* memento = this->mementos_.back();
    this->mementos_.pop_back();

    try {
        this->listaDeCompras_->restore(memento);
    } catch (...) {
        this->undo();
    }
}




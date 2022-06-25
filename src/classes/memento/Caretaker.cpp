//
// Created by Gabriel on 31/05/2022.
//

#include "memento/Caretaker.h"

Caretaker::Caretaker(ListaDeCompras *originator)  : originator_(originator) {
    this->originator_ = originator;
}

void Caretaker::backup(){
    this->mementos_.push_back(this->originator_->save());
}

void Caretaker::undo()  {
    if (!this->mementos_.size()) {
        return;
    }
    ConcreteMemento *memento = this->mementos_.back();
    this->mementos_.pop_back();
    try {
        this->originator_->restore(memento);
    } catch (...) {
        this->undo();
    }
}

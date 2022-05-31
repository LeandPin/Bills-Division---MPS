//
// Created by Gabriel on 31/05/2022.
//

#include "memento/ConcreteMemento.h"

ConcreteMemento::ConcreteMemento(unordered_map<Usuario *, vector<Produtos *>> state)  : state_(state) {
    this->state_ = state;
    time_t now = time(0);
    this->date_ = ctime(&now);
}

unordered_map<Usuario *, vector<Produtos *>> ConcreteMemento::state() const {
    return this->state_;
}

std::string ConcreteMemento::date() const  {
    return this->date_;
}

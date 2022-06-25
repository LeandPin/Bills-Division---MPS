//
// Created by Gabriel on 31/05/2022.
//

#ifndef MPS___FORK_CARETAKER_H
#define MPS___FORK_CARETAKER_H

#include "memento/ConcreteMemento.h"
#include "facade/ListaDeCompras.h"

class Caretaker {
private:
    vector<ConcreteMemento *> mementos_;
    ListaDeCompras *originator_;

public:
    explicit Caretaker(ListaDeCompras *originator);

    void backup();
    void undo();
};


#endif //MPS___FORK_CARETAKER_H

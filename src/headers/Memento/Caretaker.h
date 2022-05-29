//
// Created by Gabriel on 29/05/2022.
//

#ifndef MPS___FORK_CARETAKER_H
#define MPS___FORK_CARETAKER_H


#include "Memento.h"
#include "../Facade/ListaDeCompras.h"

class Caretaker {
private:
    vector<Memento*> mementos_;
    ListaDeCompras* listaDeCompras_;

public:
    Caretaker(ListaDeCompras* originator);
    void backup();
    void undo();
};


#endif //MPS___FORK_CARETAKER_H

//
// Created by Gabriel on 29/05/2022.
//

#ifndef MPS___FORK_LISTADECOMPRAMEMENTO_H
#define MPS___FORK_LISTADECOMPRAMEMENTO_H

#include "Memento.h"

class ListaDeCompraMemento: public Memento {
private:
    string date_;
    unordered_map<Usuario*, vector<Produtos*>> state_;

public:
    explicit ListaDeCompraMemento(unordered_map<Usuario*, vector<Produtos*>> state);
    unordered_map<Usuario*, vector<Produtos*>> state() const override;
    string date() const override;
};


#endif //MPS___FORK_LISTADECOMPRAMEMENTO_H

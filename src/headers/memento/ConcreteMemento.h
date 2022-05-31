//
// Created by Gabriel on 31/05/2022.
//

#ifndef MPS___FORK_CONCRETEMEMENTO_H
#define MPS___FORK_CONCRETEMEMENTO_H

#include "interface.h"

class ConcreteMemento: public interface {
private:
    unordered_map<Usuario*, vector<Produtos*>> state_;
    string date_;

public:
    explicit ConcreteMemento(unordered_map<Usuario*, vector<Produtos*>> state);

    unordered_map<Usuario*, vector<Produtos*>> state() const override;

    std::string date() const override;
};


#endif //MPS___FORK_CONCRETEMEMENTO_H

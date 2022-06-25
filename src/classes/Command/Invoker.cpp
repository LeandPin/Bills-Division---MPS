//
// Created by Gabriel on 29/05/2022.
//

#include "Command/Invoker.h"

void Invoker::AddUser(CommandInterface* command) {
    this->add_user_ = command;
}

void Invoker::AddProductToUser(CommandInterface* command) {
    this->add_product_to_user_ = command;
}

Invoker::~Invoker() {
    delete add_user_;
    delete add_product_to_user_;
}

void Invoker::Do() {
    if (this->add_user_) {
        add_user_->execute();
        delete add_user_;
    }
    if (this->add_product_to_user_) {
        add_product_to_user_->execute();
        delete add_product_to_user_;
    }
}


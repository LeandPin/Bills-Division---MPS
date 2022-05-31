//
// Created by Gabriel on 29/05/2022.
//

#include "Command/Invoker.h"

void Invoker::AddUser(CommandInterface* command) {
    this->AddUser_ = command;
}

void Invoker::AddProductToUser(CommandInterface* command) {
    this->AddProductToUser_ = command;
}

Invoker::~Invoker() {
    delete AddUser_;
    delete AddProductToUser_;
}

void Invoker::Do() {
    if (this->AddUser_) {
        AddUser_->Execute();
        delete AddUser_;
    }
    if (this->AddProductToUser_) {
        AddProductToUser_->Execute();
        delete AddProductToUser_;
    }
}


//
// Created by Gabriel on 29/05/2022.
//

#ifndef MPS___FORK_COMMANDINTERFACE_H
#define MPS___FORK_COMMANDINTERFACE_H


class CommandInterface {
public:
    virtual ~CommandInterface() = default;
    virtual void execute() const = 0;
};


#endif //MPS___FORK_COMMANDINTERFACE_H

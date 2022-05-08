//
// Created by Gabriel on 24/04/2022.
//

#ifndef MPS_USERNAMEEXCEPTION_H
#define MPS_USERNAMEEXCEPTION_H

#include <exception>

class UserNameException: public std::exception {
public:
    const char* what() const noexcept override;
    UserNameException();
};



#endif //MPS_USERNAMEEXCEPTION_H

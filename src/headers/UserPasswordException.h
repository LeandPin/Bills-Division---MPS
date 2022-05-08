//
// Created by Gabriel on 24/04/2022.
//

#ifndef MPS_USERPASSWORDEXCEPTION_H
#define MPS_USERPASSWORDEXCEPTION_H

#include <exception>

class UserPasswordException: public std::exception {
public:
    const char * what() const noexcept override;
    UserPasswordException();
};


#endif //MPS_USERPASSWORDEXCEPTION_H

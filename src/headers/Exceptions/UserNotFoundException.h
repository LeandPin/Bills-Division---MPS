//
// Created by Gabriel on 24/04/2022.
//

#ifndef MPS_USERNOTFOUNDEXCEPTION_H
#define MPS_USERNOTFOUNDEXCEPTION_H

#include <exception>


class UserNotFoundException: public std::exception {
public:
    const char * what() const noexcept override;
    UserNotFoundException();
};


#endif //MPS_USERNOTFOUNDEXCEPTION_H

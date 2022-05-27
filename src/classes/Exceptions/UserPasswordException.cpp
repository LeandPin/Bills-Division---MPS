//
// Created by Gabriel on 24/04/2022.
//

#include "Exceptions/UserPasswordException.h"

const char *UserPasswordException::what() const noexcept {
    {
        return "UserNameException";
    }
}

UserPasswordException::UserPasswordException() {

}
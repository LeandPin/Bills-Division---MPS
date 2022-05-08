//
// Created by Gabriel on 24/04/2022.
//

#include "../headers/UserPasswordException.h"

const char *UserPasswordException::what() const noexcept {
    {
        return "UserNameException";
    }
}

UserPasswordException::UserPasswordException() {

}
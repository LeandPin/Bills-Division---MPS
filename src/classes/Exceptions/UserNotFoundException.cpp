//
// Created by Gabriel on 24/04/2022.
//

#include "Exceptions/UserNotFoundException.h"

const char *UserNotFoundException::what() const noexcept {
    {
        return "UserNotFoundException";
    }
}

UserNotFoundException::UserNotFoundException() {

}
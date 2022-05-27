//
// Created by Gabriel on 24/04/2022.
//

#include "Exceptions/UserNameException.h"

const char *UserNameException::what() const noexcept {
    {
        return "UserNameException";
    }
}

UserNameException::UserNameException() {

}

#include "BaseException.hpp"

BaseException::BaseException(const char* message):
    message(message) {}

const char* BaseException::what() const noexcept {
    return "BaseException";
}
#include "CreationException.hpp"

CreationException::CreationException(const char* message):
    BaseException(message) {}

const char* CreationException::what() const noexcept {
    return message.empty() ? "CreationException" : message.c_str();
}
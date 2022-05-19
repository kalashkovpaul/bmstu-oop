#include "uploadExceptions.hpp"

BaseStreamException::BaseStreamException(const char* message):
    BaseException(message) {}

const char* BaseStreamException::what() const noexcept {
    return message.empty() ? "Uploader::BaseStreamException" : message.c_str();
}

OpenStreamException::OpenStreamException(const char* message):
    BaseStreamException(message) {}

const char* OpenStreamException::what() const noexcept {
    return message.empty() ? "Uploader::OpenStreamException" : message.c_str();
}

ReadStreamException::ReadStreamException(const char* message):
    BaseStreamException(message) {}

const char* ReadStreamException::what() const noexcept {
    return message.empty() ? "Uploader::ReadStreamException" : message.c_str();
}

FileFormatException::FileFormatException(const char* message):
    BaseStreamException(message) {}

const char* FileFormatException::what() const noexcept {
    return message.empty() ? "Uploader::FileFormatException" : message.c_str();
}
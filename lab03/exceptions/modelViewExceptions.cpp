#include "exceptions/modelViewExceptions.hpp"

BaseModelViewException::BaseModelViewException(const char* message):
    BaseException(message) {}

const char* BaseModelViewException::what() const noexcept {
    return message.empty() ? "ModelView::BaseModelViewException" : message.c_str();
}

ModelViewOutOfRangeException::ModelViewOutOfRangeException(const char* message):
    BaseModelViewException(message) {}

const char* ModelViewOutOfRangeException::what() const noexcept {
    return message.empty() ? "ModelView::ModelViewOutOfRangeException" : message.c_str();
}
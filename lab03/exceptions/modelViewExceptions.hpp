#ifndef MODEL_VIEW_EXCEPTIONS_HPP_

#define MODEL_VIEW_EXCEPTIONS_HPP_

#include "exceptions/BaseException.hpp"

class BaseModelViewException: public BaseException {
public:
    explicit BaseModelViewException() = default;
    explicit BaseModelViewException(const char* message);

    const char* what() const noexcept override;
};

class ModelViewOutOfRangeException: public BaseModelViewException {
public:
    explicit ModelViewOutOfRangeException() = default;
    explicit ModelViewOutOfRangeException(const char* message);

    const char* what() const noexcept override;
};

#endif
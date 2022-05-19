#ifndef CREATION_EXCEPTION_HPP_

#define CREATION_EXCEPTION_HPP_

#include "BaseException.hpp"

class CreationException: public BaseException {
public:
    explicit CreationException() = default;
    explicit CreationException(const char* message);

    const char* what() const noexcept override; 
};

#endif
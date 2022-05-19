#ifndef UPLOAD_EXCEPTIONS_HPP_

#define UPLOAD_EXCEPTIONS_HPP_

#include "BaseException.hpp"

class BaseStreamException: public BaseException {
public:
    explicit BaseStreamException() = default;
    explicit BaseStreamException(const char* message);

    const char* what() const noexcept override;
};

class OpenStreamException: public BaseStreamException {
public:
    explicit OpenStreamException() = default;
    explicit OpenStreamException(const char* message);

    const char* what() const noexcept override;
};

class ReadStreamException: public BaseStreamException {
public:
    explicit ReadStreamException() = default;
    explicit ReadStreamException(const char* message);

    const char* what() const noexcept override;
};

class FileFormatException: public BaseStreamException {
public:
    explicit FileFormatException() = default;
    explicit FileFormatException(const char* message);

    const char* what() const noexcept override;
};

#endif
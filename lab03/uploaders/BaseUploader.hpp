#ifndef BASE_UPLOADER_HPP_

#define BASE_UPLOADER_HPP_

#include <fstream>

#include "Model.hpp"

class BaseUploader {
public:
    virtual ~BaseUploader() noexcept = default;

    virtual void open() = 0;
    virtual bool isOpen() const = 0;
    virtual void close() = 0;
    
    virtual const Model getModel() = 0;
};

#endif
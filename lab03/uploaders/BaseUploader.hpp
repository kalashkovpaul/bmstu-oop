#ifndef BASE_UPLOADER_HPP_

#define BASE_UPLOADER_HPP_

#include <fstream>
#include <memory>

#include "objects/BaseModel.hpp"
class Model;

class BaseUploader {
public:
    virtual ~BaseUploader() noexcept = default;

    virtual void open() = 0;
    virtual bool isOpen() const = 0;
    virtual void close() = 0;
    
    virtual void getModel(const std::shared_ptr<BaseModel>& model) = 0;
};

#endif
#ifndef UPLOADER_HPP_

#define UPLOADER_HPP_

#include <fstream>
#include "BaseUploader.hpp"

class Uploader: public BaseUploader {
public:
    explicit Uploader(std::string filename);
    ~Uploader() override;

    void open() override;
    bool isOpen() const override;
    void close() override;

    const Model getModel() override;

private:
    std::string filename;
    std::ifstream file;
};

#endif
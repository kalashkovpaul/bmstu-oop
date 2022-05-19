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

    void getModel(const std::shared_ptr<Model>& model) override;

private:
    std::string filename;
    std::ifstream file;
};

#endif
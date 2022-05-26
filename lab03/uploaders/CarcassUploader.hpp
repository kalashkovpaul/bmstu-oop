#ifndef UPLOADER_HPP_

#define UPLOADER_HPP_

#include <fstream>
#include <memory>
#include "BaseUploader.hpp"
#include "math3D/Edge/Edge.h"
#include "math3D/Point3D/Point3D.h"
#include "objects/CarcassModelImplementator.hpp"

class CarcassUploader: public BaseUploader {
public:
    explicit CarcassUploader(std::string filename);
    ~CarcassUploader() override;

    void open() override;
    bool isOpen() const override;
    void close() override;

    void getModel(const std::shared_ptr<BaseModel>& model) override;

private:
    std::string filename;
    std::ifstream file;
};

#endif
#ifndef UPLOAD_MANAGER_HPP_

#define UPLOAD_MANAGER_HPP_

#include "BaseManager.hpp"

class UploadManager: BaseManager {
    std::string getType() override;

    void run(std::string filename);
    
};

#endif
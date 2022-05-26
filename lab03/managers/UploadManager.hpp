#ifndef UPLOAD_MANAGER_HPP_

#define UPLOAD_MANAGER_HPP_

#include <memory>
#include <string>
#include "uploaders/CarcassUploader.hpp"
#include "creators/creators.hpp"

class UploadManager {
public:
    static std::shared_ptr<SceneObject> uploadModel(Solution& solution, std::string filename);

private:
    UploadManager() = default;    
};

#endif
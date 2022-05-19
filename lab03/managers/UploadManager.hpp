#ifndef UPLOAD_MANAGER_HPP_

#define UPLOAD_MANAGER_HPP_

#include <memory>
#include "uploaders/Uploader.hpp"

class UploadManager {
public:
    static void uploadModel(BaseUploader& uploader, const std::shared_ptr<Model>& model);

private:
    UploadManager() = default;    
};

#endif
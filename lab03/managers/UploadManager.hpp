#ifndef UPLOAD_MANAGER_HPP_

#define UPLOAD_MANAGER_HPP_

#include <memory>
#include "uploaders/CarcassUploader.hpp"

class UploadManager {
public:
    static void uploadModel(BaseUploader& uploader, const std::shared_ptr<BaseModel>& model);

private:
    UploadManager() = default;    
};

#endif
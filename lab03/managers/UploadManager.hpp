#ifndef UPLOAD_MANAGER_HPP_

#define UPLOAD_MANAGER_HPP_

#include "uploaders/Uploader.hpp"

class UploadManager {
public:
    static Model uploadModel(BaseUploader& uploader);

private:
    UploadManager() = default;    
};

#endif
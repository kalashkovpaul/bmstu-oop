#include "UploadManager.hpp"

void UploadManager::uploadModel(BaseUploader& uploader, const std::shared_ptr<BaseModel>& model) {
    uploader.open();
    uploader.getModel(model);
    uploader.close();
}
#include "UploadManager.hpp"

void UploadManager::uploadModel(BaseUploader& uploader, const std::shared_ptr<Model>& model) {
    uploader.open();
    uploader.getModel(model);
    uploader.close();
}
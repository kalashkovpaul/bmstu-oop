#include "UploadManager.hpp"

Model UploadManager::uploadModel(BaseUploader& uploader) {
    uploader.open();
    auto model = uploader.getModel();
    uploader.close();

    return model;
}
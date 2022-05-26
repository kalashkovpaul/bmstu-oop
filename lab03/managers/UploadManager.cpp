#include "UploadManager.hpp"

std::shared_ptr<SceneObject> UploadManager::uploadModel(Solution& solution, std::string filename) {
    CarcassUploader uploader(filename);
    const std::unique_ptr<Creator> cr = solution.create(modelId);
    const std::shared_ptr<SceneObject> object = cr->createSceneObject();
    const std::shared_ptr<BaseModel> model = std::dynamic_pointer_cast<BaseModel>(object);
    uploader.open();
    uploader.getModel(model);
    uploader.close();
    return object;
}
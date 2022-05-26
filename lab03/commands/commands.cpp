#include "commands.hpp" 

Scene& Command::getScene(Facade& facade) {
    return facade.scene;
}

ModelView& Command::getModelView(Facade& facade) {
    return facade.modelView;
}

Solution& Command::getSolution(Facade& facade) {
    return facade.solution;
}

namespace commands {

UploadView::UploadView(const std::string filename): 
    filename(filename) {}

void UploadView::execute(Facade& facade) {
    CarcassUploader uploader(filename);
    ModelView& modelView = getModelView(facade);
    Solution& solution = getSolution(facade);
    const std::unique_ptr<Creator> cr = solution.create(modelId);
    const std::shared_ptr<SceneObject> object = cr->createSceneObject();
    const std::shared_ptr<BaseModel> model = std::dynamic_pointer_cast<BaseModel>(object);
    UploadManager::uploadModel(uploader, model);
    modelView.addView(object);
}

DeleteView::DeleteView(const std::size_t viewIndex): 
    viewIndex(viewIndex) {}

void DeleteView::execute(Facade& facade) {
    ModelView& modelView = getModelView(facade);
    modelView.deleteView(viewIndex);
}

AddModel::AddModel(const std::size_t viewIndex): 
    viewIndex(viewIndex) {}

void AddModel::execute(Facade& facade) {
    Scene& scene = getScene(facade);
    ModelView& modelView = getModelView(facade);
    const std::shared_ptr<SceneObject>& view = modelView[viewIndex];

    scene.addModel(view->clone());
}

DeleteModel::DeleteModel(const std::size_t modelIndex): 
    modelIndex(modelIndex) {}

void DeleteModel::execute(Facade& facade) {
    Scene& scene = getScene(facade);
    scene.deleteModel(modelIndex);
}

AddCamera::AddCamera() {}

void AddCamera::execute(Facade& facade) {
    Scene& scene = getScene(facade);
    Solution& solution = getSolution(facade);
    std::unique_ptr<Creator> cr = solution.create(cameraId);
    scene.addCamera((cr->createSceneObject()));
}

DeleteCamera::DeleteCamera(const std::size_t cameraIndex): 
    cameraIndex(cameraIndex) {}

void DeleteCamera::execute(Facade& facade) {
    Scene& scene = getScene(facade);
    scene.deleteCamera(cameraIndex);
}

TranslateModel::TranslateModel(const ssize_t modelIndex, const Point3D<double>& point): 
    modelIndex(modelIndex),
    point(point) {}

void TranslateModel::execute(Facade& facade) {
    dimensionalTransformations::Translation move(point);
    Transformation transformation(move);
    Scene& scene = getScene(facade);
    ModelManager::transform(scene, transformation, modelIndex);
}

RotateModelOX::RotateModelOX(const ssize_t modelIndex, const double angle): 
    modelIndex(modelIndex),
    angle(angle) { }

void RotateModelOX::execute(Facade& facade) {
    dimensionalTransformations::RotationOX rotation(angle);
    Transformation transformation(rotation);
    Scene& scene = getScene(facade);
    ModelManager::transform(scene, transformation, modelIndex);
}

RotateModelOY::RotateModelOY(const ssize_t modelIndex, const double angle): 
    modelIndex(modelIndex),
    angle(angle) {}

void RotateModelOY::execute(Facade& facade) {
    dimensionalTransformations::RotationOY rotation(angle);
    Transformation transformation(rotation);
    Scene& scene = getScene(facade);
    ModelManager::transform(scene, transformation, modelIndex);
}

RotateModelOZ::RotateModelOZ(const ssize_t modelIndex, const double angle): 
    modelIndex(modelIndex),
    angle(angle) {}

void RotateModelOZ::execute(Facade& facade) {
    dimensionalTransformations::RotationOZ rotation(angle);
    Transformation transformation(rotation);
    Scene& scene = getScene(facade);
    ModelManager::transform(scene, transformation, modelIndex);
}

ScaleModel::ScaleModel(const ssize_t modelIndex, const double scaleFactor): 
    modelIndex(modelIndex),
    scaleFactor(scaleFactor) {}

void ScaleModel::execute(Facade& facade) {
    dimensionalTransformations::Scaling scale(scaleFactor);
    Transformation transformation(scale);
    Scene& scene = getScene(facade);
    ModelManager::transform(scene, transformation, modelIndex);
}

Draw::Draw(const ssize_t cameraIndex, Drawer& drawer): 
    cameraIndex(cameraIndex),
    drawer(drawer) {}

void Draw::execute(Facade& facade) {
    Scene& scene = getScene(facade);
    DrawManager::draw(scene, drawer, std::dynamic_pointer_cast<Camera>(scene.getCamera(cameraIndex)));
}

RollLook::RollLook(const std::size_t cameraIndex, const double angle): 
    cameraIndex(cameraIndex),
    angle(angle) {}

void RollLook::execute(Facade& facade) {
    cameraCommands::RollLook rollLook(angle);
    Scene& scene = getScene(facade);
    CameraManager::transform(scene, rollLook, cameraIndex);
}

RollRight::RollRight(const std::size_t cameraIndex, const double angle): 
    cameraIndex(cameraIndex),
    angle(angle) {}

void RollRight::execute(Facade& facade) {
    cameraCommands::RollRight rollRight(angle);
    Scene& scene = getScene(facade);
    CameraManager::transform(scene, rollRight, cameraIndex);
}

RollUp::RollUp(const std::size_t cameraIndex, const double angle): 
    cameraIndex(cameraIndex),
    angle(angle) {}

void RollUp::execute(Facade& facade) {
    cameraCommands::RollUp rollUp(angle);
    Scene& scene = getScene(facade);
    CameraManager::transform(scene, rollUp, cameraIndex);
}

}


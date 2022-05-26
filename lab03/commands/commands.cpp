#include "commands.hpp" 

namespace commands {

UploadView::UploadView(const std::string filename): 
    filename(filename) {}

void UploadView::execute(ModelView& modelView, Solution& solution) {
    modelView.addView(UploadManager::uploadModel(solution, filename));
}

DeleteView::DeleteView(const std::size_t viewIndex): 
    viewIndex(viewIndex) {}

void DeleteView::execute(ModelView& modelView) {
    modelView.deleteView(viewIndex);
}

AddModel::AddModel(const std::size_t viewIndex): 
    viewIndex(viewIndex) {}

void AddModel::execute(Scene& scene, ModelView& modelView) {
    SceneManager::addModel(scene, modelView[viewIndex]);
}

DeleteModel::DeleteModel(const std::size_t modelIndex): 
    modelIndex(modelIndex) {}

void DeleteModel::execute(Scene& scene) {
    scene.deleteModel(modelIndex);
}

AddCamera::AddCamera() {}

void AddCamera::execute(Scene& scene, Solution& solution) {
    SceneManager::addCamera(scene, solution);
}

DeleteCamera::DeleteCamera(const std::size_t cameraIndex): 
    cameraIndex(cameraIndex) {}

void DeleteCamera::execute(Scene& scene) {
    scene.deleteCamera(cameraIndex);
}

TranslateModel::TranslateModel(const ssize_t modelIndex, const Point3D<double>& point): 
    modelIndex(modelIndex),
    point(point) {}

void TranslateModel::execute(Scene& scene) {
    dimensionalTransformations::Translation move(point);
    Transformation transformation(move);
    ModelManager::transform(scene, transformation, modelIndex);
}

RotateModelOX::RotateModelOX(const ssize_t modelIndex, const double angle): 
    modelIndex(modelIndex),
    angle(angle) { }

void RotateModelOX::execute(Scene& scene) {
    dimensionalTransformations::RotationOX rotation(angle);
    Transformation transformation(rotation);
    ModelManager::transform(scene, transformation, modelIndex);
}

RotateModelOY::RotateModelOY(const ssize_t modelIndex, const double angle): 
    modelIndex(modelIndex),
    angle(angle) {}

void RotateModelOY::execute(Scene& scene) {
    dimensionalTransformations::RotationOY rotation(angle);
    Transformation transformation(rotation);
    ModelManager::transform(scene, transformation, modelIndex);
}

RotateModelOZ::RotateModelOZ(const ssize_t modelIndex, const double angle): 
    modelIndex(modelIndex),
    angle(angle) {}

void RotateModelOZ::execute(Scene& scene) {
    dimensionalTransformations::RotationOZ rotation(angle);
    Transformation transformation(rotation);
    ModelManager::transform(scene, transformation, modelIndex);
}

ScaleModel::ScaleModel(const ssize_t modelIndex, const double scaleFactor): 
    modelIndex(modelIndex),
    scaleFactor(scaleFactor) {}

void ScaleModel::execute(Scene& scene) {
    dimensionalTransformations::Scaling scale(scaleFactor);
    Transformation transformation(scale);
    ModelManager::transform(scene, transformation, modelIndex);
}

Draw::Draw(const ssize_t cameraIndex, Drawer& drawer): 
    cameraIndex(cameraIndex),
    drawer(drawer) {}

void Draw::execute(Scene& scene) {
    DrawManager::draw(scene, drawer, std::dynamic_pointer_cast<Camera>(scene.getCamera(cameraIndex)));
}

RollLook::RollLook(const std::size_t cameraIndex, const double angle): 
    cameraIndex(cameraIndex),
    angle(angle) {}

void RollLook::execute(Scene& scene) {
    cameraCommands::RollLook rollLook(angle);
    CameraManager::transform(scene, rollLook, cameraIndex);
}

RollRight::RollRight(const std::size_t cameraIndex, const double angle): 
    cameraIndex(cameraIndex),
    angle(angle) {}

void RollRight::execute(Scene& scene) {
    cameraCommands::RollRight rollRight(angle);
    CameraManager::transform(scene, rollRight, cameraIndex);
}

RollUp::RollUp(const std::size_t cameraIndex, const double angle): 
    cameraIndex(cameraIndex),
    angle(angle) {}

void RollUp::execute(Scene& scene) {
    cameraCommands::RollUp rollUp(angle);
    CameraManager::transform(scene, rollUp, cameraIndex);
}

}


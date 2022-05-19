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
    std::cout << "UploadView is executing" << std::endl; // TODO
    Uploader uploader(filename);
    ModelView& modelView = getModelView(facade);
    Solution& solution = getSolution(facade);
    const std::unique_ptr<Creator> cr = solution.create(modelId);
    const std::shared_ptr<SceneObject> object = cr->createSceneObject();
    const std::shared_ptr<Model> model = std::dynamic_pointer_cast<Model>(object);
    UploadManager::uploadModel(uploader, model);
    modelView.addView(model);
}

DeleteView::DeleteView(const std::size_t viewIndex): 
    viewIndex(viewIndex) {}

void DeleteView::execute(Facade& facade) {
    std::cout << "DeleteView is executing" << std::endl;// TODO
    ModelView& modelView = getModelView(facade);
    modelView.deleteView(viewIndex);
}

AddModel::AddModel(const std::size_t viewIndex): 
    viewIndex(viewIndex) {}

void AddModel::execute(Facade& facade) {
    std::cout << "AddModel is executing" << std::endl;// TODO
    Scene& scene = getScene(facade);
    // Solution& solution = getSolution(facade);
    // std::unique_ptr<Creator> cr = solution.create(modelId);
    // scene.addModel((cr->createSceneObject()));
    ModelView& modelView = getModelView(facade);
    scene.addModel(modelView[viewIndex]);
}

DeleteModel::DeleteModel(const std::size_t modelIndex): 
    modelIndex(modelIndex) {}

void DeleteModel::execute(Facade& facade) {
    std::cout << "DeleteModel is executing" << std::endl;// TODO
    Scene& scene = getScene(facade);
    scene.deleteModel(modelIndex);
}

AddCamera::AddCamera() {}

void AddCamera::execute(Facade& facade) {
    std::cout << "AddCamera is executing" << std::endl;// TODO
    Scene& scene = getScene(facade);
    Solution& solution = getSolution(facade);
    std::unique_ptr<Creator> cr = solution.create(cameraId);
    scene.addCamera((cr->createSceneObject()));
}

DeleteCamera::DeleteCamera(const std::size_t cameraIndex): 
    cameraIndex(cameraIndex) {}

void DeleteCamera::execute(Facade& facade) {
    std::cout << "DeleteCamera is executing" << std::endl;// TODO
    Scene& scene = getScene(facade);
    scene.deleteCamera(cameraIndex);
}

TranslateModel::TranslateModel(const std::size_t modelIndex, const Point3D<double>& point): 
    modelIndex(modelIndex),
    point(point) {}

void TranslateModel::execute(Facade& facade) {
    std::cout << "TranslateModel is executing" << std::endl;// TODO
    dimensionalTransformations::Translation move(point);
    Transformation transformation(move);
    Scene& scene = getScene(facade);
    ModelManager::transform(scene, transformation, modelIndex);
}

RotateModelOX::RotateModelOX(const std::size_t modelIndex, const double angle): 
    modelIndex(modelIndex),
    angle(angle) {}

void RotateModelOX::execute(Facade& facade) {
    std::cout << "RotateModelOX is executing" << std::endl;// TODO
    dimensionalTransformations::RotationOX rotation(angle);
    Transformation transformation(rotation);
    Scene& scene = getScene(facade);
    ModelManager::transform(scene, transformation, modelIndex);
}

RotateModelOY::RotateModelOY(const std::size_t modelIndex, const double angle): 
    modelIndex(modelIndex),
    angle(angle) {}

void RotateModelOY::execute(Facade& facade) {
    std::cout << "RotateModelOY is executing" << std::endl;// TODO
    dimensionalTransformations::RotationOY rotation(angle);
    Transformation transformation(rotation);
    Scene& scene = getScene(facade);
    ModelManager::transform(scene, transformation, modelIndex);
}

RotateModelOZ::RotateModelOZ(const std::size_t modelIndex, const double angle): 
    modelIndex(modelIndex),
    angle(angle) {}

void RotateModelOZ::execute(Facade& facade) {
    std::cout << "RotateModelOZ is executing" << std::endl;// TODO
    dimensionalTransformations::RotationOZ rotation(angle);
    Transformation transformation(rotation);
    Scene& scene = getScene(facade);
    ModelManager::transform(scene, transformation, modelIndex);
}

ScaleModel::ScaleModel(const std::size_t modelIndex, const double scaleFactor): 
    modelIndex(modelIndex),
    scaleFactor(scaleFactor) {}

void ScaleModel::execute(Facade& facade) {
    std::cout << "ScaleModel is executing" << std::endl;// TODO
    dimensionalTransformations::Scaling scale(scaleFactor);
    Transformation transformation(scale);
    Scene& scene = getScene(facade);
    ModelManager::transform(scene, transformation, modelIndex);
}

Draw::Draw(const std::size_t cameraIndex, Drawer& drawer): 
    cameraIndex(cameraIndex),
    drawer(drawer) {}

void Draw::execute(Facade& facade) {
    std::cout << "Draw is executing" << std::endl;// TODO
    Scene& scene = getScene(facade);
    DrawManager::draw(scene, drawer, std::dynamic_pointer_cast<Camera>(scene.getCamera(cameraIndex)));
}

RollLook::RollLook(const std::size_t cameraIndex, const double angle): 
    cameraIndex(cameraIndex),
    angle(angle) {}

void RollLook::execute(Facade& facade) {
    std::cout << "RollLook is executing" << std::endl;// TODO
}

RollRight::RollRight(const std::size_t cameraIndex, const double angle): 
    cameraIndex(cameraIndex),
    angle(angle) {}

void RollRight::execute(Facade& facade) {
    std::cout << "RollRight is executing" << std::endl;// TODO
}

RollUp::RollUp(const std::size_t cameraIndex, const double angle): 
    cameraIndex(cameraIndex),
    angle(angle) {}

void RollUp::execute(Facade& facade) {
    std::cout << "RollUp is executing" << std::endl;// TODO
}

}


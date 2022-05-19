#include "commands.hpp" 

namespace commands {

UploadView::UploadView(const std::string filename): 
    filename(filename) {}

void UploadView::execute() {
    std::cout << "UploadView is executing" << std::endl; // TODO
}

DeleteView::DeleteView(const std::size_t viewIndex): 
    viewIndex(viewIndex) {}

void DeleteView::execute() {
    std::cout << "DeleteView is executing" << std::endl;// TODO
}

AddModel::AddModel(const std::size_t viewIndex): 
    viewIndex(viewIndex) {}

void AddModel::execute() {
    std::cout << "AddModel is executing" << std::endl;// TODO
}

DeleteModel::DeleteModel(const std::size_t modelIndex): 
    modelIndex(modelIndex) {}

void DeleteModel::execute() {
    std::cout << "DeleteModel is executing" << std::endl;// TODO
}

AddCamera::AddCamera() {}

void AddCamera::execute() {
    std::cout << "AddCamera is executing" << std::endl;// TODO
}

DeleteCamera::DeleteCamera(const std::size_t cameraIndex): 
    cameraIndex(cameraIndex) {}

void DeleteCamera::execute() {
    std::cout << "DeleteCamera is executing" << std::endl;// TODO
}

TranslateModel::TranslateModel(\
    const std::size_t modelIndex, const Point3D<double>& point): 
    modelIndex(modelIndex),
    point(point) {}

void TranslateModel::execute() {
    std::cout << "TranslateModel is executing" << std::endl;// TODO
}

RotateModelOX::RotateModelOX(const std::size_t modelIndex, const double angle): 
    modelIndex(modelIndex),
    angle(angle) {}

void RotateModelOX::execute() {
    std::cout << "RotateModelOX is executing" << std::endl;// TODO
}

RotateModelOY::RotateModelOY(\
    const std::size_t modelIndex, const double angle): 
    
    modelIndex(modelIndex),
    angle(angle) {}

void RotateModelOY::execute() {
    std::cout << "RotateModelOY is executing" << std::endl;// TODO
}

RotateModelOZ::RotateModelOZ(const std::size_t modelIndex, const double angle): 
    modelIndex(modelIndex),
    angle(angle) {}

void RotateModelOZ::execute() {
    std::cout << "RotateModelOZ is executing" << std::endl;// TODO
}

ScaleModel::ScaleModel(const std::size_t modelIndex, const double scaleFactor): 
    modelIndex(modelIndex),
    scaleFactor(scaleFactor) {}

void ScaleModel::execute() {
    std::cout << "ScaleModel is executing" << std::endl;// TODO
}

Draw::Draw(const std::size_t cameraIndex, const Drawer& drawer): 
    cameraIndex(cameraIndex),
    drawer(drawer) {}

void Draw::execute() {
    std::cout << "Draw is executing" << std::endl;// TODO
}

RollLook::RollLook(const std::size_t cameraIndex, const double angle): 
    cameraIndex(cameraIndex),
    angle(angle) {}

void RollLook::execute() {
    std::cout << "RollLook is executing" << std::endl;// TODO
}

RollRight::RollRight(const std::size_t cameraIndex, const double angle): 
    cameraIndex(cameraIndex),
    angle(angle) {}

void RollRight::execute() {
    std::cout << "RollRight is executing" << std::endl;// TODO
}

RollUp::RollUp(const std::size_t cameraIndex, const double angle): 
    cameraIndex(cameraIndex),
    angle(angle) {}

void RollUp::execute() {
    std::cout << "RollUp is executing" << std::endl;// TODO
}

}


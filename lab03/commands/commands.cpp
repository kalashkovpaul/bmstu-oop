#include "commands.hpp" 

namespace commands {

UploadView::UploadView(const std::string filename): 
    this.filename(filename) {}

void UploadView::execute() {
    // TODO
}

DeleteView::DeleteView(const std::size_t viewIndex): 
    act(action),
    this.viewIndex(viewIndex) {}

void DeleteView::execute() {
    // TODO
}

AddModel::AddModel(const std::size_t viewIndex): 
    act(action),
    this.viewIndex(viewIndex) {}

void AddModel::execute() {
    // TODO
}

DeleteModel::DeleteModel(const std::size_t modelIndex): 
    act(action),
    this.modelIndex(modelIndex) {}

void DeleteModel::execute() {
    // TODO
}

AddCamera::AddCamera(Action action): 
    act(action) {}

void AddCamera::execute() {
    // TODO
}

DeleteCamera::DeleteCamera(const std::size_t cameraIndex): 
    act(action),
    this.cameraIndex(cameraIndex) {}

void DeleteCamera::execute() {
    // TODO
}

TranslateModel::TranslateModel(\
    const std::size_t modelIndex, const Point3D<double>& point): 
    this.act(action),
    this.modelIndex(modelIndex),
    this.point(point) {}

void TranslateModel::execute() {
    // TODO
}

RotateModelOX::RotateModelOX(\
    const std::size_t modelIndex, const double angle): 
    this.act(action),
    this.modelIndex(modelIndex),
    this.angle(angle) {}

void RotateModelOX::execute() {
    // TODO
}


RotateModelOX::RotateModelOX(\
    const std::size_t modelIndex, const double angle): 
    this.act(action),
    this.modelIndex(modelIndex),
    this.angle(angle) {}

void RotateModelOX::execute() {
    // TODO
}

RotateModelOY::RotateModelOY(\
    const std::size_t modelIndex, const double angle): 
    this.act(action),
    this.modelIndex(modelIndex),
    this.angle(angle) {}

void RotateModelOY::execute() {
    // TODO
}

RotateModelOZ::RotateModelOZ(\
    const std::size_t modelIndex, const double angle): 
    this.act(action),
    this.modelIndex(modelIndex),
    this.angle(angle) {}

void RotateModelOZ::execute() {
    // TODO
}

RotateModelOZ::RotateModelOZ(\
    const std::size_t modelIndex, const double angle): 
    this.act(action),
    this.modelIndex(modelIndex),
    this.angle(angle) {}

void RotateModelOZ::execute() {
    // TODO
}

ScaleModel::ScaleModel(\
    const std::size_t modelIndex, const double scaleFactor): 
    this.act(action),
    this.modelIndex(modelIndex),
    this.scaleFactor(scaleFactor) {}

void ScaleModel::execute() {
    // TODO
}

Draw::Draw(\
    const std::size_t cameraIndex, const Drawer& drawer): 
    this.act(action),
    this.cameraIndex(cameraIndex),
    this.drawer(drawer) {}

void Draw::execute() {
    // TODO
}

RollLook::RollLook(\
    const std::size_t cameraIndex, const Drawer& drawer): 
    this.act(action),
    this.cameraIndex(cameraIndex),
    this.angle(angle) {}

void RollLook::execute() {
    // TODO
}

RollRight::RollRight(\
    const std::size_t cameraIndex, const Drawer& drawer): 
    this.act(action),
    this.cameraIndex(cameraIndex),
    this.angle(angle) {}

void RollRight::execute() {
    // TODO
}

RollUp::RollUp(\
    const std::size_t cameraIndex, const Drawer& drawer): 
    this.act(action),
    this.cameraIndex(cameraIndex),
    this.angle(angle) {}

void RollUp::execute() {
    // TODO
}

}


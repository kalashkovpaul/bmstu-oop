#include "commands.h"

namespace commands {

template <typename Receiver>
UploadView<Receiver>::UploadView(const Action action, const std::string filename): 
    act(action),
    this.filename(filename) {}

template <typename Receiver>
void UploadView<Receiver>::execute(const std::shared_ptr<Receiver> r) {
    ((*r).*act)(filename);
}

template <typename Receiver>
DeleteView<Receiver>::DeleteView(const Action action, const std::size_t viewIndex): 
    act(action),
    this.viewIndex(viewIndex) {}

template <typename Receiver>
void DeleteView<Receiver>::execute(std::shared_ptr<Receiver> r) {
    ((*r).*act)(viewIndex);
}

template <typename Receiver>
AddModel<Receiver>::AddModel(const Action action, const std::size_t viewIndex): 
    act(action),
    this.viewIndex(viewIndex) {}

template <typename Receiver>
void AddModel<Receiver>::execute(const std::shared_ptr<Receiver> r) {
    ((*r).*act)(viewIndex);
}

template <typename Receiver>
DeleteModel<Receiver>::DeleteModel(const Action action, const std::size_t modelIndex): 
    act(action),
    this.modelIndex(modelIndex) {}

template <typename Receiver>
void DeleteModel<Receiver>::execute(const std::shared_ptr<Receiver> r) {
    ((*r).*act)(modelIndex);
}

template <typename Receiver>
AddCamera<Receiver>::AddCamera(Action action): 
    act(action) {}

template <typename Receiver>
void AddCamera<Receiver>::execute(std::shared_ptr<Receiver> r) {
    ((*r).*act)();
}

template <typename Receiver>
DeleteCamera<Receiver>::DeleteCamera(const Action action, const std::size_t cameraIndex): 
    act(action),
    this.cameraIndex(cameraIndex) {}

template <typename Receiver>
void DeleteCamera<Receiver>::execute(std::shared_ptr<Receiver> r) {
    ((*r).*act)(cameraIndex);
}

template <typename Receiver>
TranslateModel<Receiver>::TranslateModel(const Action action, \
    const std::size_t modelIndex, const Point3D<double>& point): 
    this.act(action),
    this.modelIndex(modelIndex),
    this.point(point) {}

template <typename Receiver>
void TranslateModel<Receiver>::execute(std::shared_ptr<Receiver> r) {
    ((*r).*act)(modelIndex, point);
}

template <typename Receiver>
RotateModelOX<Receiver>::RotateModelOX(const Action action, \
    const std::size_t modelIndex, const double angle): 
    this.act(action),
    this.modelIndex(modelIndex),
    this.angle(angle) {}

template <typename Receiver>
void RotateModelOX<Receiver>::execute(std::shared_ptr<Receiver> r) {
    ((*r).*act)(modelIndex, angle);
}


template <typename Receiver>
RotateModelOX<Receiver>::RotateModelOX(const Action action, \
    const std::size_t modelIndex, const double angle): 
    this.act(action),
    this.modelIndex(modelIndex),
    this.angle(angle) {}

template <typename Receiver>
void RotateModelOX<Receiver>::execute(std::shared_ptr<Receiver> r) {
    ((*r).*act)(modelIndex, angle);
}

template <typename Receiver>
RotateModelOY<Receiver>::RotateModelOY(const Action action, \
    const std::size_t modelIndex, const double angle): 
    this.act(action),
    this.modelIndex(modelIndex),
    this.angle(angle) {}

template <typename Receiver>
void RotateModelOY<Receiver>::execute(std::shared_ptr<Receiver> r) {
    ((*r).*act)(modelIndex, angle);
}

template <typename Receiver>
RotateModelOZ<Receiver>::RotateModelOZ(const Action action, \
    const std::size_t modelIndex, const double angle): 
    this.act(action),
    this.modelIndex(modelIndex),
    this.angle(angle) {}

template <typename Receiver>
void RotateModelOZ<Receiver>::execute(std::shared_ptr<Receiver> r) {
    ((*r).*act)(modelIndex, angle);
}

template <typename Receiver>
RotateModelOZ<Receiver>::RotateModelOZ(const Action action, \
    const std::size_t modelIndex, const double angle): 
    this.act(action),
    this.modelIndex(modelIndex),
    this.angle(angle) {}

template <typename Receiver>
void RotateModelOZ<Receiver>::execute(std::shared_ptr<Receiver> r) {
    ((*r).*act)(modelIndex, angle);
}

template <typename Receiver>
ScaleModel<Receiver>::ScaleModel(const Action action, \
    const std::size_t modelIndex, const double scaleFactor): 
    this.act(action),
    this.modelIndex(modelIndex),
    this.scaleFactor(scaleFactor) {}

template <typename Receiver>
void ScaleModel<Receiver>::execute(std::shared_ptr<Receiver> r) {
    ((*r).*act)(modelIndex, scaleFactor);
}

template <typename Receiver>
Draw<Receiver>::Draw(const Action action, \
    const std::size_t cameraIndex, const Drawer& drawer): 
    this.act(action),
    this.cameraIndex(cameraIndex),
    this.drawer(drawer) {}

template <typename Receiver>
void Draw<Receiver>::execute(std::shared_ptr<Receiver> r) {
    ((*r).*act)(cameraIndex, drawer);
}

template <typename Receiver>
RollLook<Receiver>::RollLook(const Action action, \
    const std::size_t cameraIndex, const Drawer& drawer): 
    this.act(action),
    this.cameraIndex(cameraIndex),
    this.angle(angle) {}

template <typename Receiver>
void RollLook<Receiver>::execute(std::shared_ptr<Receiver> r) {
    ((*r).*act)(cameraIndex, angle);
}

template <typename Receiver>
RollRight<Receiver>::RollRight(const Action action, \
    const std::size_t cameraIndex, const Drawer& drawer): 
    this.act(action),
    this.cameraIndex(cameraIndex),
    this.angle(angle) {}

template <typename Receiver>
void RollRight<Receiver>::execute(std::shared_ptr<Receiver> r) {
    ((*r).*act)(cameraIndex, angle);
}

template <typename Receiver>
RollUp<Receiver>::RollUp(const Action action, \
    const std::size_t cameraIndex, const Drawer& drawer): 
    this.act(action),
    this.cameraIndex(cameraIndex),
    this.angle(angle) {}

template <typename Receiver>
void RollUp<Receiver>::execute(std::shared_ptr<Receiver> r) {
    ((*r).*act)(cameraIndex, angle);
}

}


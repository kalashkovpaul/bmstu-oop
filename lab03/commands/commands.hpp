#ifndef COMMANDS_H_

#define COMMANDS_H_

#include <string>
#include <memory>


#include "math3D/Point3D/Point3D.h"
#include "managers/UploadManager.hpp"
#include "managers/ModelManager.hpp"
#include "managers/DrawManager.hpp"
#include "managers/CameraManager.hpp"
#include "gui/drawers.hpp"
#include "Facade/Facade.hpp"
class Facade;
#include "creators/creators.hpp"
#include "transformations/Transformation.hpp"
#include "transformations/cameraCommands.hpp"
class Scene;

class ModelView;

class Command {
public:
    Command() = default;
    Command(const Command&) = delete;
    virtual ~Command() = default;

    virtual void execute(Facade& facade) = 0;
protected:
    Scene& getScene(Facade& facade);
    ModelView& getModelView(Facade& facade);
    Solution& getSolution(Facade& facade);
};

namespace commands {

class UploadView: public Command{
public:
    explicit UploadView(const std::string filename);
    UploadView(const UploadView&) = delete;
    ~UploadView() = default;

    virtual void execute(Facade& facade) override;
private:
    const std::string filename;
};

class DeleteView: public Command {
public:
    explicit DeleteView(const std::size_t viewIndex);
    DeleteView(const DeleteView&) = delete;
    ~DeleteView() = default;

    virtual void execute(Facade& facade) override;
    
private:
    const std::size_t viewIndex;
};

class AddModel: public Command {
public:
    explicit AddModel(const std::size_t viewIndex);
    AddModel(const AddModel&) = delete;
    ~AddModel() = default;

    virtual void execute(Facade& facade) override;

private:
    const std::size_t viewIndex;
};

class DeleteModel: public Command {
public:
    explicit DeleteModel(const std::size_t modelIndex);
    DeleteModel(const DeleteModel&) = delete;
    ~DeleteModel() = default;

    virtual void execute(Facade& facade) override;

private:
    const std::size_t modelIndex;
};

class AddCamera: public Command {
public:
    explicit AddCamera();
    AddCamera(const AddCamera&) = delete;
    ~AddCamera() = default;

    virtual void execute(Facade& facade) override;
};

class DeleteCamera: public Command {
public:
    explicit DeleteCamera(const std::size_t cameraIndex);
    DeleteCamera(const DeleteCamera&) = delete;
    ~DeleteCamera() = default;

    virtual void execute(Facade& facade) override;

private:
    const std::size_t cameraIndex;
};

class TranslateModel: public Command {
public:
    explicit TranslateModel(const ssize_t modelIndex, const Point3D<double>& point);
    TranslateModel(const TranslateModel&) = delete;
    ~TranslateModel() = default;

    virtual void execute(Facade& facade) override;

private:
    const ssize_t modelIndex;
    const Point3D<double> point;
};

class RotateModelOX: public Command {
public:
    explicit RotateModelOX(const ssize_t modelIndex, const double angle);
    RotateModelOX(const RotateModelOX&) = delete;
    ~RotateModelOX() = default;

    virtual void execute(Facade& facade) override;

private:
    const ssize_t modelIndex;
    const double angle;
};

class RotateModelOY: public Command {
public:
    explicit RotateModelOY(const ssize_t modelIndex, const double angle);
    RotateModelOY(const RotateModelOY&) = delete;
    ~RotateModelOY() = default;

    virtual void execute(Facade& facade) override;

private:
    const ssize_t modelIndex;
    const double angle;
};

class RotateModelOZ: public Command {
public:
    explicit RotateModelOZ(const ssize_t modelIndex, const double angle);
    RotateModelOZ(const RotateModelOZ&) = delete;
    ~RotateModelOZ() = default;

    virtual void execute(Facade& facade) override;

private:
    const ssize_t modelIndex;
    const double angle;
};

class ScaleModel: public Command {
public:
    explicit ScaleModel(const ssize_t modelIndex, const double scaleFactor);
    ScaleModel(const ScaleModel&) = delete;
    ~ScaleModel() = default;

    virtual void execute(Facade& facade) override;

private:
    const ssize_t modelIndex;
    const double scaleFactor;
};

class Draw: public Command {
public:
    explicit Draw(const ssize_t cameraIndex, Drawer& drawer);
    Draw(const Draw&) = delete;
    ~Draw() = default;

    virtual void execute(Facade& facade) override;

private:
    const ssize_t cameraIndex;
    Drawer& drawer;
};

class RollLook: public Command {
public:
    explicit RollLook(const std::size_t cameraIndex, const double angle);
    RollLook(const RollLook&) = delete;
    ~RollLook() = default;

    virtual void execute(Facade& facade) override;

private:
    const std::size_t cameraIndex;
    const double angle;
};

class RollRight: public Command {
public:
    explicit RollRight(const std::size_t cameraIndex, const double angle);
    RollRight(const RollRight&) = delete;
    ~RollRight() = default;

    virtual void execute(Facade& facade) override;

private:
    const std::size_t cameraIndex;
    const double angle;
};

class RollUp: public Command {
public:
    explicit RollUp(const std::size_t cameraIndex, const double angle);
    RollUp(const RollUp&) = delete;
    ~RollUp() = default;

    virtual void execute(Facade& facade) override;

private:
    const std::size_t cameraIndex;
    const double angle;
};

}

#endif
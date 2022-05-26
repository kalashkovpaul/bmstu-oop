#ifndef COMMANDS_H_

#define COMMANDS_H_

#include <string>
#include <memory>


#include "math3D/Point3D/Point3D.h"
#include "managers/UploadManager.hpp"
#include "managers/ModelManager.hpp"
#include "managers/DrawManager.hpp"
#include "managers/CameraManager.hpp"
#include "managers/SceneManager.hpp"
#include "gui/drawers.hpp"
#include "Facade/Facade.hpp"
class Facade;
#include "creators/creators.hpp"
#include "transformations/Transformation.hpp"
#include "transformations/cameraCommands.hpp"
class Scene;

class ModelView;

constexpr std::size_t SceneCommandID = 0;
constexpr std::size_t ModelViewCommandID = 1;
constexpr std::size_t SceneAndViewCommandID = 2;
constexpr std::size_t SceneAndSolutionCommandID = 3;
constexpr std::size_t ViewAndSolutionCommandID = 4;

class Command {
public:
    Command() = default;
    Command(const Command&) = delete;
    virtual ~Command() = default;

    virtual void execute(Facade& facade) {};
    virtual std::size_t getType() { return 17;}

    virtual void execute(Scene& scene) {}
    virtual void execute(ModelView& modelView) {}
    virtual void execute(Scene& scene, ModelView& modelView) {}
    virtual void execute(Scene& scene, Solution& solution) {}
    virtual void execute(ModelView& modelView, Solution& solution) {}
};

namespace commands {

class UploadView: public Command{
public:
    explicit UploadView(const std::string filename);
    UploadView(const UploadView&) = delete;
    ~UploadView() = default;

    std::size_t getType() override { return ViewAndSolutionCommandID; }

    void execute(ModelView& modelView, Solution& solution) override;
private:
    const std::string filename;
};

class DeleteView: public Command {
public:
    explicit DeleteView(const std::size_t viewIndex);
    DeleteView(const DeleteView&) = delete;
    ~DeleteView() = default;

    std::size_t getType() override { return ModelViewCommandID; }

    virtual void execute(ModelView& modelView) override;
    
private:
    const std::size_t viewIndex;
};

class AddModel: public Command {
public:
    explicit AddModel(const std::size_t viewIndex);
    AddModel(const AddModel&) = delete;
    ~AddModel() = default;

    std::size_t getType() override { return SceneAndViewCommandID; }

    virtual void execute(Scene& scene, ModelView& modelView) override;

private:
    const std::size_t viewIndex;
};

class DeleteModel: public Command {
public:
    explicit DeleteModel(const std::size_t modelIndex);
    DeleteModel(const DeleteModel&) = delete;
    ~DeleteModel() = default;

    std::size_t getType() override { return SceneCommandID; }

    virtual void execute(Scene& scene) override;

private:
    const std::size_t modelIndex;
};

class AddCamera: public Command {
public:
    explicit AddCamera();
    AddCamera(const AddCamera&) = delete;
    ~AddCamera() = default;

    std::size_t getType() override { return SceneAndSolutionCommandID; }

    virtual void execute(Scene& scene, Solution& solution) override;
};

class DeleteCamera: public Command {
public:
    explicit DeleteCamera(const std::size_t cameraIndex);
    DeleteCamera(const DeleteCamera&) = delete;
    ~DeleteCamera() = default;

    std::size_t getType() override { return SceneCommandID; }

    virtual void execute(Scene& scene) override;

private:
    const std::size_t cameraIndex;
};

class TranslateModel: public Command {
public:
    explicit TranslateModel(const ssize_t modelIndex, const Point3D<double>& point);
    TranslateModel(const TranslateModel&) = delete;
    ~TranslateModel() = default;

    std::size_t getType() override { return SceneCommandID; }

    virtual void execute(Scene& scene) override;

private:
    const ssize_t modelIndex;
    const Point3D<double> point;
};

class RotateModelOX: public Command {
public:
    explicit RotateModelOX(const ssize_t modelIndex, const double angle);
    RotateModelOX(const RotateModelOX&) = delete;
    ~RotateModelOX() = default;

    std::size_t getType() override { return SceneCommandID; }

    virtual void execute(Scene& scene) override;

private:
    const ssize_t modelIndex;
    const double angle;
};

class RotateModelOY: public Command {
public:
    explicit RotateModelOY(const ssize_t modelIndex, const double angle);
    RotateModelOY(const RotateModelOY&) = delete;
    ~RotateModelOY() = default;

    std::size_t getType() override { return SceneCommandID; }

    virtual void execute(Scene& scene) override;

private:
    const ssize_t modelIndex;
    const double angle;
};

class RotateModelOZ: public Command {
public:
    explicit RotateModelOZ(const ssize_t modelIndex, const double angle);
    RotateModelOZ(const RotateModelOZ&) = delete;
    ~RotateModelOZ() = default;

    std::size_t getType() override { return SceneCommandID; }

    virtual void execute(Scene& scene) override;

private:
    const ssize_t modelIndex;
    const double angle;
};

class ScaleModel: public Command {
public:
    explicit ScaleModel(const ssize_t modelIndex, const double scaleFactor);
    ScaleModel(const ScaleModel&) = delete;
    ~ScaleModel() = default;

    std::size_t getType() override { return SceneCommandID; }

    virtual void execute(Scene& scene) override;

private:
    const ssize_t modelIndex;
    const double scaleFactor;
};

class Draw: public Command {
public:
    explicit Draw(const ssize_t cameraIndex, Drawer& drawer);
    Draw(const Draw&) = delete;
    ~Draw() = default;

    std::size_t getType() override { return SceneCommandID; }

    virtual void execute(Scene& scene) override;

private:
    const ssize_t cameraIndex;
    Drawer& drawer;
};

class RollLook: public Command {
public:
    explicit RollLook(const std::size_t cameraIndex, const double angle);
    RollLook(const RollLook&) = delete;
    ~RollLook() = default;

    std::size_t getType() override { return SceneCommandID; }

    virtual void execute(Scene& scene) override;

private:
    const std::size_t cameraIndex;
    const double angle;
};

class RollRight: public Command {
public:
    explicit RollRight(const std::size_t cameraIndex, const double angle);
    RollRight(const RollRight&) = delete;
    ~RollRight() = default;

    std::size_t getType() override { return SceneCommandID; }

    virtual void execute(Scene& scene) override;

private:
    const std::size_t cameraIndex;
    const double angle;
};

class RollUp: public Command {
public:
    explicit RollUp(const std::size_t cameraIndex, const double angle);
    RollUp(const RollUp&) = delete;
    ~RollUp() = default;

    std::size_t getType() override { return SceneCommandID; }

    virtual void execute(Scene& scene) override;

private:
    const std::size_t cameraIndex;
    const double angle;
};

}

#endif
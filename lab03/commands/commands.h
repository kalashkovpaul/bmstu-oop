#ifndef COMMANDS_H_

#define COMMANDS_H_

#include <string>
#include <memory>

#include "math3D/Point3D/Point3D.h"
#include "gui/drawers/drawers.hpp"

template <typename Receiver>
class Command {
public:
    virtual Command() = default;
    virtual Command(const Command&) = delete;
    virtual ~Command() = default;

    virtual void execute(const shared_ptr<Receiver>) = 0;
};

namespace commands {

template <typename Receiver>
class UploadView: public Command<Receiver> {
    using Action = void (Receiver::*)();
public:
    explicit UploadView(const Action action, const std::string filename);
    UploadView(const UploadView&) = delete;
    ~UploadView() = default;

    virtual void execute(const std::shared_ptr<Receiver> r) override;
private:
    const Action act;
    const std::string filename;
};

template <typename Receiver>
class DeleteView: public Command<Receiver> {
    using Action = void (Receiver::*)();
public:
    explicit DeleteView(const Action action, const std::size_t viewIndex);
    DeleteView(const DeleteView&) = delete;
    ~DeleteView() = default;

    virtual void execute(const std::shared_ptr<Receiver> r) override;
    
private:
    const Action act;
    const std::size_t viewIndex;
};

template <typename Receiver>
class AddModel: public Command<Receiver> {
    using Action = void (Receiver::*)();
public:
    explicit AddModel(const Action action, const std::size_t viewIndex);
    AddModel(const AddModel&) = delete;
    ~AddModel() = default;

    virtual void execute(const std::shared_ptr<Receiver> r) override;

private:
    const Action act;
    const std::size_t viewIndex;
};

template <typename Receiver>
class DeleteModel: public Command<Receiver> {
    using Action = void (Receiver::*)();
public:
    explicit DeleteModel(const Action action, const std::size_t modelIndex);
    DeleteModel(const DeleteModel&) = delete;
    ~DeleteModel() = default;

    virtual void execute(const std::shared_ptr<Receiver> r) override;

private:
    const Action act;
    const std::size_t modelIndex;
};

template <typename Receiver>
class AddCamera: public Command<Receiver> {
    using Action = void (Receiver::*)();
public:
    explicit AddCamera(const Action action);
    AddCamera(const AddCamera&) = delete;
    ~AddCamera() = default;

    virtual void execute(const std::shared_ptr<Receiver> r) override;

private:
    const Action act;
};

template <typename Receiver>
class DeleteCamera: public Command<Receiver> {
    using Action = void (Receiver::*)();
public:
    explicit DeleteCamera(const Action action, const std::size_t cameraIndex);
    DeleteCamera(const DeleteCamera&) = delete;
    ~DeleteCamera() = default;

    virtual void execute(const std::shared_ptr<Receiver> r) override;

private:
    const Action act;
    const std::size_t cameraIndex;
};

template <typename Receiver>
class TranslateModel: public Command<Receiver> {
    using Action = void (Receiver::*)();
public:
    explicit TranslateModel(const Action action, \
        const std::size_t modelIndex, const Point3D<double>& point);p
    TranslateModel(const TranslateModel&) = delete;
    ~TranslateModel() = default;

    virtual void execute(std::shared_ptr<Receiver> r) override;

private:
    const Action act;
    const std::size_t modelIndex;
    const Point3D<double> point;
};

template <typename Receiver>
class RotateModelOX: public Command<Receiver> {
    using Action = void (Receiver::*)();
public:
    explicit RotateModelOX(const Action action, \
        const std::size_t modelIndex, const double angle);
    RotateModelOX(const RotateModelOX&) = delete;
    ~RotateModelOX() = default;

    virtual void execute(std::shared_ptr<Receiver> r) override;

private:
    const Action act;
    const std::size_t modelIndex;
    const double angle;
};

template <typename Receiver>
class RotateModelOY: public Command<Receiver> {
    using Action = void (Receiver::*)();
public:
    explicit RotateModelOY(const Action action, \
        const std::size_t modelIndex, const double angle);
    RotateModelOY(const RotateModelOY&) = delete;
    ~RotateModelOY() = default;

    virtual void execute(std::shared_ptr<Receiver> r) override;

private:
    const Action act;
    const std::size_t modelIndex;
    const double angle;
};

template <typename Receiver>
class RotateModelOZ: public Command<Receiver> {
    using Action = void (Receiver::*)();
public:
    explicit RotateModelOZ(const Action action, \
        const std::size_t modelIndex, const double angle);
    RotateModelOZ(const RotateModelOZ&) = delete;
    ~RotateModelOZ() = default;

    virtual void execute(std::shared_ptr<Receiver> r) override;

private:
    const Action act;
    const std::size_t modelIndex;
    const double angle;
};

template <typename Receiver>
class ScaleModel: public Command<Receiver> {
    using Action = void (Receiver::*)();
public:
    explicit ScaleModel(const Action action, \
        const std::size_t modelIndex, const double scaleFactor);
    ScaleModel(const ScaleModel&) = delete;
    ~ScaleModel() = default;

    virtual void execute(std::shared_ptr<Receiver> r) override;

private:
    const Action act;
    const std::size_t modelIndex;
    const double scaleFactor;
};

template <typename Receiver>
class Draw: public Command<Receiver> {
    using Action = void (Receiver::*)();
public:
    explicit Draw(const Action action, \
        const std::size_t cameraIndex, const Drawer& drawer);
    Draw(const Draw&) = delete;
    ~Draw() = default;

    virtual void execute(std::shared_ptr<Receiver> r) override;

private:
    const Action act;
    const std::size_t cameraIndex;
    const Drawer& drawer;
};

template <typename Receiver>
class RollLook: public Command<Receiver> {
    using Action = void (Receiver::*)();
public:
    explicit RollLook(const Action action, \
        const std::size_t cameraIndex, const double angle);
    RollLook(const RollLook&) = delete;
    ~Draw() = default;

    virtual void execute(std::shared_ptr<Receiver> r) override;

private:
    const Action act;
    const std::size_t cameraIndex;
    const angle;
};

template <typename Receiver>
class RollRight: public Command<Receiver> {
    using Action = void (Receiver::*)();
public:
    explicit RollRight(const Action action, \
        const std::size_t cameraIndex, const double angle);
    RollRight(const RollRight&) = delete;
    ~Draw() = default;

    virtual void execute(std::shared_ptr<Receiver> r) override;

private:
    const Action act;
    const std::size_t cameraIndex;
    const angle;
};

template <typename Receiver>
class RollUp: public Command<Receiver> {
    using Action = void (Receiver::*)();
public:
    explicit RollUp(const Action action, \
        const std::size_t cameraIndex, const double angle);
    RollUp(const RollUp&) = delete;
    ~Draw() = default;

    virtual void execute(std::shared_ptr<Receiver> r) override;

private:
    const Action act;
    const std::size_t cameraIndex;
    const angle;
};

}

#include "commands.hpp"

#endif
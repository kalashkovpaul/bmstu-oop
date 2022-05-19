#ifndef VISIBLE_OBJECT_HPP_

#define VISIBLE_OBJECT_HPP_

#include "SceneObject.hpp"

class VisibleObject: public SceneObject {
public:
    explicit VisibleObject() = default;
    VisibleObject(const VisibleObject&) = delete;
    ~VisibleObject() override = default;

    bool isVisible() const final;
};

#endif
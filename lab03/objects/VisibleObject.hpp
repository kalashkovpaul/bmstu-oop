#ifndef VISIBLE_OBJECT_HPP_

#define VISIBLE_OBJECT_HPP_

#include "SceneObject.hpp"

class VisibleObject: public SceneObject {
public:
    VisibleObject() = default;
    VisibleObject(const VisibleObject&) = default;
    ~VisibleObject() override = default;

    bool isVisible() const override final;
};

#endif
#ifndef INVISIBLE_OBJECT_HPP_ 

#define INVISIBLE_OBJECT_HPP_

#include "Scene.hpp"

class InvisibleObject: public Scene {
    explicit InvisibleObject() = default;
    InvisibleObject(const InvisibleObject&) = delete;
    ~InvisibleObject() override = default;

    bool isVisible() const final;
};

#endif
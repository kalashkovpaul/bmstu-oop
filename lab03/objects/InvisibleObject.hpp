#ifndef INVISIBLE_OBJECT_HPP_ 

#define INVISIBLE_OBJECT_HPP_

#include "SceneObject.hpp"

class InvisibleObject: public SceneObject {
public:
    explicit InvisibleObject() = default;
    InvisibleObject(const InvisibleObject&) = delete;
    ~InvisibleObject() = default;

    virtual bool isVisible() const final;
};

#endif
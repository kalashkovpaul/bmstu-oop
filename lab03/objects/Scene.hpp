#ifndef SCENE_HPP_

#define SCENE_HPP_

#include <vector>

class Scene {
public:
    explicit Scene() = default;
    Scene(const Scene&) = delete;
    virtual ~Scene() = default;

    virtual bool isVisible() const = 0;
};

#endif
#ifndef CREATORS_HPP_

#define CREATORS_HPP_

#include <memory>
#include <map>
#include "objects/SceneObject.hpp"
#include "objects/Model.hpp"
#include "objects/Camera.hpp"
#include "exceptions/CreationException.hpp"

constexpr std::size_t modelId = 0;
constexpr std::size_t cameraId = 1;

class Creator {
public:
    virtual std::shared_ptr<SceneObject> createSceneObject() = 0;
};

template <typename T>
class ConCreator: public Creator {
    std::shared_ptr<SceneObject> createSceneObject() override;
};


class CrCreator {
public:
    template <typename T>
    static std::unique_ptr<Creator> createConCreator();
};

class Solution {
public:
    using CreateCreator = std::unique_ptr<Creator>(*)();

    Solution();
    Solution(std::initializer_list<std::pair<std::size_t, CreateCreator>> list);
    bool registrate(size_t id, CreateCreator createfun);
    bool check(std::size_t id);

    std::unique_ptr<Creator> create(size_t id);
private:
    std::map<std::size_t, CreateCreator> callbacks;
};

#endif
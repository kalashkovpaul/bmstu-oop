#include "creators/creators.hpp"

template <typename T>
std::unique_ptr<SceneObject> ConCreator<T>::createSceneObject() {
    return std::unique_ptr<SceneObject>(new T());
}

template <typename T>
std::unique_ptr<Creator> CrCreator::createConCreator() {
    return std::unique_ptr<Creator>(new ConCreator<T>());
}

Solution::Solution() {
    registrate(modelId, &CrCreator::createConCreator<Model>);
    registrate(cameraId, &CrCreator::createConCreator<Camera>);
}

Solution::Solution(std::initializer_list<std::pair<std::size_t, CreateCreator>> list) {
    for (auto elem : list) {
        this->registrate(elem.first, elem.second);
    }
}

bool Solution::registrate(std::size_t id, CreateCreator createfun) {
    return callbacks.insert(std::map<std::size_t, CreateCreator>::value_type(id, createfun)).second;
}

std::unique_ptr<Creator> Solution::create(size_t id) {
    std::map<std::size_t, CreateCreator>::const_iterator it = callbacks.find(id);
    if (it == callbacks.end()) {
        throw CreationException();
    }
    return std::unique_ptr<Creator>((it->second)());
}

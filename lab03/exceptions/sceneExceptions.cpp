#include "sceneExceptions.hpp"

BaseSceneException::BaseSceneException(const char* message):
    BaseException(message) {}

const char* BaseSceneException::what() const noexcept {
    return message.empty() ? "Scene::BaseException" : message.c_str();
}

SceneOutOfRangeException::SceneOutOfRangeException(const char* message):
    BaseSceneException(message) {}

const char* SceneOutOfRangeException::what() const noexcept {
    return message.empty() ? "Scene::OutOfRangeException" : message.c_str();
}


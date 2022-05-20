#ifndef SCENE_EXCEPTIONS_HPP_

#define SCENE_EXCEPTIONS_HPP_

#include "BaseException.hpp"

class BaseSceneException: public BaseException {
public:
    explicit BaseSceneException() = default;
    explicit BaseSceneException(const char* message);

    const char* what() const noexcept override; 
};

class SceneOutOfRangeException: public BaseSceneException {
public:
    explicit SceneOutOfRangeException() = default;
    explicit SceneOutOfRangeException(const char* message);

    const char* what() const noexcept override; 

};

class SceneCloneException: public BaseSceneException {
public:
    explicit SceneCloneException() = default;
    explicit SceneCloneException(const char* message);

    const char* what() const noexcept override;
};

#endif
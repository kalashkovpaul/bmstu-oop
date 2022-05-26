#ifndef BASE_MODEL_HPP_

#define BASE_MODEL_HPP_

#include <memory>
#include "objects/VisibleObject.hpp"
#include "objects/BaseModelImplementator.hpp"
#include "objects/Camera.hpp"
#include "visitors/Visitor.hpp"

class BaseModel: public VisibleObject {
public:
    BaseModel() = default;
    BaseModel(std::shared_ptr<BaseModelImplementator> imp): implementator(imp) {}     
    BaseModel(const BaseModel&) = default;
    BaseModel(BaseModel&&) noexcept = default;

    void setImplementator(std::shared_ptr<BaseModelImplementator> imp) { implementator = imp; }

    virtual void accept(Visitor& visitor) = 0;

    virtual void transform(Matrix4x4<double>& matrix) = 0;

    virtual std::shared_ptr<SceneObject> clone() const = 0;
    
protected:
    std::shared_ptr<BaseModelImplementator> implementator;
};

#endif

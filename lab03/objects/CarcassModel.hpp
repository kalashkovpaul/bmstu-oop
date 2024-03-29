#ifndef CARCASS_MODEL_HPP_

#define CARCASS_MODEL_HPP_

#include "objects/BaseModel.hpp"

class CarcassModel: public BaseModel {
public:
    CarcassModel() = default;
    CarcassModel(const CarcassModel&);
    CarcassModel(CarcassModel&&);
    CarcassModel& operator=(const CarcassModel&);
    CarcassModel& operator=(CarcassModel&&) noexcept;

    void accept(Visitor& visitor) override;

    void transform(Matrix4x4<double>& matrix) override;

    std::shared_ptr<SceneObject> clone() const override;
};

#endif
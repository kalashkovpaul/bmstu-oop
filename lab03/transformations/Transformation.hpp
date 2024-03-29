#ifndef TRANSFORMATION_HPP_

#define TRANSFORMATION_HPP_

#include "transformations/BaseTransformation.hpp"
#include "transformations/ITransformation.hpp"
#include "objects/BaseModel.hpp"

class Transformation: public BaseTransformation {
public:
    explicit Transformation(ITransfromation& interface);
    ~Transformation() override = default;

    void transform(std::shared_ptr<SceneObject> object) override;

private:
    Matrix4x4<double> matrix = Matrix4x4<double>();
};

#endif
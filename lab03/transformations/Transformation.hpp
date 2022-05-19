#ifndef TRANSFORMATION_HPP_

#define TRANSFORMATION_HPP_

#include "BaseTransformation.hpp"
#include "ITransformation.hpp"
#include "Model.hpp"

class Transformation: public BaseTransformation {
public:
    explicit Transformation(ITransfromation& interface);
    ~Transformation() override = default;

    void transform(Scene*& object) override;

private:
    Matrix4x4<double> matrix = Matrix4x4<double>();
};

#endif
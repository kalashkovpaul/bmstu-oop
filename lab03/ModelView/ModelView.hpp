#ifndef MODEL_VIEW_HPP_

#define MODEL_VIEW_HPP_

#include <vector>
#include "objects/Model.hpp"
#include "exceptions/modelViewExceptions.hpp"

class ModelView {
public:
    ModelView() = default;
    // ModelView(const std::shared_ptr<Model>&);
    ~ModelView() = default;

    void addView(const std::shared_ptr<SceneObject>& model);
    void deleteView(std::size_t index);

    const std::shared_ptr<SceneObject>& operator[](std::size_t index) const;

private:
    void checkOutOfRange(std::size_t index) const;

    std::vector<std::shared_ptr<SceneObject>> models;
};

#endif
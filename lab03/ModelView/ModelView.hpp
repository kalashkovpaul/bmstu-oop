#ifndef MODEL_VIEW_HPP_

#define MODEL_VIEW_HPP_

#include <vector>
#include "objects/Model.hpp"
#include "exceptions/modelViewExceptions.hpp"

class ModelView {
public:
    ModelView() = default;
    ModelView(const ModelView&) = default;
    ~ModelView() = default;

    void addView(const Model& model);
    void deleteView(std::size_t index);

    const Model& operator[](std::size_t index) const;

private:
    void checkOutOfRange(std::size_t index) const;

    std::vector<Model> models;
};

#endif
#include "model.hpp"

#include <fstream>
#include <assert.h>

bool isAmountRight(int verticesAmount, int edgesAmount) {
    return (verticesAmount > 0 && edgesAmount > 0) && \
        (edgesAmount < verticesAmount * (verticesAmount - 1) / 2);
}

bool readAmounts(model_t *model, std::ifstream& file) {
    int verticesAmount = 0, edgesAmount = 0;
    bool ok = true;
    if (file >> verticesAmount >> edgesAmount && \
        isAmountRight(verticesAmount, edgesAmount)) {
        size_t vAmount = verticesAmount, eAmount = edgesAmount;
        model->vertices.resize(vAmount);
        model->edges.resize(eAmount);
    } else 
        ok = false;
    return ok;
}

bool createModel(model_t *model) {
    model = new model_t;
    return model;
}

void deleteModel(model_t *model) {
    delete model;
    // *model = nullptr; no operator "=" matches these operands
}

err_t readModel(model_t *model, std::ifstream& file) {
    err_t error = NONE;
    if (readAmounts(model, file) && \
        createModel(model)) {
            if (!(readVectors3d(model->vertices, file) && \
                readEdges(model->edges, file))) {
                    deleteModel(model);
                    error = INVALID_FILE_FORMAT;
            }
    }
    return error;
}

err_t loadModel(model_t *model, std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) 
        return CANT_OPEN_FILE;
    model_t tmp;
    err_t error = readModel(&tmp, file);
    file.close();
    if (!error) {
        *model = tmp;
    }
    return error;
}

const vector3d_t& getIJVertex(const model_t *model, int i, int j) {
    return model->vertices.at(getIEnd(model->edges.at(i), j));
}

err_t renderModel(const model_t *model, const screen_t *screen) {
    for (size_t i = 0; i < model->edges.size(); i++) {
        vector2d_t a = project3dOn2d(getIJVertex(model, i, 0), screen);
        vector2d_t b = project3dOn2d(getIJVertex(model, i, 1), screen);
        screen->canvas->painter.drawLine(QPointF(a.x, a.y), QPointF(b.x, b.y));
    }
    return NONE;
}

err_t transformModel(model_t *model, const transformMeta_t *transformMeta) {
    const transform_t transform = createTransform(transformMeta);
    for (size_t i = 0; i < model->vertices.size(); i++)
        model->vertices.at(i) = transformVector3d(transform, model->vertices.at(i));
    return NONE;
}





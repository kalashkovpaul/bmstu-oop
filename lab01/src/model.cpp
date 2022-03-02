#include "model.hpp"

#include <fstream>
#include "assert.h"

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
        model->vertices.reserve(vAmount);
        model->edges.reserve(eAmount);
    } else 
        ok = false;
    return ok;
}

err_t readModel(model_t *model, std::ifstream& file) {
    err_t error = NONE;
    if (readAmounts(model, file) && \
        readVectors3d(model->vertices, file) && \
        readEdges(model->edges, file)) {
        model = new model_t;
    } else 
        error = INVALID_FILE_FORMAT;
    return error;
}

void deleteModel(model_t *model) {
    delete model;
    // *model = nullptr; no operator "=" matches these operands
}

err_t loadModel(model_t *model, std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) 
        return CANT_OPEN_FILE;
    model_t *tmp = nullptr;
    err_t error = readModel(tmp, file);
    file.close();
    if (!error) {
        deleteModel(model);
        *model = *tmp;
    }
    return error;
}
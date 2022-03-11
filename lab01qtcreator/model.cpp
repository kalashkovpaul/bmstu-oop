#include "model.hpp"

#include <assert.h>

model_t createModel(const int verticesAmount, const int edgesAmount) {
    model_t model = { nullptr, nullptr, verticesAmount, edgesAmount };
    return model;
}

bool allocModel(model_t *model) {
    assert(model->verticesAmount > 0 && model->edgesAmount > 0);
    bool ok = true;
    if (model->verticesAmount > 0) {
        if (!(model->vertices = static_cast<vector3d_t*>(malloc(model->verticesAmount * sizeof(*model->vertices)))))
            ok = false;
        else if (model->edgesAmount > 0 && \
            !(model->edges = static_cast<edge_t*>(malloc(model->edgesAmount * sizeof(*model->vertices))))) {
            free(model->vertices);
            ok = false;
        } else
            ok = true;
    } else if (model->edgesAmount > 0) {
        ok = false;
    }
    return ok;
}

void deleteModel(model_t *model) {
    if (model->verticesAmount) {
        free(model->vertices);
        model->vertices = nullptr;
    }
    if (model->edgesAmount) {
        free(model->edges);
        model->edges = nullptr;
    }
    *model = createModel(0, 0);
}

bool isAmountRight(const int verticesAmount, const int edgesAmount)
{
    return (verticesAmount > 0 && edgesAmount > 0) && (edgesAmount < verticesAmount * (verticesAmount - 1) / 2);
}

bool readAmounts(int* verticesAmount, int* edgesAmount, FILE* file)
{
    bool ok = true;
    if (!((fscanf(file, "%d %d", verticesAmount, edgesAmount) == 2) && \
        isAmountRight(*verticesAmount, *edgesAmount))) {
        ok = false;
        *verticesAmount = 0;
        *edgesAmount = 0;
    }
    return ok;
}

err_t readModel(model_t* model, FILE* file)
{
    err_t error = NONE;
    if (readAmounts(&model->verticesAmount, &model->edgesAmount, file)) {
        if (!allocModel(model))
            error = ALLOC_FAIL;
        else if (!((readVectors3d(model->vertices, model->verticesAmount, file) && \
            readEdges(model->edges, model->edgesAmount, file)))) {
            deleteModel(model);
            error = INVALID_FILE_FORMAT;
        }
    }
    return error;
}

err_t loadModel(model_t* model, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
        return CANT_OPEN_FILE;
    model_t tmp;
    err_t error = readModel(&tmp, file);
    fclose(file);
    if (!error) {
        deleteModel(model);
        *model = tmp;
    }
    return error;
}

const vector3d_t& getIJVertex(const model_t* model, const int i, const int j)
{
    return model->vertices[(getIEnd(model->edges[i], j))];
}

err_t renderModel(const model_t* model, const screen_t& screen)
{
    for (int i = 0; i < model->edgesAmount; i++) {
        vector2d_t a = project3dOn2d(getIJVertex(model, i, 0), screen);
        vector2d_t b = project3dOn2d(getIJVertex(model, i, 1), screen);
        screen.canvas->painter.drawLine(QPointF(a.x, a.y), QPointF(b.x, b.y));
    }
    return NONE;
}

err_t transformModel(model_t* model, const transformMeta_t& transformMeta)
{
    const transform_t transform = createTransform(transformMeta);
    for (int i = 0; i < model->verticesAmount; i++)
        model->vertices[i] = transformVector3d(transform, model->vertices[i]);
    return NONE;
}

void writeAmounts(const int verticesAmount, const int edgesAmount, FILE* file)
{
    fprintf(file, "%d %d\n", verticesAmount, edgesAmount);
}

void writeModel(const model_t* model, FILE* file)
{
    writeAmounts(model->verticesAmount, model->edgesAmount, file);
    fprintf(file, "\n");
    writeVectors3d(model->vertices, model->verticesAmount, file);
    fprintf(file, "\n");
    writeEdges(model->edges, model->edgesAmount, file);
    fprintf(file, "\n");
}

err_t dumpModel(const model_t* model, const char* filename)
{
    FILE* file = fopen(filename, "w");
    if (!file)
        return CANT_OPEN_FILE;
    writeModel(model, file);
    fclose(file);
    return NONE;
}

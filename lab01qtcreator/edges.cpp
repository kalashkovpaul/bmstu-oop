#include "edges.hpp"

int getIEnd(const edge_t& edge, int i)
{
    int end = 0;
    if (i == 1)
        end = edge.end2;
    else
        end = edge.end1;
    return end;
}

bool readEdge(edge_t& edge, FILE* file)
{
    bool ok = true;
    int tmp = fscanf(file, "%d %d", &edge.end1, &edge.end2);
    if (tmp != 2)
        ok = false;
    return ok;
}

bool readEdges(edge_t* edges, const int edgesAmount, FILE* file)
{
    bool ok = true;
    for (int i = 0; i < edgesAmount && ok; i++) {
        edge_t& edge = edges[i];
        ok = readEdge(edge, file);
    }
    return ok;
}

void writeSingleEdge(const edge_t& edge, FILE* file)
{
    fprintf(file, "%d %d\n", edge.end1, edge.end2);
}

void writeEdges(const edge_t* edges, int edgesAmount, FILE* file)
{
    for (size_t i = 0; i < edgesAmount; i++)
        writeSingleEdge(edges[i], file);
}

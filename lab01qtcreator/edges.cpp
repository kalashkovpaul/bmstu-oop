#include "edges.hpp"

int getIEnd(const edge_t& edge, int i) {
    int end = 0;
    if (i == 1)
        end = edge.end2;
    else
        end = edge.end1;
    return end;
}

bool readEdge(edge_t& edge, std::ifstream& file) {
    bool ok = true;
    int end1 = 0; int end2 = 0;
    if (file >> end1 >> end2) {
        edge.end1 = end1;
        edge.end2 = end2;
    } else
        ok = false;
    return ok;
}

bool readEdges(std::vector<edge_t>& edges, std::ifstream& file) {
    bool ok = true;
    for (size_t i = 0; i < edges.size() && ok; i++) {
        edge_t& edge = edges.at(i);
        ok = readEdge(edge, file);
    }
    return ok;
}

void writeSingleEdge(const edge_t& edge, std::ofstream& file) {
    file << edge.end1 << " " << edge.end2 << std::endl;
}

void writeEdges(const std::vector<edge_t>& edges, std::ofstream& file) {
    for (size_t i = 0; i < edges.size(); i++)
        writeSingleEdge(edges.at(i), file);
}

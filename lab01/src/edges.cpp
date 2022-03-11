#include "edges.hpp"

bool readEdge(edge_t& edge, std::ifstream& file) {
    bool ok = true;
    int end1 = 0; int end2 = 0;
    if (file >> end1 >> end2) {
        edge.ends.end1 = end1;
        edge.ends.end2 = end2;
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
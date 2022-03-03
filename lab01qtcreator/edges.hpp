#ifndef EDGES_HPP
#define EDGES_HPP

#include <vector>
#include <fstream>

struct edge_t {
    int end1, end2;
};

int getIEnd(const edge_t& edge, int i);

bool readEdges(std::vector<edge_t>& edges, std::ifstream& file);

#endif

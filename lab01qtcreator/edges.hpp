#ifndef EDGES_HPP
#define EDGES_HPP

#include <vector>
#include <fstream>

typedef struct {
    int end1, end2;
} edge_t;



int getIEnd(const edge_t& edge, int i);

bool readEdges(std::vector<edge_t>& edges, std::ifstream& file);

#endif

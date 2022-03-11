#pragma once

#include <vector>
#include <fstream>

typedef union {
    struct {
        int end1, end2;
    } ends;
    int m[2];
} edge_t;


bool readEdges(std::vector<edge_t>& edges, std::ifstream& file);

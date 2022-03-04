#ifndef EDGES_HPP
#define EDGES_HPP

#include <stdio.h>

struct edge_t {
    int end1, end2;
};

int getIEnd(const edge_t& edge, int i);

bool readEdges(edge_t* edges, const int edgesAmount, FILE* file);

void writeEdges(const edge_t* edges, int edgesAmount, FILE* file);

#endif

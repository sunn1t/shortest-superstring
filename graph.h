#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph {
public:
    Graph(size_t n_vertex);

    void AddEdge(size_t from, size_t to, size_t length);

    size_t ** GetMatrix() const;
    size_t * GetEdgesFrom(size_t from) const;
    size_t GetSize() const;

    void PrintAdjMatrix() const;

    ~Graph();

private:
    size_t n_vertex;
    size_t ** adj_matrix;
};

#endif // GRAPH_H


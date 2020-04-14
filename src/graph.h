#ifndef GRAPH_H
#define GRAPH_H

#include <cstddef>

struct Path {
public:
    size_t *v_sequence;
    size_t n;
};

class Graph {
public:
    Graph(size_t n_vertex);
    Graph(const Graph &old);
    Graph &operator = (const Graph &old);


    void AddEdge(size_t from, size_t to, size_t length);

    size_t ** GetMatrix() const;
    size_t * GetEdgesFrom(const size_t from) const;
    size_t GetSize() const;
    size_t GetLength(Path const &path) const;

    void PrintAdjMatrix() const;

    ~Graph();

private:
    size_t n_vertex;
    size_t ** adj_matrix;
};


#endif // GRAPH_H


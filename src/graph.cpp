#include <graph.h>
#include <iostream>

Graph::Graph(size_t n_vertex) : n_vertex(n_vertex) {

    adj_matrix = new size_t * [n_vertex];

    for (size_t i = 0; i < n_vertex; i++) {
        adj_matrix[i] = new size_t [n_vertex];

        for (size_t j = 0; j < n_vertex; j++) {
            adj_matrix[i][j] = 0;
        }
    }
}

Graph::Graph(const Graph &old): n_vertex(old.n_vertex) {
    adj_matrix = new size_t * [n_vertex];

    for (size_t i = 0; i < n_vertex; i++) {
        adj_matrix[i] = new size_t [n_vertex];

        for (size_t j = 0; j < n_vertex; j++) {
            adj_matrix[i][j] = old.adj_matrix[i][j];
        }
    }
}

Graph& Graph::operator=(const Graph &old) {
    n_vertex = old.GetSize();
    adj_matrix = new size_t * [n_vertex];

    for (size_t i = 0; i < n_vertex; i++) {
        adj_matrix[i] = new size_t [n_vertex];

        for (size_t j = 0; j < n_vertex; j++) {
            adj_matrix[i][j] = old.adj_matrix[i][j];
        }
    }
    return *this;
}

void Graph::AddEdge(size_t from, size_t to, size_t length) {
    adj_matrix[from][to] = length;
}

size_t *Graph::GetEdgesFrom(size_t from) const {
    return adj_matrix[from];
}

size_t **Graph::GetMatrix() const {
    return adj_matrix;
}

size_t Graph::GetSize() const {
    return n_vertex;
}

size_t Graph::GetLength(Path const &path) const {
    size_t length = 0;
    for (size_t i = 0; i < path.n - 1; i++) {
        length += adj_matrix[path.v_sequence[i]][path.v_sequence[i + 1]];
    }
    return length;
}

void Graph::PrintAdjMatrix() const {
    for (size_t i = 0; i < n_vertex; i++) {
        for (size_t j = 0; j < n_vertex; j++) {
            std::cout << adj_matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

Graph::~Graph() {
    for (size_t i = 0; i < n_vertex; i++) {
        delete [] adj_matrix[i];
    }

    delete [] adj_matrix;
    }


#include <tcp.h>

void TcpRec(const Graph &G, Path &path, Path &final_path, bool *unused, size_t idx) {

    static size_t length = 0;
    length = idx == 0 ? 0 : length;

    if (idx == G.GetSize()) {
        size_t path_length = G.GetLength(path);

        if (path_length >= length) {
            length = path_length;

            for (size_t i = 0; i < final_path.n; i++) {
                final_path.v_sequence[i] = path.v_sequence[i];
            }
        }
    }

    for (size_t i = 0; i < G.GetSize(); i++) {
        if (unused[i]) {
            unused[i] = false;
            path.v_sequence[i] = idx;
            TcpRec(G, path, final_path, unused, idx + 1);
            unused[i] = true;
        }
    }
}

Path Tcp(const Graph G) {
    bool *unused = new bool [G.GetSize()];

    for (size_t i = 0; i < G.GetSize(); i++) {
        unused[i] = true;
    }

    Path final_path;
    final_path.n = G.GetSize();
    final_path.v_sequence = new size_t [final_path.n];

    Path path;
    path.n = G.GetSize();
    path.v_sequence = new size_t[path.n];

    TcpRec(G, path, final_path, unused, 0);

    delete [] path.v_sequence;
    delete [] unused;

    return final_path;
}

std::string GetStringFromPath(const Graph &overlaps, const Path &path, std::string *strings) {

    std::list<std::string> str_list;
    for (size_t i = 0; i < path.n - 1; i++) {
        str_list.push_back(prefix(strings[path.v_sequence[i]],
                           overlaps.GetEdgesFrom(path.v_sequence[i])[path.v_sequence[i + 1]]));
    }
    str_list.push_back(strings[path.v_sequence[path.n - 1]]);

    return StringBuilder(str_list);
}


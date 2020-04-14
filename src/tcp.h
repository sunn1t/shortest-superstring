#ifndef TCP_H
#define TCP_H

#include <graph.h>
#include <common.h>
#include <string>
#include <cstddef>

Path Tcp(Graph G);

void TcpRec(Graph &G, Path &path, Path &final_path, bool *unused, size_t idx);

std::string GetStringFromPath(const Graph &overlaps, const Path &path, std::string *strings);

#endif // TCP_H


#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <common.h>
#include <graph.h>
#include <tcp.h>

#include <iostream>
#include <iterator>
#include <algorithm>

std::string AlgorithmBJLTY(size_t number_of_strings, std::string *strings);

size_t * assignment(size_t ** matrix, size_t size);

std::string ExactSolution(size_t number_of_strings, std::string *strings);

#endif // ALGORITHMS_H


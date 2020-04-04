#ifndef BJLTYALGORYTHM_H
#define BJLTYALGORYTHM_H

#include <iostream>
#include "graph.h"
#include <list>
#include <iterator>
#include <algorithm>

std::string AlgorithmBJLTY();

size_t Overlap(std::string s1, std::string s2);

size_t * Assignment(size_t ** matrix, size_t size);

std::string Prefix(std::string s1, size_t ov);

std::string StringBuilder(std::list<std::string> & superstrings);

#endif // BJLTYALGORYTHM_H

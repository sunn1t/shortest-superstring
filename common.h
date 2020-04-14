#ifndef COMMON_H
#define COMMON_H

#include <string>
#include <graph.h>
#include <list>

size_t overlap(std::string s1, std::string s2);

std::string prefix(std::string s1, size_t ov);

std::string StringBuilder(std::list<std::string> & superstrings);

Graph BuildOverlaps(size_t number_of_strings, std::string *strings);

#endif // COMMON_H


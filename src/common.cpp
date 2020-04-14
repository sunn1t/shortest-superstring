#include <common.h>

size_t overlap(const std::string &s1, const std::string &s2) {
    size_t s1_len = s1.length();
    size_t s2_len = s2.length();
    size_t overlap = 0;

    for (size_t i = s1_len - 1, j = 1; i > 0 && j < s2_len; i--, j++) {
        size_t k, l;
        for(k = i, l = 0; k < s1_len && l < j && s1[k] == s2[l]; k++, l++);
        overlap = j == l ? j : overlap;
    }
    return overlap;
}

std::string prefix(const std::string &s1, size_t ov) {
    return s1.substr(0, s1.length() - ov);
}

std::string StringBuilder(const std::list<std::string> & superstrings) {
    std::string string_result = "";
    std::list<std::string>::const_iterator it = superstrings.begin();
    for (; it != superstrings.end(); it++) {
        string_result += (*it);
    }
    return string_result;
}

Graph BuildOverlaps(size_t number_of_strings, std::string *strings) {
    Graph overlaps(number_of_strings);

    for (size_t i = 0; i < number_of_strings; i++) {
        for (size_t j = 0; j < number_of_strings; j++) {
            overlaps.AddEdge(i, j, overlap(strings[i], strings[j]));
        }
    }
    return overlaps;
}


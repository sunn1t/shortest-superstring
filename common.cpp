#include <common.h>
#include <iostream>

size_t overlap(std::string s1, std::string s2) {
    size_t s1_last = s1.length() - 1;
    size_t s2_len = s2.length();
    size_t overlap = 0;

//    std::cout << "Analasyed: " << s1 << ", " << s2 << std::endl;

    for (size_t i = s1_last, j = 1; i > 0 && j < s2_len; i--, j++) {
        std::string suff = s1.substr(i);
        std::string pref = s2.substr(0, j);
        if (suff == pref) {
            overlap = j;
        }
    }
    return overlap;
}

std::string prefix(std::string s1, size_t ov) {
    return s1.substr(0, s1.length() - ov);
}

std::string StringBuilder(std::list<std::string> & superstrings) {
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


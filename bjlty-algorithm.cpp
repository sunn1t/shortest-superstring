#include <bjlty-algorithm.h>

std::string AlgorithmBJLTY() {
    size_t number_of_strings;
    std::cin >> number_of_strings;

    std::string * strings = new std::string [number_of_strings];

    for (size_t i = 0; i < number_of_strings; i++) {
        std::cin >> strings[i];
    }

    Graph overlaps(number_of_strings);

    for (size_t i = 0; i < number_of_strings; i++) {
        for (size_t j = 0; j < number_of_strings; j++) {
            overlaps.AddEdge(i, j, Overlap(strings[i], strings[j]));
        }
    }

    size_t *assign = Assignment(overlaps.GetMatrix(), overlaps.GetSize());

    std::list<std::list<size_t>> cycles;
    std::list<std::size_t> cycle;
    bool *mark = new bool[number_of_strings];

    for (size_t i = 0; i < number_of_strings; i++) {
        mark[i] = false;
    }

    for (size_t i = 0; i < number_of_strings; i++) {
        if (!mark[i]) {
            cycle.push_back(i);
            mark[i] = true;

            if (assign[i] == cycle.front()) {
                cycles.push_back(cycle);
                cycle.clear();
                i = 0;
            } else {
                i = assign[i] - 1;
            }
        }
    }

    delete [] mark;
    delete [] assign;

    std::list<std::string> superstrings;
    std::list<std::list<size_t>>::iterator it;

    for (it = cycles.begin(); it != cycles.end(); it++) {
        std::string str = "";
        std::list<size_t> ovs;
        std::list<size_t>::iterator it1 = it->begin();
        std::list<size_t>::iterator it2 = it1;
        it2++;

        for (; it2 != it->end(); it1++, it2++) {
            ovs.push_back(overlaps.GetEdgesFrom(*it1)[*it2]);
        }

        size_t min = overlaps.GetEdgesFrom(*it1)[0];

        for (it1 = ovs.begin(), it2 = (*it).begin(); it1 != ovs.end(); it1++, it2++)
            if (*it1 < min) {
                min = *it1;
            }
        it2++;

        it1 = std::rotate((*it).begin(), it2, (*it).end());
        it2 = it1;
        it2++;

        for (; it2 != (*it).end(); it1++, it2++) {
            str += Prefix(strings[*it1], overlaps.GetEdgesFrom(*it1)[*it2]);
        }
        str += strings[*it1];
        superstrings.push_back(str);
    }

    delete [] strings;

    return StringBuilder(superstrings);
}

size_t Overlap(std::string s1, std::string s2) {
    size_t s1_last = s1.length() - 1;
    size_t s2_len = s2.length();
    size_t Overlap = 0;

    for (size_t i = s1_last, j = 1; i > 0 && j < s2_len; i--, j++) {
        std::string suff = s1.substr(i);
        std::string pref = s2.substr(0, j);
        if (suff == pref) {
            Overlap = j;
        }
    }
    return Overlap;
}

size_t * Assignment(size_t **matrix, size_t size) {
    bool **not_allow = new bool*[size];
    size_t *assign = new size_t[size];

    for (size_t i = 0; i < size; i++) {

        not_allow[i] = new bool[size];

        for (size_t j = 0; j < size; j++) {
            not_allow[i][j] = false;
        }
    }

    long max;
    size_t max_i, max_j;

    do {
        max = -1;
        max_i = max_j = 0;

        for (size_t i = 0; i < size; i++) {
            for (size_t j = 0; j < size; j++) {
                if (!not_allow[i][j] && static_cast<long>(matrix[i][j]) > max) {
                    max = static_cast<long>(matrix[i][j]);
                    max_i = i;
                    max_j = j;
                }
            }
        }

        if (max != -1) {
            assign[max_i] = max_j;

            for (size_t i = 0; i < size; i++) {
                not_allow[max_i][i] = not_allow[i][max_j] = true;
            }
        }
    } while (max != -1);

    for (size_t i = 0; i < size; i++) {
        delete [] not_allow[i];
    }
    delete [] not_allow;

    return assign;
}


std::string Prefix(std::string s1, size_t ov) {
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

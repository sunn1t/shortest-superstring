#include <algorithms.h>

std::string AlgorithmBJLTY(size_t number_of_strings, std::string *strings) {

    Graph overlaps = BuildOverlaps(number_of_strings, strings);

    size_t *assign = assignment(overlaps.GetMatrix(), overlaps.GetSize());

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
            str += prefix(strings[*it1], overlaps.GetEdgesFrom(*it1)[*it2]);
        }
        str += strings[*it1];
        superstrings.push_back(str);
    }

    return StringBuilder(superstrings);
}


size_t * assignment(size_t **matrix, size_t size) {
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


std::string ExactSolution(size_t number_of_strings, std::string *strings) {
    Graph overlaps = BuildOverlaps(number_of_strings, strings);
    Path path = Tcp(overlaps);
    std::string result = GetStringFromPath(overlaps, path, strings);
    delete [] path.v_sequence;
    return result;
}


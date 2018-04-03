#ifndef TRAVELINGSALESMANCPP_HAMILTONIANPATH_H
#define TRAVELINGSALESMANCPP_HAMILTONIANPATH_H

#include "City.h"
#include <algorithm>

namespace ts {
class HamiltonianPath {
    vector<City> GetUsingBruteforce(vector<City> cities, int startIndex);
    vector<City> GetUsingNearestNeighbour(vector<City> cities, int startIndex);
};

}


#endif //TRAVELINGSALESMANCPP_HAMILTONIANPATH_H

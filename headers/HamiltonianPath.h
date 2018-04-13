#ifndef TRAVELINGSALESMANCPP_HAMILTONIANPATH_H
#define TRAVELINGSALESMANCPP_HAMILTONIANPATH_H

#include "City.h"
#include <vector>

namespace ts {
    class HamiltonianPath {
    public:
        void GetUsingBruteforce(vector<City> cities, int startIndex, int i = 1);

        vector<City> GetBruteforceResult();

        vector<City> GetUsingGreedy(vector<City> cities, int startIndex);

        vector<City> GetUsingGraph(vector<City> cities, int startIndex);
    };
}


#endif //TRAVELINGSALESMANCPP_HAMILTONIANPATH_H

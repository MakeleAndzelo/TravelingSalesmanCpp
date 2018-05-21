#include <vector>
#include "../headers/City.h"

#ifndef TRAVELINGSALESMANCPP_CITYSEED_H
#define TRAVELINGSALESMANCPP_CITYSEED_H

namespace ts {
    class CitySeed {
    public:
        vector<City> SeedData(int count);
        vector<int[]> SeedNeighborhood(int count, int maxNeighbors);
    };
}

#endif //TRAVELINGSALESMANCPP_CITYSEED_H
